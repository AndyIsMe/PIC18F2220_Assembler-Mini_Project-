#include "unity.h"
#include "clrwdt.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "tolower.h"

void setUp(void){}
void tearDown(void){}


void test_CLRWDT__clrwdt_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   clrwdt  ";
	IdentifierToken clrwdtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"clrwdt"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrwdtToken);//

	Try {
		machineCode = clrwdt(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
