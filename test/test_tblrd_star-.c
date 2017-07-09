#include "unity.h"
#include "tblrd_star-.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_TBLRD_STAR_MINUS_tblrd_star_minus_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblrd_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblrd"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*-"};

	initTokenizer_ExpectAndReturn("   tblrd*-  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star_minus("   tblrd*-  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
