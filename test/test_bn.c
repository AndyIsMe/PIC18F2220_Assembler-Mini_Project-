#include "unity.h"
#include "AssemblyCode.h"
#include "checkregister.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"

void setUp(void)
{}

void tearDown(void)
{}

  void test_BN_bn_0x37_expect_0xe61a(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bN   0x37  ";
  	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BN"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = bn(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_BN_bd_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   Bd    ";
  	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BD"};


  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//

  	Try {
  		bn(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BN_bn_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bN      ";
  	IdentifierToken bnToken = {TOKEN_OPERATOR_TYPE, 3,2,instr,"BN"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
  	Try {
   		bn(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BN_bn_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bN   0x37  ";
  	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BN"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		bn(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BN_bn_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bN   0xff1  ";
  	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BN"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		bn(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
