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

  void test_CPFSLT_cpfslt_0x37_coma_ACCESS_expect_0x6037(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   cPFsLt   0x37,ACCESS  ";
  	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSLT"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		cpfslt(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CPFSLT_cpfslt_0x37_coma_0_expect_0x6037(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   cPFsGLt   0x37,ACCESS  ";
  	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSLT"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"0"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		cpfslt(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CPFSLT_cpfslt_0x37_coma_BANKED_expect_0x6137(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   cPfSLt   0x37,BANKED  ";
  	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSLT"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		cpfslt(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CPFSLT_cpfslt_0x37_coma_1_expect_0x6137(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   cPfSLt   0x37,1  ";
  	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSLT"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		cpfslt(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_CPFSLT_cpfsle_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   CpFSLe    ";
  	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSLE"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//

  	Try {
  		cpfslt(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_CPFSLT_cpfslt_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   cpFsLt      ";
  	IdentifierToken cpfsltToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"CPFSLT"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
  	Try {
   		cpfslt(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
