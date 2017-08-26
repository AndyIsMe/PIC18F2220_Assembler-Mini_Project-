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
  void test_PUSH_push_expect_0x0005(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   PUSH  ";
  	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"PUSH"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//

  	Try {
  		push(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_PUSH_puhs_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   pUhS    ";
  	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"PUHS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//

  	Try {
  		push(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  	freeException(ex);
  }
  void test_PUSH_push_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   pUsH      ";
  	IdentifierToken pushToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"PUSH"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//
  	Try {
   		push(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  	freeException(ex);
  }
