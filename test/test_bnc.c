#include "unity.h"
#include "bnc.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_BNC_bnc_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bnc"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bnc   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnc("   bnc   0x37  ");
    printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
