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

  void test_XORLW_xorlw_0x37_expect_0x0a37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   xOrLw   0x37  ";
  	IdentifierToken xorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		xorlw(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_XORLW_xorwl_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   XoRwl    ";
  	IdentifierToken xorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWL"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//

  	Try {
  		xorlw(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_XORLW_xorlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   xorlw      ";
  	IdentifierToken xorlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"XORLW"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//
  	Try {
   		xorlw(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
