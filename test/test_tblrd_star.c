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

void test_TBLRD_STAR_PLUS_tblrd_star_plus_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode1;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblrd_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblrd"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*+"};

	initTokenizer_ExpectAndReturn("   tblrd*+  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode1 = tblrd_star_plus("   tblrd*+  ");
		printf("the instruction opcode is %#4x",machineCode1);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_TBLRD_STAR_MINUS_tblrd_star_minus_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode2;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblrd_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblrd"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*-"};

	initTokenizer_ExpectAndReturn("   tblrd*-  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode2 = tblrd_star_minus("   tblrd*-  ");
		printf("the instruction opcode is %#4x",machineCode2);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_TBLRD_PLUS_STAR_tblrd_plus_star_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode3;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken tblrd_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"tblrd"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"+*"};

	initTokenizer_ExpectAndReturn("   tblrd+*  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_plus_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode3 = tblrd_plus_star("   tblrd+*  ");
		printf("the instruction opcode is %#4x",machineCode3);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
