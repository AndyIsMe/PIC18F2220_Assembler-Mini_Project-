#include "unity.h"
#include "setf.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"

void setUp(void){}
void tearDown(void){}


void test_SETF_setf_0x37_coma_ACCESS_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   setf   0x37,ACCESS  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 14,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 15,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = setf(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}

void test_SETF_setf_0x37_coma_BANKED_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   setf   0x37,BANKED  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = setf(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}