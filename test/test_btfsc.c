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

  void test_BTFSC_btfsc_0x37_4_ACCESS_expect_0xb837(void){
    CEXCEPTION_T ex;
    int machineCode;
    //OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTfsc   0x37,6,ACCESS  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_btfsc_0x37_4_0_expect_0xb837(void){
    CEXCEPTION_T ex;
    int machineCode;
    //OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTfsc   0x37,4,0  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_bsfsc_0x37_4_BANKED_expect_0xb937(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSC   0x37,4,BANKED  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_bsfsc_0x37_4_1_expect_0xb937(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSC   0x37,4,1  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_bsfsc_0x37_8_1_expect_0xb137(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSC   0x37,8,1  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"8",8};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_bsfsc_0x37_9_1_expect_0xb337(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSC   0x37,9,1  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"9",9};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_bsfsc_0x37_10_1_expect_0xb137(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSC   0x37,10,1  ";
    IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,2,instr,"10",10};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 18,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 19,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = btfsc(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSC_brbbf_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   BrbbF    ";
  	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BRBBF"};


  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
  	Try {
  		btfsc(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTFSC_btfsc_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTfsC      ";
  	IdentifierToken btfscToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"BTFSC"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
  	Try {
   		btfsc(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTFSC_btfsc_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bTfsC  0x37  ";
  	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSC"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,10,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		btfsc(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTFSC_btfsc_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bTfsC  0xff1  ";
  	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSC"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		btfsc(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
