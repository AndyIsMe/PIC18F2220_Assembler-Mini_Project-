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

  void test_SUBLW_sublw_0x37_expect_0x0837(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   SuBLw   0x37  ";
  	IdentifierToken sublwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBLW"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = sublw(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_SUBLW_subwl_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   SuBwl    ";
  	IdentifierToken sublwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWL"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//

  	Try {
  		sublw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_SUBLW_sublw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   SuBlW      ";
  	IdentifierToken sublwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"SUBLW"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//
  	Try {
   		sublw(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
