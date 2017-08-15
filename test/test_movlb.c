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

  void test_MOVLB_movlb_0x9_expect_0x0109(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   MoVLb   0x9  ";
  	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVLB"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,instr,"0x9",0x9};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = movlb(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_MOVLB_movlb_0xff_expect_0x010f(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   MoVLb   0xf9  ";
  	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVLB"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,instr,"0xf9",0xf9};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = movlb(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_MOVLB_mvole_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   mVoLe    ";
  	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MVOLE"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//

  	Try {
  		movlb(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_MOVLB_movlb_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   moVlB      ";
  	IdentifierToken movlbToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MOVLB"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
  	Try {
   		movlb(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
