#include "unity.h"
#include "tblwt_star+.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_TBLWT_STAR_PLUS_tblwt_star_plus_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblwt_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblwt"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*+"};

	initTokenizer_ExpectAndReturn("   tblwt*+  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star_plus("   tblwt*+  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
