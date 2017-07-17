#include "unity.h"
#include "reset.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "tolower.h"

void setUp(void){}
void tearDown(void){}


void test_RESET__reset_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   reset  ";
	IdentifierToken resetToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"reset"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//


	Try {
		machineCode = reset(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
