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

  void test_ANDLW_addlw_0x37_expect_0xf37(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   aNdLw   0x37  ";
  	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = andlw(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDLW_anddw_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   ANDwW    ";
  	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWW"};


  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//

  	Try {
  		andlw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);

  	}
  	freeException(ex);
  }
  void test_ANDLW_andlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDlW       ";
  	IdentifierToken andlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ANDLW"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
  	Try {
   		andlw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);

  	}
  	freeException(ex);
  }
  void test_ANDLW_andlw_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   aNdLw   0x37  ";
  	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDLW"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		andlw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDLW_andlw_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   aNdLw   0xff1  ";
  	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		andlw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
