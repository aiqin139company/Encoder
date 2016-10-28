#ifdef UT_TEST
#include "UT_Test.h"

#ifdef UT_MSGMANAGER
#include "MsgManager.h"

MsgManager msg;

void setUp(void)
{
	msg.Initialize();
}


void tearDown(void)
{

}

void TestTxMessage(void)
{
	u8 buff[] = {0x00,0x01,0x02,0x03,0x00,0x05,0x06,0x00,0x08,0x09};
	u8 expected[] = {0x02,0x01,0x04,0x01,0x02,0x03,0x03,0x05,0x06,0x04,0x08,0x09,0xff,0x00}; 
	msg.TxMessage(1,buff,sizeof(buff));
	msg.TxMessage(1,buff,sizeof(buff));

	TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, msg.txMsgBuff,sizeof(expected));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, msg.txMsgBuff+sizeof(expected),sizeof(expected));
}

void TestProcessTxData(void)
{
	msg.ProcessTxData();
	
}

int main(void)
{
	Uart_Init(230400);
	UNITY_BEGIN();

	RUN_TEST(TestTxMessage);
//	RUN_TEST(TestProcessTxData);
		
	UNITY_END();
	while(1) {}
}

#endif
#endif
