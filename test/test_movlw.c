#include "unity.h"
#include "movlw.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_MOVLW_movlw_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken movlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"movlw"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
	//IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3, "fff"};

	initTokenizer_ExpectAndReturn("   movlw   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlwToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
	//getToken_ExpectAndReturn(tokenizer, (Token *)&fffToken);

	Try {
		machineCode = movlw("   movlw   0x37  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
/*
void xtest_movlw_(void)
{
  Tokenizer *actualTokenizer = (Tokenizer *)0x0badface;
  Tokenizer *tokenizer;
  Token *token;

  IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"movlw"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x63"};

  initTokenizer_ExpectAndReturn("   movlw  0x63    ",tokenizer);
  getToken_ExpectAndReturn(tokenizer,(Token *)&idToken);
  getToken_ExpectAndReturn(tokenizer,(Token *)&intToken);

  Tokenizer *tokenizer = initTokenizer("   movlw  0x63    ");
  TEST_ASSERT_EQUAL_PTR(actualTokenizer,tokenizer);
  token = getToken(tokenizer);                                //pass movlw


  token = getToken(tokenizer);                                //pass 0x63
}*/
