#include "unity.h"
#include "comf.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_COMF_comf_0x37_coma_WREG_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"comf"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 15,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 19,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 20,6,"ACCESS"};

	initTokenizer_ExpectAndReturn("   comf   0x37,WREG,ACCESS  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = comf("   comf   0x37,WREG,ACCESS  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_COMF_comf_0x37_coma_WREG_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"comf"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 15,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 19,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 20,6,"BANKED"};

	initTokenizer_ExpectAndReturn("   comf   0x37,WREG,BANKED  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = comf("   comf   0x37,WREG,BANKED  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_COMF_comf_0x37_coma_f_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"comf"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 15,1,"f"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"ACCESS"};

	initTokenizer_ExpectAndReturn("   comf   0x37,f,ACCESS  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = comf("   comf   0x37,f,ACCESS  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_COMF_comf_0x37_coma_f_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"comf"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 15,1,"f"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"BANKED"};

	initTokenizer_ExpectAndReturn("   comf   0x37,f,BANKED  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = comf("   comf   0x37,f,BANKED  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}