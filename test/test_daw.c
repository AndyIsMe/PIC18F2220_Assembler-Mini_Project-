#include "unity.h"
#include "daw.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"

void setUp(void){}
void tearDown(void){}


void test_DAW__daw_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	IdentifierToken dawToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"daw"};


	initTokenizer_ExpectAndReturn("   daw  ",tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dawToken);//


	Try {
		machineCode = daw("   daw  ");
		printf("the instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
