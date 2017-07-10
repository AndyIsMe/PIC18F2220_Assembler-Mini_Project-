#include "unity.h"
#include "bc.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_BC_bc_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bc"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bc   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bc("   bc   0x37  ");
    printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_BN_bn_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode1;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bn"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bn   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode1 = bn("   bn   0x37  ");
		printf("the instruction opcode is %#4x",machineCode1);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_BNC_bnc_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode2;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bnc"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bnc   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode2 = bnc("   bnc   0x37  ");
    printf("the instruction opcode is %#4x",machineCode2);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_BNN_bnn_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode3;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bnn"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bnn   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode3 = bnn("   bnn   0x37  ");
    printf("the instruction opcode is %#4x",machineCode3);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_BNOV_bnov_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode4;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bnov"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bnov   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode4 = bnov("   bnov   0x37  ");
		printf("the instruction opcode is %#4x",machineCode4);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}


void test_BNZ_bnz_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode5;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bnz"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bnz   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode5 = bnz("   bnz   0x37  ");
		printf("the instruction opcode is %#4x",machineCode5);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_BOV_bov_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode6;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bov"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bov   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode6 = bov("   bov   0x37  ");
		printf("the instruction opcode is %#4x",machineCode6);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_BZ_bz_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode7;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"bz"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   bz   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode7 = bz("   bz   0x37  ");
		printf("the instruction opcode is %#4x",machineCode7);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
