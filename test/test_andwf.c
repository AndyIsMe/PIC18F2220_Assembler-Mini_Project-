#include "unity.h"
#include "andwf.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"

void setUp(void){}
void tearDown(void){}


void test_ANDWF_andwf_0x37_coma_WREG_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   AnDwF   0x37,WREG,ACCESS  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = andwf(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_ANDWF_andwf_0x37_coma_WREG_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   andwf   0x37,WREG,BANKED  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = andwf(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_ANDWF_andwf_0x37_coma_f_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   andwf   0x37,F,ACCESS  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = andwf(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_ANDWF_andwf_0x37_coma_f_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   andwf   0x37,F,BANKED  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = andwf(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
