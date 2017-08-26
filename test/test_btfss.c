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

  void test_BTFSS_btfss_0x37_4_ACCESS_expect_0xa837(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTfsS   0x37,6,ACCESS  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfss_0x37_4_0_expect_0xa837(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTfsS   0x37,6,0  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfss_0x37_4_BANKED_expect_0xa937(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSS   0x37,4,BANKED  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfss_0x37_4_1_expect_0xa937(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSS   0x37,4,1  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfss_0x37_8_1_expect_0xa137(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSS   0x37,8,1  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"8",8};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfss_0x37_9_1_expect_0xa337(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSS   0x37,9,1  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"9",9};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfss_0x37_10_1_expect_0xa137(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btfSS   0x37,10,1  ";
    IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,2,instr,"10",10};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 18,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 19,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btfss(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTFSS_btfse_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   BtFSe    ";
  	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSE"};


  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//

  	Try {
  		btfss(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTFSS_btfss_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTfsS      ";
  	IdentifierToken btfssToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"BTFSS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
  	Try {
   		btfss(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTFSS_btfss_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bTfsS  0x37  ";
  	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSS"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,10,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		btfss(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTFSS_btfss_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bTfsS  0xff1  ";
  	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSS"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		btfss(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
