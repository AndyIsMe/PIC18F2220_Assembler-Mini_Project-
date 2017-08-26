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

  void test_BTG_btg_0x37_4_ACCESS_expect_0x7837(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,4,ACCESS  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"ACCESS"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btg_0x37_4_0_expect_0x7837(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,4,0  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btg_0x37_4_BANKED_expect_0x7937(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,4,BANKED  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"BANKED"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btg_0x37_4_1_expect_0x7937(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,4,1  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btg_0x37_8_1_expect_0x7137(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,8,1  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"8",8};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btg_0x37_9_1_expect_0x7337(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,9,1  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"9",9};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btg_0x37_10_1_expect_0x7137(void){
    CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   btG   0x37,10,1  ";
    IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
    IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,2,instr,"10",10};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

    initTokenizer_ExpectAndReturn(instr,tokenizer);
    getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

    Try {
      btg(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
  }
  void test_BTG_btt_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   Btt    ";
  	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BTT"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//

  	Try {
  		btg(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  }
  void test_BTG_btg_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   bTg      ";
  	IdentifierToken btgToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BTG"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  	Try {
   		btg(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTG_btg_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bTg  0x37  ";
  	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BTG"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		btg(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_BTG_btg_0xff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   bTg  0xff1  ";
  	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BTG"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		btg(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
