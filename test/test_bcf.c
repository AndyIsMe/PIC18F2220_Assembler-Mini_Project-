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

  void test_BCF_bcf_0x37_4_ACCESS_expect_0x9837(void){
    CEXCEPTION_T ex;
    int machineCode;
    //OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,4,ACCESS  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"ACCESS"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcf_0x37_4_0_expect_0x9837(void){
    CEXCEPTION_T ex;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,4,0  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcf_0x37_4_BANKED_expect_0x9937(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,4,BANKED  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"BANKED"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcf_0x37_4_1_expect_0x9937(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,4,1  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcf_0x37_8_1_expect_0x9137(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,8,1  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"8",8};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcf_0x37_9_1_expect_0x9337(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,9,1  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"9",9};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcf_0x37_10_1_expect_0x9137(void){
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    int machineCode;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf   0x37,10,1  ";
    IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,2,instr,"10",10};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
    Try {
      machineCode = bcf(instr);
  		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BCF_bcd_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   BcD    ";
  	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BCD"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//

  	Try {
  		bcf(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BCF_bcf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bCf      ";
  	IdentifierToken bcfToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BCF"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
  	Try {
   		bcf(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BCF_bcf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bCf  0x37  ";
  	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BCF"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		bcf(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BCF_bcf_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
  	int machineCode;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bCf  0xff1  ";
  	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BCF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		bcf(instr);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
