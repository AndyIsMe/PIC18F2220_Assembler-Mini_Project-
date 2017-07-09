#include "unity.h"
#include "tblrd_star.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_TBLRD_STAR_tblrd_star_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblrd"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,"*"};

	initTokenizer_ExpectAndReturn("   tblrd*  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star("   tblrd*  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
