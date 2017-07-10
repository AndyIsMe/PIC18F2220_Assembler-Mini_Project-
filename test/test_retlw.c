#include "unity.h"
#include "retlw.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_RETLW_retlw_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken retlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"retlw"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
	//IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3, "fff"};

	initTokenizer_ExpectAndReturn("   retlw   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	//getToken_ExpectAndReturn(tokenizer, (Token *)&fffToken);

	Try {
		machineCode = retlw("   retlw   0x37  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}