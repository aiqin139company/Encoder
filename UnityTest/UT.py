import os
import os.path
import sys
import serial
import re
import ctypes
import shutil

#about cmd print color
STD_INPUT_HANDLE = -10
STD_OUTPUT_HANDLE = -11
STD_ERROR_HANDLE = -12
RED = 0x0c 
GREEN = 0x0a 
DARKWHITE = 0x07

# get handle
std_out_handle = ctypes.windll.kernel32.GetStdHandle(STD_OUTPUT_HANDLE)
 
def set_cmd_text_color(color, handle=std_out_handle):
    Bool = ctypes.windll.kernel32.SetConsoleTextAttribute(handle, color)
    return Bool

#red
def printRed(str):
    set_cmd_text_color(RED)
    print str
    set_cmd_text_color(DARKWHITE)

#green
def printGreen(str):
    set_cmd_text_color(GREEN)
    print str
    set_cmd_text_color(DARKWHITE)
	
#create UT_Conf.h file
def CreateConfFile(filename):
	confFile = open('.\Test\UT_Conf.h','w')
	confFile.write('#define	' + filename.upper()[:-4] + '\r\n')
	confFile.close()	
	
#running Keil to building and running unity test
def StartUnityTest(filename):
	print filename
	os.system('C:\Keil_v5\Uv4\UV4.exe -j0 -b ..\Project\RADIX.uvprojx')
	if os.path.exists(r'..\Debug\RADIX.axf'):
		os.system('C:\Keil_v5\Uv4\UV4.exe -j0 -f ..\Project\RADIX.uvprojx')	
		return True
	else:
		printRed("Compile project failed!")
		return False
	
#received information from target by using serial 
def CreateLogFile(filename):
	if False == os.path.exists(r'.\Log'):
		os.makedirs('.\Log')
	logFilePath = '.\Log\\' + filename[:-4] + '.log'
	logFile = open(logFilePath,'w')	
	loop = True	
	loopIndex = 0;
	while loop :
		buf = ser.read(1)
		if 0 != ser.inWaiting():
			if '*' == buf:
				loopIndex += 1;
			else:
				loopIndex = 0;
		else:
			if loopIndex >= 20:
				loop = False
				buf = '\n'	
		logFile.write(buf)
	logFile.close()		

#deal with the information and show the result
def PasrerLogFile(filename):
	invalid = True
	logFilePath = '.\Log\\' + filename[:-4] + '.log'
	logFile = open(logFilePath,'r')
	teststring = logFile.read()
	fail_pattern = r"^------------------------------\n[0-9]+\sTests\s[0-9]+\sFailures\s[0-9]+\sIgnored\s\nFAIL"
	pass_pattern = r"^------------------------------\n[0-9]+\sTests\s[0-9]+\sFailures\s[0-9]+\sIgnored\s\nOK"
	if re.search(fail_pattern, teststring, flags=re.MULTILINE):
		printRed("FAIL")
		invalid =  False
	elif re.search(pass_pattern, teststring, flags=re.MULTILINE):
		printGreen("PASS")
		invalid = True
	else:
		printRed("ERROR")
		invalid = False
	logFile.close()		
	return invalid
	
#show Sunmary	
def Summary(all,true,false):
	sunmary = "---------------Sunmary-----------------\r\n"
	sunmary += "%d Tests | %d Successful | %d Failures" %(all,true,false)
	if 0 != false:
		printRed(sunmary)
		printRed("FAIL")
	elif all == true:
		printGreen(sunmary)
		printGreen("OK")
	else:
		printRed(sunmary)
		printRed("ERROR")
	
	
#####################################################################
#						START RUNNING SCRIPT						#
#																	#
#####################################################################
		
#judgement
argc = len(sys.argv)
if argc < 2:
	print 'Invalid usage, format is: ' 
	print '\t %s "COMx" [FILENAME]' % (sys.argv[0])
	sys.exit()
else:
	portName = sys.argv[1]
	
#open serical	
ser = serial.Serial()
ser.port = portName
ser.baudrate = 230400
ser.timeout = 2

try:
	print "Opening serial port: " + portName
	ser.open()
except:
	print "Count not open serial port: " +portName
	sys.exit()

if True == os.path.exists(r'.\Log'):
	shutil.rmtree(r'.\Log')
	
if 2 == argc:
	
	AllCnt = 0;
	FalseCnt = 0;
	TrueCnt = 0;

	dir = ".\Test"
	for parentdir,dirname,filenames in os.walk(dir):  
		for filename in filenames: 
		
			if os.path.splitext(filename)[1]=='.cpp':  
				AllCnt = AllCnt + 1;
				CreateConfFile(filename)
				
				if StartUnityTest(filename):
					CreateLogFile(filename)
					
					if PasrerLogFile(filename):
						TrueCnt = TrueCnt + 1;
					else:
						FalseCnt = FalseCnt + 1;
						
				else:
					FalseCnt = FalseCnt + 1;
					break
					
	Summary(AllCnt,TrueCnt,FalseCnt)
	
else:
	
	filename = sys.argv[2]
	if os.path.exists(r'.\Test\\' + filename):
		CreateConfFile(filename)
		if StartUnityTest(filename):
			CreateLogFile(filename)
			PasrerLogFile(filename)
	else:
		printRed("Not such file!")		

ser.close()

