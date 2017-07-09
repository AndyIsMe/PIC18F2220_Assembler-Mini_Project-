#include "unity.h"
#include "sleep.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_SLEEP__sleep_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"sleep"};


	initTokenizer_ExpectAndReturn("   sleep  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//


	Try {
		machineCode = sleep("   sleep  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
