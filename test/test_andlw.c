#include "unity.h"
#include "andlw.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_ANDLW_andlw_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"andlw"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn("   andlw   0x37  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = andlw("   andlw   0x37  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
