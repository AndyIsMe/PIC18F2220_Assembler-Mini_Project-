#include "unity.h"
#include "mullw.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "tolower.h"

void setUp(void){}
void tearDown(void){}


void test_MULLW_mullw_0x37_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   mullw   0x37  ";
	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"mullw"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
	//IdentifierToken fffToken = {TOKEN_IDENTIFIER_TYPE, 17, 3, "fff"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	//getToken_ExpectAndReturn(tokenizer, (Token *)&fffToken);

	Try {
		machineCode = mullw(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
