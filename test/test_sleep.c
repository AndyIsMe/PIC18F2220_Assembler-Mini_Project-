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

  void test_SLEEP_sleep_expect_exception(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   SLEEP  ";
  	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SLEEP"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//

  	Try {
  		machineCode = sleep(instr);
  		printf("\nthe instruction opcode is %#4x",machineCode);
  	}Catch(ex) {
  	dumpErrorMessage(ex, 1);
  	}
  }
  void test_SLEEP_slepe_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   SlEpe    ";
  	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SLEPE"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//

  	Try {
  		sleep(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_SLEEP_sleep_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   SlEep      ";
  	IdentifierToken sleepToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"SLEEP"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//
  	Try {
   		sleep(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
