#ifdef UT_TEST
#include "UT_Test.h"

#ifdef UT_PARAMMANAGER
#include "ParamManager.h"

void setUp(void)
{

}


void tearDown(void)
{

}


void test(void)
{
	char *test = {0};
	TEST_ASSERT_NULL(test);
}


int main(void)
{
	Uart_Init(230400);
	UNITY_BEGIN();
	
	RUN_TEST(test);
	
	UNITY_END();
	while(1){}
}

#endif
#endif

