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

  void test_POP_pop_expect_0x0006(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   PoP  ";
  	IdentifierToken popToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"POP"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//

  	Try {
  		pop(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_POF_pof_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   poF    ";
  	IdentifierToken popToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"POF"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//

  	Try {
  		pop(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_POP_pop_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   PoP      ";
  	IdentifierToken popToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"POP"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//
  	Try {
   		pop(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
