#include "unity.h"
#include "push.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_PUSH__push_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"push"};


	initTokenizer_ExpectAndReturn("   push  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//


	Try {
		machineCode = push("   push  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
