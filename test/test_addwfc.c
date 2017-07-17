#include "unity.h"
#include "addwfc.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"

void setUp(void){}
void tearDown(void){}


void test_ADDWFC_addwfc_0x37_coma_WREG_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aDdWfC   0x37,WREG,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 17,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 21,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 22,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_ADDWFC_addwfc_0x37_coma_WREG_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aDdWfc   0x37,WREG,BANKED  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 17,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 21,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 22,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_ADDWFC_addwfc_0x37_coma_f_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   addWfC   0x37,F,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 17,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 18,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 19,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_ADDWFC_addwfc_0x37_coma_f_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   addWfC   0x37,f,BANKED  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 17,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 18,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 19,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
