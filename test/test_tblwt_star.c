#include "unity.h"
#include "tblwt_star.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_TBWLT_STAR_tbwlt_star_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblwt_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblwt"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,"*"};

	initTokenizer_ExpectAndReturn("   tblwt*  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star("   tblwt*  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_TBLWT_STAR_PLUS_tblwt_star_plus_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode1;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblwt_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblwt"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*+"};

	initTokenizer_ExpectAndReturn("   tblwt*+  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode1 = tblwt_star_plus("   tblwt*+  ");
		printf("the instruction opcode is %#4x",machineCode1);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_TBLWT_STAR_MINUS_tblwt_star_minus_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode2;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblwt_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblwt"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*-"};

	initTokenizer_ExpectAndReturn("   tblwt*-  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode2 = tblwt_star_minus("   tblwt*-  ");
		printf("the instruction opcode is %#4x",machineCode2);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_TBLWT_PLUS_STAR_tblwt_plus_star_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode3;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblwt_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblwt"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"+*"};

	initTokenizer_ExpectAndReturn("   tblwt+*  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_plus_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode3 = tblwt_plus_star("   tblwt+*  ");
		printf("the instruction opcode is %#4x",machineCode3);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
