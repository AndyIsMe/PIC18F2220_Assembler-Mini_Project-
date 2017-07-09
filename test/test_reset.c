#include "unity.h"
#include "reset.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_RESET__reset_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken resetToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"reset"};


	initTokenizer_ExpectAndReturn("   reset  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//


	Try {
		machineCode = reset("   reset  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
