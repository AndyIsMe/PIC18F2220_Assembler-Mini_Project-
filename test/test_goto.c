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


  void test_GOTO_goto_0xbff_expect_0xeffff005(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   goTO   0xbff  ";
  	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xbff",0xbff};


  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//


  	Try {
  		machineCode = _goto(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_GOTO_goto_0xfe_expect_0xef7ff000(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   goTO   0xfe  ";
  	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xfe",0xfe};


  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = _goto(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_GOTO_goto_0xf_expect_0xef07f000(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   goTO   0xf  ";
  	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xf",0xf};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = _goto(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_GOTO_goto_0x0_expect_0xef00f000(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   goTO   0x0  ";
  	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x0",0x0};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		machineCode = _goto(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_GOTO_gotd_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   gOtD    ";
  	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTD"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//

  	Try {
  		machineCode = _goto(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_GOTO_goto_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   GoTo      ";
  	IdentifierToken gotoToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"GOTO"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
  	Try {
   		_goto(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
