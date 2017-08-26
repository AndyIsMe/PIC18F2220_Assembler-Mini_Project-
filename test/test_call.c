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

  void test_CALL_call_0xbff_coma_0_expect_0xecfff005(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   cAlL   0xbff,0  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xbff",0xbff};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,15,1,instr,","};
  	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,16,1,instr,"0",0};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

  	Try {
  		call(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[4],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x%02x%02x",instr,flash[0],flash[1],flash[2],flash[3]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CALL_call_0xbff_coma_1_expect_0xedfff005(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   cAlL   0xbff,1  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xbff",0xbff};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,15,1,instr,","};
  	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,16,1,instr,"1",1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

  	Try {
  		call(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[4],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x%02x%02x",instr,flash[0],flash[1],flash[2],flash[3]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CALL_call_0xfe_coma_1_expect_0xed7ff000(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   cAlL   0xfe,1  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xfe",0xfe};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,14,1,instr,","};
  	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,15,1,instr,"1",1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

  	Try {
  		call(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[4],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x%02x%02x",instr,flash[0],flash[1],flash[2],flash[3]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CALL_call_0xf_coma_1_expect_0xed07f000(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   cAlL   0xf,1  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xf",0xf};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
  	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,14,1,instr,"1",1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

  	Try {
  		call(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[4],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x%02x%02x",instr,flash[0],flash[1],flash[2],flash[3]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CALL_call_0x0_coma_1_expect_0xed00f000(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   cAlL   0x0,1  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x0",0x0};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
  	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,14,1,instr,"1",1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

  	Try {
  		call(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[4],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x%02x%02x",instr,flash[0],flash[1],flash[2],flash[3]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CALL_calr_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   CaLr    ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALR"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//

  	Try {
  		call(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[4],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x%02x%02x",instr,flash[0],flash[1],flash[2],flash[3]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CALL_call_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   cAlL      ";
  	IdentifierToken callToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"CALL"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	Try {
   		call(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CALL_call_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   CalL  0x37  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,9,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		call(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CALL_call_0x37_fullstop_expect_INVALID_OPERATOR_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   caLl  0x37.      ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,"."};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	Try {
   		call(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CALL_call_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   CalL  0x37,  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,13,1,instr,","};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	Try {
  		call(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CALL_call_0x37_coma_1_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   CalL  0x37,  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
  	IntegerToken int1Token = {TOKEN_OPERATOR_TYPE,14,1,instr,"1",1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);//
  	Try {
  		call(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CALL_call_0xfff1_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  	char instr[] = "   cAlL  0xff1  ";
  	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,6,instr,"0xff1",0xfff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	Try {
  		call(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
