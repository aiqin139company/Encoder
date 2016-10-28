#ifdef UT_TEST
#include "UT_Test.h"

#ifdef UT_FAULTMANAGER
#include "FaultManager.h"

FaultManager fault;
ParamManager sys;

void setUp(void)
{
	fault.Initialize(&sys);
}


void tearDown(void)
{

}


void test_pointer(void)
{
	char *test = {0};
	TEST_ASSERT_NULL(test);
}


void test_float()
{
	float expected = 20.012;
	float actual = 20.011;
	TEST_ASSERT_EQUAL_FLOAT(expected, actual);
}


void test_float_within(void)
{
	float expected = 20.012;
	float actual = 20.019;
	
	TEST_ASSERT_FLOAT_WITHIN(0.02, expected, actual);

}

int main(void)
{
	Uart_Init(230400);
	UNITY_BEGIN();
	
	RUN_TEST(test_pointer);
	RUN_TEST(test_float);
	RUN_TEST(test_float_within);
	
	UNITY_END();
	while(1){}
}

#endif
#endif
