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

  void test_ADDLW_addlw_0x37_expect_0x0f37(void){
  	CEXCEPTION_T ex;
  	uint8_t flash[4] = {0,0,0,0};
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *memory = flash;
  	char instr[] = "   aDdLw   0x37  ";
  	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		addlw(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ADDLW_addmw_expect_NOT_VALID_IDENTIFIER_(void){
  	CEXCEPTION_T ex;
  	uint8_t flash[4] = {0,0,0,0};
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *memory = flash;
    char instr[] = "   AdDlW    ";
  	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDvF"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
  	Try {
   		addlw(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ADDLW_addlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AdDlW       ";
  	IdentifierToken addlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ADDLW"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
  	Try {
   		addlw(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ADDLW_addlw_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   aDdLw   0x37  ";
  	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDLW"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		addlw(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ADDLW_addlw_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   aDdLw   0xff1  ";
  	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		addlw(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
