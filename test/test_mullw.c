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

  void test_MULLW_mullw_0x37_expect_0x0d37(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   mUlLw   0x37  ";
  	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = mullw(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_MULLW_mulld_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   mulLD    ";
  	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULLD"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//

  	Try {
  		mullw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_MULLW_mullw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   mUllW      ";
  	IdentifierToken mullwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MULLW"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//
  	Try {
   		mullw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
