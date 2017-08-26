#include "unity.h"
#include "AssemblyCode.h"
#include "checkregister.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"
#define M (1024*1024)
char flash[2*M];
void setUp(void)
{}

void tearDown(void)
{}

  void test_ANDWF_andwf_0x37_coma_WREG_coma_ACCESS_expect_0x1437(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,WREG,ACCESS  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_WREG_coma_0_expect_0x1437(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,WREG,0  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_WREG_coma_BANKED_expect_0x1537(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,WREG,ACCESS  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_WREG_coma_1_expect_0x1537(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,WREG,1  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"1"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_F_coma_ACCESS_expect_0x1637(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,f,ACCESS  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_1_coma_ACCESS_expect_0x1637(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,f,ACCESS  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_F_coma_BANKED_expect_1737(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,f,BaNkEd  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_1_coma_BANKED_expect_1737(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,f,BaNkEd  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_0_coma_0_expect_0x1437(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,0,0  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_0_coma_1_expect_0x1537(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,0,0  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_1_coma_0_expect_0x1637(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,1,0  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andwf_0x37_coma_1_coma_1_expect_0x1737(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,1,0  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
    IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
    OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
    IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
    getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  	Try {
  		andwf(instr,&memory);
      TEST_ASSERT_EQUAL_PTR(&flash[2],memory);
  		printf("\nthe instruction[   %s   ] opcode is 0x%02x%02x",instr,flash[0],flash[1]);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
  	}
  }
  void test_ANDWF_andvf_expect_NOT_VALID_IDENTIFIER(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDvF    ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDVF"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//

  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF    ";
  	IdentifierToken andwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ANDWF"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//

  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AdDwF   0x37  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,11,4,instr,"0x37",0x37};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0xff_expect_overflow_occur(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0xff1  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0xff1",0xff1};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_INTEGER_TYPE, 15,1,instr,","};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37.  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,"."};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_coma_F_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,F  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  	IdentifierToken FToken = {TOKEN_OPERATOR_TYPE, 16,4,instr,"F"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_coma_D_expect_INVALID_IDENTIFIER_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,D  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"D"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_coma_F_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,F,  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  	OperatorToken op1Token = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,","};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  	getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_ANDWF_andwf_0x37_coma_F_coma_BANKED_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  	CEXCEPTION_T ex;
    uint8_t flash[4] = {0,0,0,0};
  	char *memory = flash;
  	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char instr[] = "   AnDwF   0x37,F,BANKED  ";
  	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
  	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  	OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  	  IdentifierToken BANKEDToken = {TOKEN_OPERATOR_TYPE, 18,6,instr,"BANKED"};

  	initTokenizer_ExpectAndReturn(instr,tokenizer);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
  	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  	getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
  	getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  	Try {
  		andwf(instr,&memory);
  	}Catch(ex) {
  		dumpErrorMessage(ex, 1);
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
