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

  void test_DCFSNZ_dcfsnz_0x37_coma_0_coma_ACCESS_expect_0x4c37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsnZ  0x37,0,ACCESS  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcfsnz_0x37_coma_WREG_coma_ACCESS_expect_0x4c37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsnZ  0x37,WREG,ACCESS  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcfsnz_0x37_coma_WREG_coma_BANKED_expect_0x4d37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsNz  0x37,WREG,BANKED  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcfsnz_0x37_coma_F_coma_ACCESS_expect_0x4e37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsNz  0x37,F,ACCESS  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcfsnz_0x37_coma_F_coma_BANKED_expect_0x4f37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsnZ  0x37,F,BANKED  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcfsnz_0x37_coma_F_coma_1_expect_0x4f37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsnZ  0x37,F,1  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcfsnz_0x37_coma_1_coma_1_expect_0x4f37(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   dcFsnZ  0x37,1,1  ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCFSNZ"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		dcfsnz(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
      printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_DCFSNZ_dcdsnz_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   DCdsnZ    ";
  	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCDSNZ"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//

  	Try {
  		dcfsnz(instr,&memory);

  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_DCFSNZ_dcfsnz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
    char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   DCFsnZ      ";
  	IdentifierToken dcfsnzToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"DCFSNZ"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
  	Try {
   		dcfsnz(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
