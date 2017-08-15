#include "unity.h"
#include "AssemblyCode.h"
#include "checkregister.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"

void setUp(void){}
void tearDown(void){}/*
TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
TEST_ASSERT_EQUAL(NOT_VALID_INTEGER,ex->errorCode);
*/

void test_ADDLW_addlw_0x37_expect_0x0f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aDdLw   0x37  ";
	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode=addlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDLW_addmw_expect_NOT_VALID_IDENTIFIER_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDlW    ";
	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDvF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
	Try {
 		addlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDLW_addlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDlW       ";
	IdentifierToken addlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ADDLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
	Try {
 		addlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDLW_addlw_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aDdLw   0x37  ";
	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDLW"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		addlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDLW_addlw_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aDdLw   0xff1  ";
	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		addlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_ADDWF_addwf_0x37_coma_W_coma_ACCESS_expect_0x2437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,W,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"W"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWF_addwf_0x37_coma_W_coma_0_expect_0x2437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,W,0  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"W"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_WREG_coma_ACCESS_expect_0x2437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,WREG,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_WREG_coma_0_expect_0x2437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,WREG,0  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_WREG_coma_BANKED_expect_0x2537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,WREG,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_WREG_coma_1_expect_0x2537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,WREG,1  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_F_coma_ACCESS_expect_0x2637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,f,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_1_coma_ACCESS_expect_0x2637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,f,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_F_coma_BANKED_expect_2737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,f,BaNkEd  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_1_coma_BANKED_expect_2737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,f,BaNkEd  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_0_coma_0_expect_0x2437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,0,0  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_0_coma_1_expect_0x2537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,0,0  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_1_coma_0_expect_0x2637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,1,0  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addwf_0x37_coma_1_coma_1_expect_0x2737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,1,0  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ADDWF_addvf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDvF    ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDvF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//

	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF    ";
	IdentifierToken addwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ADDWF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//

	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0xff_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0xff1  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_INTEGER_TYPE, 15,1,instr,","};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37.  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,"."};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_coma_F_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,F  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_OPERATOR_TYPE, 16,4,instr,"F"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_coma_D_expect_INVALID_IDENTIFIER_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,D  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"D"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_coma_F_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,F,  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
	OperatorToken op1Token = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,","};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ADDWF_addwf_0x37_coma_F_coma_BANKED_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,F,BANKED  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
	OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
	  IdentifierToken BANKEDToken = {TOKEN_OPERATOR_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
	Try {
		addwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_ADDWFC_addwfc_0x37_coma_W_coma_ACCESS_expect_0x2037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc   0x37,W,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"W"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_W_coma_0_expect_0x2037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,W,0  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"W"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_WREG_coma_ACCESS_expect_0x2037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc   0x37,WREG,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_WREG_coma_0_expect_0x2037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,WREG,0  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_WREG_coma_BANKED_expect_0x2137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc   0x37,WREG,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_WREG_coma_1_expect_0x2137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,WREG,1  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_F_coma_ACCESS_expect_0x2237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc  0x37,f,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_1_coma_ACCESS_expect_0x2237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,1,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_F_coma_BANKED_expect_2337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc  0x37,f,BaNkEd  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_1_coma_BANKED_expect_2337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,f,BaNkEd  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_0_coma_0_expect_0x2037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,0,0  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_0_coma_1_expect_0x2137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,0,0  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_1_coma_0_expect_0x2237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,1,0  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwfc_0x37_coma_1_coma_1_expect_0x2337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,1,0  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_ADDWFC_addwdf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwdF    ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ADDWDF"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC    ";
	IdentifierToken addwfcToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"ADDWFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//

	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0xff_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0xff1  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_INTEGER_TYPE, 15,1,instr,","};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37.  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,"."};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_coma_F_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,F  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_OPERATOR_TYPE, 16,4,instr,"F"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_coma_D_expect_INVALID_IDENTIFIER_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,D  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"D"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_coma_F_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,F,  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
	OperatorToken op1Token = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,","};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ADDWFC_addwfc_0x37_coma_F_coma_BANKED_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFC  0x37,F,BANKED  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
	IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
	OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
	  IdentifierToken BANKEDToken = {TOKEN_OPERATOR_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
	getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
	getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
	Try {
		addwfc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_ANDLW_addlw_0x37_expect_0xf37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aNdLw   0x37  ";
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = andlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDLW_anddw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ANDwW    ";
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//

	Try {
		andlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDLW_andlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDlW       ";
	IdentifierToken andlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ANDLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
	Try {
 		andlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDLW_andlw_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aNdLw   0x37  ";
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDLW"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		andlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDLW_andlw_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aNdLw   0xff1  ";
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		andlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_ANDWF_andwf_0x37_coma_WREG_coma_ACCESS_expect_0x1437(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_WREG_coma_0_expect_0x1437(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_WREG_coma_BANKED_expect_0x1537(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_WREG_coma_1_expect_0x1537(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_F_coma_ACCESS_expect_0x1637(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_1_coma_ACCESS_expect_0x1637(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_F_coma_BANKED_expect_1737(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_1_coma_BANKED_expect_1737(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_0_coma_0_expect_0x1437(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_0_coma_1_expect_0x1537(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_1_coma_0_expect_0x1637(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andwf_0x37_coma_1_coma_1_expect_0x1737(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_ANDWF_andvf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDvF    ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDVF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//

	Try {
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDwF    ";
	IdentifierToken andwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"ANDWF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//

	Try {
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0xff_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDwF   0xff1  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_coma_F_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_coma_D_expect_INVALID_IDENTIFIER_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_coma_F_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_ANDWF_andwf_0x37_coma_F_coma_BANKED_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		andwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BC_bc_0x37_expect_0xe21a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bC   0x37  ";
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BC_bc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bs    ";
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"Bs"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//

	Try {
		bc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BC_bc_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bC      ";
	IdentifierToken bcToken = {TOKEN_OPERATOR_TYPE, 3,2,instr,"BC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//
	Try {
 		bc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BC_bc_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bC   0x37  ";
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BC"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BC_bc_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bC   0xff1  ";
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BN_bn_0x37_expect_0xe61a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bN   0x37  ";
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BN_bd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bd    ";
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BD"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//

	Try {
		bn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BN_bn_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bN      ";
	IdentifierToken bnToken = {TOKEN_OPERATOR_TYPE, 3,2,instr,"BN"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
	Try {
 		bn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BN_bn_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bN   0x37  ";
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BN"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BN_bn_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bN   0xff1  ";
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BNC_bnc_0x37_expect_0xe31a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNC   0x37  ";
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BNC_bc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bc    ";
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//

	Try {
		bnc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNC_bnc_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bNc      ";
	IdentifierToken bncToken = {TOKEN_OPERATOR_TYPE, 3,2,instr,"BNC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	Try {
 		bnc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNC_bnc_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNc   0x37  ";
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BNC"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNC_bnc_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNc   0xff1  ";
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BNC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BNN_bnn_0x37_expect_0xe71a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNN   0x37  ";
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BNN_bnm_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bnm    ";
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNM"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//

	Try {
		machineCode = bnn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNN_bnn_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bNn      ";
	IdentifierToken bnnToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BNN"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//
	Try {
 		bnn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNN_bnn_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNn  0x37  ";
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNN"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNN_bnn_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNn  0xff1  ";
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnn(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BNOV_bnov_0x37_expect_0xe51a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNoV   0x37  ";
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"BNOV"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BNOV_bnow_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BnoW    ";
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"BNOW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//

	Try {
		machineCode = bnov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNOV_bnov_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bNoV      ";
	IdentifierToken bnovToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"BNov"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//
	Try {
 		bnov(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNOV_bnov_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNoV 0x37  ";
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"BNOV"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnov(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNOV_bnov_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNoV 0xff1  ";
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"BNOV"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnov(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BNZ_bnz_0x37_expect_0xe11a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNZ   0x37  ";
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BNZ_bnx_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bnx    ";
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNX"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//

	Try {
		bnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNZ_bnz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bNz      ";
	IdentifierToken bnzToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BNZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//
	Try {
 		bnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNZ_bnz_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNz  0x37  ";
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BNZ"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BNZ_bnz_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNz   0xff1  ";
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BOV_bov_0x37_expect_0xe41a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   boV   0x37  ";
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BOV"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BOV_bov_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bow    ";
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BOW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//

	Try {
		machineCode = bov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BOV_bov_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   boV      ";
	IdentifierToken bovToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"Bov"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//
	Try {
 		bov(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BOV_bov_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   boV 0x37  ";
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BOV"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bov(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BOV_bov_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   boV 0xff1  ";
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BOV"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bov(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BRA_bra_0x801_expect_0xd39ad7ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA   0x801  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BRA"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,5,instr,"0x801",0x801};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BRA_bra_0x37_expect_0xdo1ad7ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA   0x37  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BRA"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BRA_bra_0x1_expect_0xd7ffd7ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA   0x1  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BRA"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,3,instr,"0x1",0x1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BRA_brb_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Brb    ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BRB"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BRA_bra_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   brA      ";
	IdentifierToken braToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BRA"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	Try {
 		bra(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BRA_bra_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA 0x37  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BRA"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bra(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BRA_bra_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA 0xff1  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BRA"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0x802",0x802};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bra(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BZ_bz_0x37_expect_0xe01a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bZ   0x37  ";
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BZ_ba_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Ba    ";
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BA"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//

	Try {
		bz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BZ_bz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bZ      ";
	IdentifierToken bzToken = {TOKEN_OPERATOR_TYPE, 3,2,instr,"BZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//
	Try {
 		bz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BZ_bz_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bZ   0x37  ";
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BZ"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BZ_bz_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bZ   0xff1  ";
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,instr,"BZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BCF_bcf_0x37_4_ACCESS_expect_0x9837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,4,ACCESS  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"ACCESS"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcf_0x37_4_0_expect_0x9837(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,4,0  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcf_0x37_4_BANKED_expect_0x9937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,4,BANKED  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"BANKED"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcf_0x37_4_1_expect_0x9937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,4,1  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcf_0x37_8_1_expect_0x9137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,8,1  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"8",8};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcf_0x37_9_1_expect_0x9337(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,9,1  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"9",9};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcf_0x37_10_1_expect_0x9137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,10,1  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,2,instr,"10",10};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BCF_bcd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BcD    ";
	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BCD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//

	Try {
		bcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BCF_bcf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf      ";
	IdentifierToken bcfToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BCF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
	Try {
 		bcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BCF_bcf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bCf  0x37  ";
	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BCF"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BCF_bcf_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bCf  0xff1  ";
	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		bcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BSF_bsf_0x37_4_ACCESS_expect_0x8837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,4,ACCESS  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"ACCESS"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsf_0x37_4_0_expect_0x8837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,0,ACCESS  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsf_0x37_4_BANKED_expect_0x8937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,4,BANKED  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"BANKED"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsf_0x37_4_1_expect_0x8937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,4,1  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsf_0x37_8_1_expect_0x8137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,8,1  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"8",8};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsf_0x37_9_1_expect_0x8337(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,4,1  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"9",9};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsf_0x37_10_1_expect_0x8137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,4,1  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,2,instr,"10",10};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BSF_bsd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BsD    ";
	IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BSD"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//

	Try {
		bsf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BSF_bsf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf      ";
	IdentifierToken bsfToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BSF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//
	Try {
 		bsf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BSF_bsf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bSf  0x37  ";
	IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BSF"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		bsf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BSF_bsf_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bSf  0xff1  ";
	IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BSF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		bsf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BTFSC_btfsc_0x37_4_ACCESS_expect_0xb837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsc   0x37,6,ACCESS  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_btfsc_0x37_4_0_expect_0xb837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsc   0x37,4,0  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_bsfsc_0x37_4_BANKED_expect_0xb937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSC   0x37,4,BANKED  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_bsfsc_0x37_4_1_expect_0xb937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSC   0x37,4,1  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_bsfsc_0x37_8_1_expect_0xb137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSC   0x37,8,1  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"8",8};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_bsfsc_0x37_9_1_expect_0xb337(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSC   0x37,9,1  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"9",9};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_bsfsc_0x37_10_1_expect_0xb137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSC   0x37,10,1  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,2,instr,"10",10};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 18,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 19,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);
  Try {
    machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSC_brbbf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BrbbF    ";
	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BRBBF"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
	Try {
		btfsc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTFSC_btfsc_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsC      ";
	IdentifierToken btfscToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"BTFSC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
	Try {
 		btfsc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTFSC_btfsc_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bTfsC  0x37  ";
	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSC"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,10,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		btfsc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTFSC_btfsc_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bTfsC  0xff1  ";
	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		btfsc(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BTFSS_btfss_0x37_4_ACCESS_expect_0xa837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsS   0x37,6,ACCESS  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfss_0x37_4_0_expect_0xa837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsS   0x37,6,0  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfss_0x37_4_BANKED_expect_0xa937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSS   0x37,4,BANKED  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfss_0x37_4_1_expect_0xa937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSS   0x37,4,1  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfss_0x37_8_1_expect_0xa137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSS   0x37,8,1  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"8",8};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfss_0x37_9_1_expect_0xa337(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSS   0x37,9,1  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,instr,"9",9};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfss_0x37_10_1_expect_0xa137(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSS   0x37,10,1  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,instr,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,2,instr,"10",10};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 18,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 19,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTFSS_btfse_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BtFSe    ";
	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSE"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//

	Try {
		btfss(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTFSS_btfss_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsS      ";
	IdentifierToken btfssToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"BTFSS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
	Try {
 		btfss(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTFSS_btfss_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bTfsS  0x37  ";
	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSS"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,10,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		btfss(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTFSS_btfss_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bTfsS  0xff1  ";
	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"BTFSS"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		btfss(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_BTG_btg_0x37_4_ACCESS_expect_0x7837(void){
  CEXCEPTION_T ex;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,4,ACCESS  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"ACCESS"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btg_0x37_4_0_expect_0x7837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,4,0  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btg_0x37_4_BANKED_expect_0x7937(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,4,BANKED  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,instr,"BANKED"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btg_0x37_4_1_expect_0x7937(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,4,1  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btg_0x37_8_1_expect_0x7137(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,8,1  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"8",8};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btg_0x37_9_1_expect_0x7337(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,9,1  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,instr,"9",9};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btg_0x37_10_1_expect_0x7137(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,10,1  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,instr,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,2,instr,"10",10};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
}
void xtest_BTG_btt_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Btt    ";
	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BTT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//

	Try {
		btg(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_BTG_btg_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTg      ";
	IdentifierToken btgToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"BTG"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
	Try {
 		btg(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTG_btg_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bTg  0x37  ";
	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BTG"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		btg(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_BTG_btg_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bTg  0xff1  ";
	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"BTG"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		btg(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_CALL_call_0xbff_coma_0_expect_0xecfff005(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xbff,0  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xbff",0xbff};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,15,1,instr,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,16,1,instr,"0",0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CALL_call_0xbff_coma_1_expect_0xedfff005(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xbff,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xbff",0xbff};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,15,1,instr,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,16,1,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CALL_call_0xfe_coma_1_expect_0xed7ff000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xfe,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xfe",0xfe};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,14,1,instr,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,15,1,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CALL_call_0xf_coma_1_expect_0xed07f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xf,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xf",0xf};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,14,1,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CALL_call_0x0_coma_1_expect_0xed00f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0x0,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x0",0x0};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,14,1,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CALL_calr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CaLr    ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CALL_call_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cAlL      ";
	IdentifierToken callToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"CALL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	Try {
 		call(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CALL_call_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   CalL  0x37  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		call(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CALL_call_0x37_fullstop_expect_INVALID_OPERATOR_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   caLl  0x37.      ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,"."};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	Try {
 		call(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CALL_call_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   CalL  0x37,  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,13,1,instr,","};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	Try {
		call(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CALL_call_0x37_coma_1_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   CalL  0x37,  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
	IntegerToken int1Token = {TOKEN_OPERATOR_TYPE,14,1,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);//
	Try {
		call(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CALL_call_0xfff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL  0xff1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,6,instr,"0xff1",0xfff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		call(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_CLRF_clrf_0x37_coma_ACCESS_expect_0x6a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF   0x37,ACCESS  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CLRF_clrf_0x37_coma_0_expect_0x6a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF   0x37,0  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CLRF_clrf_0x37_coma_BANKED_expect_0x6b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF   0x37,BANKED  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 12,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CLRF_clrf_0x37_coma_1_expect_0x6b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF   0x37,1  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CLRF_clrr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CLrr    ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//

	Try {
		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRF_clrf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF      ";
	IdentifierToken clrfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"CLRF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	Try {
 		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRF_clrf_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF      ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,9,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
 		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRF_clrf_0x37_fullstop_expect_INVALID_OPERATOR_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF  0x37.      ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,"."};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	Try {
 		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRF_clrf_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   ClRf  0x37,  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,13,1,instr,","};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	Try {
		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRF_clrf_0x37_coma_1_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   ClRf  0x37,  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,instr,"0x37",0x37};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,instr,","};
	IntegerToken int1Token = {TOKEN_OPERATOR_TYPE,14,1,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);//
	Try {
		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRF_clrf_0xfff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cLrf  0xff1  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,5,instr,"0xff1",0xff1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	Try {
		clrf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_CLRWDT__clrwdt_expect_0x0004(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cLrWDt  ";
	IdentifierToken clrwdtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CLRWDT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrwdtToken);//

	Try {
		machineCode = clrwdt(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_CLRWDT_clrwed_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CLrwEd    ";
	IdentifierToken clrwdtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CLRWED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrwdtToken);//

	Try {
		clrwdt(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_CLRWDT_clrwdt_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrWdT      ";
	IdentifierToken clrwdtToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"CLRWDT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrwdtToken);//
	Try {
 		clrwdt(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_COMF_comf_0x37_coma_0_coma_ACCESS_expect_0x1c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,0,ACCESS  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_WREG_coma_0_expect_0x1c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,WREG,0  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_0_coma_BANKED_expect_0x1d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,0,BANKED  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_WREG_coma_1_expect_0x1d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,WREG,1  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_F_coma_ACCESS_expect_0x1e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,F,ACCESS  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_1_coma_ACCESS_expect_0x1e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,1,ACCESS  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_F_coma_BANKED_expect_0x1f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,F,BANKED  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_comf_0x37_coma_1_coma_BANKED_expect_0x1f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,1,BANKED  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_COMF_come_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CoME    ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"COME"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_COMF_comf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   coMf      ";
	IdentifierToken comfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"COMF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//
	Try {
 		comf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_CPFSEQ_cpfseq_0x37_coma_ACCESS_expect_0x6237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsEq   0x37,ACCESS  ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSEQ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSEQ_cpfseq_0x37_coma_0_expect_0x6237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsEq   0x37,ACCESS  ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSEQ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSEQ_cpfseq_0x37_coma_BANKED_expect_0x6337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSEq   0x37,BANKED  ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSEQ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSEQ_cpfseq_0x37_coma_1_expect_0x6337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSEq   0x37,1  ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSEQ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSEQ_cpfsef_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CpFSef    ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSEF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	Try {
		cpfseq(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_CPFSEQ_cpfseq_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cpFsEq      ";
	IdentifierToken cpfseqToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"CPFSEQ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	Try {
 		cpfseq(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_CPFSGT_cpfsgt_0x37_coma_ACCESS_expect_0x6437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsGt   0x37,ACCESS  ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSGT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSGT_cpfsgt_0x37_coma_0_expect_0x6437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsGt   0x37,ACCESS  ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSGT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSGT_cpfsgt_0x37_coma_BANKED_expect_0x6537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSGt   0x37,BANKED  ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSGT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSGT_cpfsgt_0x37_coma_1_expect_0x6537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSGt   0x37,1  ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSGT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSGT_cpfsgd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CpFSGd    ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSGD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//

	Try {
		cpfsgt(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_CPFSGT_cpfsgt_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cpFsGt      ";
	IdentifierToken cpfsgtToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"CPFSGT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	Try {
 		cpfsgt(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_CPFSLT_cpfslt_0x37_coma_ACCESS_expect_0x6037(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSLT_cpfslt_0x37_coma_0_expect_0x6037(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSLT_cpfslt_0x37_coma_BANKED_expect_0x6137(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSLT_cpfslt_0x37_coma_1_expect_0x6137(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_CPFSLT_cpfsle_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CpFSLe    ";
	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"CPFSLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//

	Try {
		cpfslt(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_CPFSLT_cpfslt_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cpFsLt      ";
	IdentifierToken cpfsltToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"CPFSLT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
	Try {
 		cpfslt(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_DAW_daw_expect_0x0007(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   daW     ";
	IdentifierToken dawToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"DAW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dawToken);//
	Try {
		machineCode = daw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DAW_dae_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DaE    ";
	IdentifierToken dawToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"DAE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dawToken);//

	Try {
		machineCode = daw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_DAW_daw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Daw      ";
	IdentifierToken dawToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"DAW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dawToken);//
	Try {
 		daw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_DECF_decf_0x37_coma_0_coma_ACCESS_expect_0x0437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,0,ACCESS  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decf_0x37_coma_WREG_coma_ACCESS_expect_0x0437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,WREG,ACCESS  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decf_0x37_coma_WREG_coma_BANKED_expect_0x0537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,WREG,BANKED  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decf_0x37_coma_F_coma_ACCESS_expect_0x0637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,F,ACCESS  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decf_0x37_coma_F_coma_BANKED_expect_0x0737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,F,BANKED  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decf_0x37_coma_F_coma_1_expect_0x0737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,F,1  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decf_0x37_coma_1_coma_1_expect_0x0737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,1,1  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECF_decd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DeCd    ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"DECD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_DECF_decf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DeCF      ";
	IdentifierToken decfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"DECF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfToken);//
	Try {
 		decf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_DECFSZ_decfsz_0x37_coma_0_coma_ACCESS_expect_0x2c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,0,ACCESS  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decfsz_0x37_coma_WREG_coma_ACCESS_expect_0x2c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,WREG,ACCESS  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decfsz_0x37_coma_WREG_coma_BANKED_expect_0x2d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsz  0x37,WREG,BANKED  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decfsz_0x37_coma_F_coma_ACCESS_expect_0x2e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsz  0x37,F,ACCESS  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decfsz_0x37_coma_F_coma_BANKED_expect_0x2f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,F,BANKED  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decfsz_0x37_coma_F_coma_1_expect_0x2f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,F,1  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decfsz_0x37_coma_1_coma_1_expect_0x2f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,1,1  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DECFSZ_decdsz_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DeCdsZ    ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DECDSZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_DECFSZ_decfsz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DeCFsZ      ";
	IdentifierToken decfszToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"DECFSZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//
	Try {
 		decfsz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_DCFSNZ_dcfsnz_0x37_coma_0_coma_ACCESS_expect_0x4c37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcfsnz_0x37_coma_WREG_coma_ACCESS_expect_0x4c37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcfsnz_0x37_coma_WREG_coma_BANKED_expect_0x4d37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcfsnz_0x37_coma_F_coma_ACCESS_expect_0x4e37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcfsnz_0x37_coma_F_coma_BANKED_expect_0x4f37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcfsnz_0x37_coma_F_coma_1_expect_0x4f37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcfsnz_0x37_coma_1_coma_1_expect_0x4f37(void){
	CEXCEPTION_T ex;
	int machineCode;
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
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_DCFSNZ_dcdsnz_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DCdsnZ    ";
	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"DCDSNZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//

	Try {
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_DCFSNZ_dcfsnz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DCFsnZ      ";
	IdentifierToken dcfsnzToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"DCFSNZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//
	Try {
 		dcfsnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_GOTO_goto_0xbff_expect_0xeffff005(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0xbff  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,instr,"0xbff",0xbff};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//


	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_GOTO_goto_0xfe_expect_0xef7ff000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0xfe  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xfe",0xfe};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_GOTO_goto_0xf_expect_0xef07f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0xf  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0xf",0xf};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_GOTO_goto_0x0_expect_0xef00f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0x0  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x0",0x0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_GOTO_gotd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   gOtD    ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"GOTD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_GOTO_goto_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   GoTo      ";
	IdentifierToken gotoToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"GOTO"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	Try {
 		_goto(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_INCF_incf_0x37_coma_0_coma_ACCESS_expect_0x2837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   incF    0x37,0,ACCESS  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCF_incf_0x37_coma_WREG_coma_ACCESS_expect_0x2837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   incF    0x37,WREG,ACCESS  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCF_incf_0x37_coma_WREG_coma_BANKED_expect_0x2937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   IncF    0x37,WREG,BANKED  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCF_incf_0x37_coma_F_coma_ACCESS_expect_0x2a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcF    0x37,F,ACCESS  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCF_incf_0x37_coma_F_coma_BANKED_expect_0x2b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcF    0x37,F,BANKED  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCF_incf_0x37_coma_F_coma_1_expect_0x2b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcF    0x37,F,1  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCF_incf_0x37_coma_1_coma_1_expect_0x2b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcF    0x37,1,1  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_INCF_infe_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNfE    ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"INFE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//

	Try {
		incf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_INCF_incf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   IncF      ";
	IdentifierToken incfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"INCF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//
	Try {
 		incf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_INCFSZ_incfsz_0x37_coma_0_coma_ACCESS_expect_0x3c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,0,ACCESS  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_WREG_coma_ACCESS_expect_0x3c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,WREG,ACCESS  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_WREG_coma_BANKED_expect_0x3d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,WREG,BANKED  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_F_coma_ACCESS_expect_0x3e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,F,ACCESS  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_F_coma_BANKED_expect_0x3f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,F,BANKED  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_F_coma_1_expect_0x3f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,F,1  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_1_coma_1_expect_0x3f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,1,1  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_INCFSZ_incfec_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcfEC    ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INCFEC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//

	Try {
		incfsz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_INCFSZ_incfsz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   IncFsZ      ";
	IdentifierToken incfszToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"INCFSZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//
	Try {
 		incfsz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_INFSNZ_infsnz_0x37_coma_0_coma_ACCESS_expect_0x4837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,0,ACCESS  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"0"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_WREG_coma_ACCESS_expect_0x4837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,WREG,ACCESS  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_WREG_coma_BANKED_expect_0x4937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,WREG,BANKED  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_F_coma_ACCESS_expect_0x4a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,F,ACCESS  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_F_coma_BANKED_expect_0x4b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,F,BANKED  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_F_coma_1_expect_0x4b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,F,1  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_1_coma_1_expect_0x4b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,1,1  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_INFSNZ_infsnc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNfsNC    ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"INFSNC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//

	Try {
		infsnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_INFSNZ_infsnz_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   InFsnZ      ";
	IdentifierToken infsnzToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"INFSNZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//
	Try {
 		infsnz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_IORLW_iorlw_0x37_expect_0x0937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   IoRLw   0x37  ";
	IdentifierToken iorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"IORLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&iorlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = iorlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_IORLW_iorle_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iOrLe    ";
	IdentifierToken iorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"IORLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&iorlwToken);//

	Try {
		iorlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_IORLW_iorlw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ioRlW    ";
	IdentifierToken iorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"IORLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&iorlwToken);//

	Try {
		iorlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_IORLW_iorlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   IoRlW      ";
	IdentifierToken iorlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"IORLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&iorlwToken);//
	Try {
 		iorlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_MOVLB_movlb_0x9_expect_0x0109(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   MoVLb   0x9  ";
	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVLB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,instr,"0x9",0x9};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = movlb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MOVLB_movlb_0xff_expect_0x010f(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   MoVLb   0xf9  ";
	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVLB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,instr,"0xf9",0xf9};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = movlb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MOVLB_mvole_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mVoLe    ";
	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MVOLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//

	Try {
		movlb(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MOVLB_movlb_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   moVlB      ";
	IdentifierToken movlbToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MOVLB"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
	Try {
 		movlb(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_MOVLW_movlw_0x37_expect_0x0e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   MoVLw   0x37  ";
	IdentifierToken movlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = movlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MOVLW_movld_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvLD    ";
	IdentifierToken movlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVLD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlwToken);//

	Try {
		movlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MOVLW_movlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   moVlw      ";
	IdentifierToken movlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MOVLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlwToken);//
	Try {
 		movlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_MOVWF_movwf_0x37_coma_0_expect_0x6e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVwF   0x37,0  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = movwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVWF_movwf_0x37_coma_ACCESS_expect_0x6e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVwF   0x37,ACCESS  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = movwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVWF_movwf_0x37_coma_BANKED_expect_0x6f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVwF   0x37,BANKED  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = movwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVWF_movwf_0x37_coma_1_expect_0x6f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVwF   0x37,1  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = movwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MOVWF_movwr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvwR    ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVWR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//

	Try {
		movwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MOVWF_movwf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   moVwf      ";
	IdentifierToken movwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MOVWF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	Try {
 		movwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_MOVF_movf_0x37_coma_WREG_coma_0_expect_0x5037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,WREG,0  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 19,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 20,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVF_movf_0x37_coma_WREG_coma_ACCESS_expect_0x5037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,WREG,ACCESS  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 19,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 20,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVF_movf_0x37_coma_WREG_coma_BANKED_expect_0x5137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,WREG,BANKED  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 19,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 20,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVF_movf_0x37_coma_F_coma_ACCESS_expect_0x5237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF    0x37,F,ACCESS  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVF_movf_0x37_coma_F_coma_BANKED_expect_0x5337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF    0x37,F,BANKED  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVF_movf_0x37_coma_F_coma_1_expect_0x5337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF    0x37,F,1  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MOVF_movf_0x37_coma_1_coma_1_expect_0x5337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF    0x37,1,1  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MOVF_movd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvD    ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"MOVD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//

	Try {
		movf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MOVF_movf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   moVf      ";
	IdentifierToken movfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"MOVF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//
	Try {
 		movf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_MOVFF_movff_0x222_coma_movff_0xff_expect_0xc222_0xf0ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVfF   0x222,0xff  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVFF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,5,instr,"0x222",0x222};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,instr,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,4,instr,"0xff",0xff};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = movff(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MOVFF_movft_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvfT    ";
	IdentifierToken movffToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MOVFT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movffToken);//

	Try {
		movff(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MOVFF_movff_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   moVff      ";
	IdentifierToken movffToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MOVFF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movffToken);//
	Try {
 		movff(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_MULLW_mullw_0x37_expect_0x0d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   mUlLw   0x37  ";
	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = mullw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MULLW_mulld_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mulLD    ";
	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULLD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//

	Try {
		mullw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MULLW_mullw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mUllW      ";
	IdentifierToken mullwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MULLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//
	Try {
 		mullw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_MULWF_mulwf_0x37_coma_0_expect_0x0237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MuLWf   0x37,0  ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MULWF_mulwf_0x37_coma_ACCESS_expect_0x0237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MuLWf   0x37,ACCESS  ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MULWF_mulwf_0x37_coma_BANKED_expect_0x0337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MuLWf   0x37,BANKED  ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_MULWF_mulwf_0x37_coma_1_expect_0x0337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MuLWf   0x37,1  ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_MULWF_mulle_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   muLLe    ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"MULLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//

	Try {
		 mulwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_MULWF_mulwf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mUlwF      ";
	IdentifierToken mulwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"MULWF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	Try {
 		mulwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_NEGF_negf_0x37_coma_0_expect_0x6c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Negf   0x37,0  ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"NEGF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_NEGF_negf_0x37_coma_ACCESS_expect_0x6c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Negf   0x37,ACCESS  ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"NEGF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_NEGF_negf_0x37_coma_BANKED_expect_0x6d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Negf   0x37,BANKED  ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"NEGF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_NEGF_negf_0x37_coma_1_expect_0x6d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Negf   0x37,1  ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"NEGF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_NEGF_negd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   nEGD    ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"NEGD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//

	Try {
		negf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_NEGF_negf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   NeGF      ";
	IdentifierToken negfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"NEGF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	Try {
 		negf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_POP_pop_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   PoP  ";
	IdentifierToken popToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"POP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//

	Try {
		machineCode = pop(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_POF_pof_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   poF    ";
	IdentifierToken popToken = {TOKEN_IDENTIFIER_TYPE, 3,3,instr,"POF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//

	Try {
		pop(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_POP_pop_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   PoP      ";
	IdentifierToken popToken = {TOKEN_OPERATOR_TYPE, 3,3,instr,"POP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//
	Try {
 		pop(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_PUSH_push_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   PUSH  ";
	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"PUSH"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//

	Try {
		machineCode = push(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_PUSH_puhs_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   pUhS    ";
	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"PUHS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//

	Try {
		push(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_PUSH_push_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   pUsH      ";
	IdentifierToken pushToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"PUSH"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//
	Try {
 		push(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_RESET_reset_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   RESET  ";
	IdentifierToken resetToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RESET"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//

	Try {
		machineCode = reset(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_RESET_reste_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReSTe    ";
	IdentifierToken resetToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RESTE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//

	Try {
		reset(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_RESET_reset_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReSEt      ";
	IdentifierToken resetToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"RESET"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//
	Try {
 		reset(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_RETFIE_retfie_0_expect_0x0010(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rEtFIE   0  ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETFIE"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0",0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_RETFIE_retfie_1_expect_0x0011(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rEtFIE   1  ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETFIE"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_RETFIE_retfie_2_expect_0x0010(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rEtFIE   2  ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETFIE"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"2",2};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_RETFIE_retfei_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReTFei    ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETFEI"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//

	Try {
		retfie(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_RETFIE_retfie_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReTfIe      ";
	IdentifierToken retfieToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"RETFIE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	Try {
 		retfie(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_RETURN_return_0_expect_0x0012(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rETuRn   0  ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETURN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0",0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RETURN_return_1_expect_0x0013(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rETuRn   1  ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETURN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RETURN_return_2_expect_0x0012(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rETuRn   2  ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"RETURN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"2",2};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RETURN_retunr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   REtunr    ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE,3 ,6,instr,"RETUNR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//

	Try {
		_return(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_RETURN_return_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReTuRn      ";
	IdentifierToken returnToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"RETURN"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	Try {
 		_return(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_RLCF_rlcf_0x37_coma_WREG_coma_0_expect_0x3437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,0,ACCESS  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlcf_0x37_coma_WREG_coma_ACCESS_expect_0x3437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,WREG,ACCESS  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlcf_0x37_coma_WREG_coma_BANKED_expect_0x3537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,WREG,BANKED  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlcf_0x37_coma_F_coma_ACCESS_expect_0x3637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,F,ACCESS  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlcf_0x37_coma_F_coma_BANKED_expect_0x3737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,F,BANKED  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlcf_0x37_coma_F_coma_1_expect_0x3737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,F,1  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlcf_0x37_coma_1_coma_1_expect_0x3737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,1,1  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLCF_rlfc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RLfC    ";
	IdentifierToken rlfcToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RLFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlfcToken);//

	Try {
		rlcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_RLCF_rlcf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlCf      ";
	IdentifierToken rlcfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"RLCF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlcfToken);//
	Try {
 		rlcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_RLNCF_rlncf_0x37_coma_WREG_coma_0_expect_0x4437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,WREG,0  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_WREG_coma_ACCESS_expect_0x4437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,WREG,ACCESS  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_WREG_coma_BANKED_expect_0x4537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,WREG,BANKED  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_F_coma_ACCESS_expect_0x4637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,F,ACCESS  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_F_coma_BANKED_expect_0x4737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,F,BANKED  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_F_coma_1_expect_0x4737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,F,1  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_1_coma_1_expect_0x4737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,1,1  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RLNCF_rlnfc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RLnfC    ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"RLNFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//

	Try {
		rlncf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_RLNCF_rlncf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlnCf      ";
	IdentifierToken rlncfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"RLNCF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//
	Try {
 		rlncf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_RRCF_rrcf_0x37_coma_WREG_coma_0_expect_0x3037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,WREG,0  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrcf_0x37_coma_WREG_coma_ACCESS_expect_0x3037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,WREG,ACCESS  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrcf_0x37_coma_WREG_coma_BANKED_expect_0x3137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,WREG,BANKED  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrcf_0x37_coma_F_coma_ACCESS_expect_0x3237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,F,ACCESS  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrcf_0x37_coma_F_coma_BANKED_expect_0x3337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,F,BANKED  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrcf_0x37_coma_F_coma_1_expect_0x3337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,F,1  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrcf_0x37_coma_1_coma_1_expect_0x3337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,1,1  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_RRCF_rrfc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrFc    ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"RRFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//

	Try {
		rrcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_RRCF_rrcf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrCf      ";
	IdentifierToken rrcfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"RRCF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//
	Try {
 		rrcf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SETF_setf_0x37_coma_0_expect_0x6837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Setf   0x37,0  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SETF_setf_0x37_coma_ACCESS_expect_0x6837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Setf   0x37,ACCESS  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SETF_setf_0x37_coma_BANKED_expect_0x6937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Setf   0x37,BANKED  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SETF_setf_0x37_coma_1_expect_0x6937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Setf   0x37,1  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SETF_seft_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SEfT    ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,instr,"SEFT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//

	Try {
		setf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SETF_setf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sEtF      ";
	IdentifierToken setfToken = {TOKEN_OPERATOR_TYPE, 3,4,instr,"SETF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	Try {
 		setf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SLEEP_sleep_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   SLEEP  ";
	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SLEEP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//

	Try {
		machineCode = sleep(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
	dumpErrorMessage(ex, 1);
	}
}
void test_SLEEP_slepe_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SlEpe    ";
	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SLEPE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//

	Try {
		sleep(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SLEEP_sleep_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SlEep      ";
	IdentifierToken sleepToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"SLEEP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//
	Try {
 		sleep(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SUBLW_sublw_0x37_expect_0x0837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   SuBLw   0x37  ";
	IdentifierToken sublwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = sublw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBLW_subwl_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwl    ";
	IdentifierToken sublwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//

	Try {
		sublw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SUBLW_sublw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBlW      ";
	IdentifierToken sublwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"SUBLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//
	Try {
 		sublw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SUBWF_subwf_0x37_coma_WREG_coma_0_expect_0x5c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,WREG,0  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_subwf_0x37_coma_WREG_coma_ACCESS_expect_0x5c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,WREG,ACCESS  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_subwf_0x37_coma_WREG_coma_BANKED_expect_0x5d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,WREG,BANKED  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_subwf_0x37_coma_F_coma_ACCESS_expect_0x5e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,F,ACCESS  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_subwf_0x37_coma_F_coma_BANKED_expect_0x5f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,F,BANKED  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_subwf_0x37_coma_F_coma_1_expect_0x5f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,F,1  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_subwf_0x37_coma_1_coma_1_expect_0x5f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,1,1  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWF_sbufw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sbUfW    ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SBUFW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//

	Try {
		subwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SUBWF_subwf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF      ";
	IdentifierToken subwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"SUBWF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//
	Try {
 		subwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SUBWFB_subwfb_0x37_coma_WREG_coma_0_expect_0x5837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,WREG,0  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWFB_subwfb_0x37_coma_WREG_coma_ACCESS_expect_0x5837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,WREG,ACCESS  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWFB_subwfb_0x37_coma_WREG_coma_BANKED_expect_0x5937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,WREG,BANKED  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWFB_subwfb_0x37_coma_F_coma_ACCESS_expect_0x5a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,F,ACCESS  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWFB_subwfb_0x37_coma_F_coma_BANKED_expect_0x5b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,F,BANKED  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWFB_subwfb_0x37_coma_F_coma_1_expect_0x5b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,F,1  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBWFB_subwfb_0x37_coma_1_coma_1_expect_0x5b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,1,1  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SBWFWB_sbufwb_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sbUfWb    ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SBUFWB"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//

	Try {
		subwfb(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SUBWFB_subwfb_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb      ";
	IdentifierToken subwfbToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"SUBWFB"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//
	Try {
 		subwfb(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SUBFWB_subfwb_0x37_coma_WREG_coma_0_expect_0x5437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFWb  0x37,WREG,0  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subfwb_0x37_coma_WREG_coma_ACCESS_expect_0x5437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFWb  0x37,WREG,ACCESS  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subfwb_0x37_coma_WREG_coma_BANKED_expect_0x5537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,WREG,BANKED  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subfwb_0x37_coma_F_coma_ACCESS_expect_0x5637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,F,ACCESS  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subfwb_0x37_coma_F_coma_BANKED_expect_0x5737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,F,BANKED  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subfwb_0x37_coma_F_coma_1_expect_0x5737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,F,1  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subfwb_0x37_coma_1_coma_1_expect_0x5737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,1,1  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SUBFWB_subbfw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sUbBfW    ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SUBBFW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//

	Try {
		subfwb(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SUBFWB_subfwb_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb      ";
	IdentifierToken subfwbToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"SUBFWB"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//
	Try {
 		subfwb(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_SWAPF_swapf_0x37_coma_WREG_coma_0_expect_0x3837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,WREG,0  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swapf_0x37_coma_WREG_coma_ACCESS_expect_0x3837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,WREG,ACCESS  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swapf_0x37_coma_WREG_coma_BANKED_expect_0x3937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,WREG,BANKED  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swapf_0x37_coma_F_coma_ACCESS_expect_0x3a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,F,ACCESS  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swapf_0x37_coma_F_coma_BANKED_expect_0x3b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,F,BANKED  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swapf_0x37_coma_F_coma_1_expect_0x3b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,F,1  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swapf_0x37_coma_1_coma_1_expect_0x3b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,F,1  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_SWAPF_swafp_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sWafP    ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"SWAFP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//

	Try {
		swapf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_SWAPF_swapf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF      ";
	IdentifierToken swapfToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"SWAPF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//
	Try {
 		swapf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TBLRD_tblrd_star_expect_0x0008(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd*  ";
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,instr,"*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLDR_tbldr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR    ";
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLDR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//

	Try {
		tblrd_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrdstar_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd      ";
	IdentifierToken tblrdToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"TBLRD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	Try {
 		tblrd_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_minus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd-  ";
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,instr,"-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblrd_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_star_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd*      ";
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,1,instr,"*"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblrd_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TBLRD_tblrd_star_plus_expect_0x0009(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd*+  ";
	IdentifierToken tblrd_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"*+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star_plus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLDR_tbldr_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR#    ";
	IdentifierToken tblrd_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TBLDR#"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_plusToken);//

	Try {
		tblrd_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_starplus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd      ";
	IdentifierToken tblrdToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"TBLRD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	Try {
 		tblrd_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_minus_minus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd--  ";
	IdentifierToken tblrdToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"--"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblrd_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_star_plus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd*+      ";
	IdentifierToken tblrd_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,2,instr,"*+"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblrd_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TBLRD_tblrd_star_minus_expect_0x000a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd*-  ";
	IdentifierToken tblrd_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"*-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star_minus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLDR_tbldr_hashtag_star_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR#*    ";
	IdentifierToken tblrd_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,7,instr,"TBLDR#*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_minusToken);//

	Try {
		tblrd_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_starminus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd      ";
	IdentifierToken tblrdToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"TBLRD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	Try {
 		tblrd_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_minus_plus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd-+  ";
	IdentifierToken tblrdToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"-+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblrd_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_star_minus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd*-      ";
	IdentifierToken tblrdToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,2,instr,"*-"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblrd_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
		TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
	}
	freeException(ex);
}

void test_TBLRD_tblrd_plus_star_expect_0x000b(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd+*  ";
	IdentifierToken tblrd_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"+*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_plus_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_plus_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLDR_tbldr_hashtag_minus_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR#-    ";
	IdentifierToken tblrdToken = {TOKEN_IDENTIFIER_TYPE, 3,7,instr,"TBLDR#-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	Try {
		tblrd_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_plusstar_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd      ";
	IdentifierToken tblrdToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"TBLRD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	Try {
 		tblrd_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_plus_minus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd+-  ";
	IdentifierToken tblrdToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"+-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblrd_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLRD_tblrd_plus_star_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlRd*+      ";
	IdentifierToken tblrdToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLRD"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,2,instr,"*+"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrdToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblrd_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void xtest_TBLWT_tblwt_star_expect_0x000c(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT*  ";
	IdentifierToken tblwt_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,instr,"*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void xtest_TBLWT_tbwtl_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl    ";
	IdentifierToken tblwt_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBWTL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_starToken);//

	Try {
		tblwt_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tbwtlstar_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlWt      ";
	IdentifierToken tbwtlToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"TBLWT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tbwtlToken);//
	Try {
 		tblwt_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void xtest_TBLWT_tbwtl_minus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tBlWt-  ";
	IdentifierToken tbwtlToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,instr,"-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tbwtlToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblwt_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tbwtl_star_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tBlWt*      ";
	IdentifierToken tbwtlToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,1,instr,"*"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tbwtlToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblwt_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TBLWT_tblwt_star_plus_expect_0x000d(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT*+  ";
	IdentifierToken tblwt_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"*+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star_plus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLWT_tbwtl_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl#    ";
	IdentifierToken tblwt_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TBWTL#"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_plusToken);//
	Try {
		tblwt_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_starplus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tblwt      ";
	IdentifierToken tblwtToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"TBLWT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	Try {
 		tblwt_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_minus_minus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblwt--  ";
	IdentifierToken tblwtToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"--"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblwt_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_star_plus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tblwt*+      ";
	IdentifierToken tblwtToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,2,instr,"*+"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblwt_star_plus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TBLWT_tblwt_star_minus_expect_0x000e(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT*-  ";
	IdentifierToken tblwt_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"*-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star_minus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLWT_tbwtl_hashtag_minus_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl#-    ";
	IdentifierToken tblwt_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,7,instr,"TBWTL#-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_minusToken);//

	Try {
		tblwt_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_starminus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tblwt      ";
	IdentifierToken tblwtToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"TBLWT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	Try {
 		tblwt_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_minus_plus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblwt-+  ";
	IdentifierToken tblwtToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"-+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblwt_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_star_minus_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tblwt*-      ";
	IdentifierToken tblwtToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,2,instr,"*-"};
	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblwt_star_minus(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TBLWT_tblwt_plus_star_expect_0x000f(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT+*  ";
	IdentifierToken tblwt_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"+*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_plus_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_plus_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TBLWT_tbwtl_minus_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl-#    ";
	IdentifierToken tblwt_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TBWTL-#"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_plus_starToken);//

	Try {
		tblwt_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwtL_plusstar_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tblwt      ";
	IdentifierToken tblwtToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"TBLWT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	Try {
 		tblwt_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_plus_minus_expect_NOT_VALID_OPERATOR(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblwt+-  ";
	IdentifierToken tblwtToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,instr,"+-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		tblwt_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TBLWT_tblwt_plus_star_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tblwt*+      ";
	IdentifierToken tblwtToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"TBLWT"};
	OperatorToken opToken = {TOKEN_IDENTIFIER_TYPE,8,2,instr,"*+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//
	Try {
 		tblwt_plus_star(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_TSTFSZ_tstfsz_0x37_coma_0_expect_0x6637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tstfsz   0x37,0  ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TSTFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TSTFSZ_tstfsz_0x37_coma_ACCESS_expect_0x6637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tstfsz   0x37,ACCESS  ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TSTFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TSTFSZ_tstfsz_0x37_coma_BANKED_expect_0x6737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tstfsz   0x37,BANKED  ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TSTFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TSTFSZ_tstfsz_0x37_coma_1_expect_0x6737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tstfsz   0x37,1  ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TSTFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_TSTFSZ_tstfzs_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TstFzS    ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,instr,"TSTFZS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//

	Try {
		tstfsz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_TSTFZS_tstfzs_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   tstfsz      ";
	IdentifierToken tstfszToken = {TOKEN_OPERATOR_TYPE, 3,6,instr,"TSTFSZ"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	Try {
 		tstfsz(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_XORLW_xorlw_0x37_expect_0x0a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   xOrLw   0x37  ";
	IdentifierToken xorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = xorlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORLW_xorwl_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   XoRwl    ";
	IdentifierToken xorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//

	Try {
		xorlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_XORLW_xorlw_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xorlw      ";
	IdentifierToken xorlwToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"XORLW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//
	Try {
 		xorlw(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_XORWF_xorwf_0x37_coma_WREG_coma_0_expect_0x1837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,WREG,0  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,1,instr,"0"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_xorwf_0x37_coma_WREG_coma_ACCESS_expect_0x1837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,WREG,ACCESS  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_xorwf_0x37_coma_WREG_coma_BANKED_expect_0x1937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,WREG,BANKED  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_xorwf_0x37_coma_F_coma_ACCESS_expect_0x1a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,f,ACCESS  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_xorwf_0x37_coma_F_coma_BANKED_expect_1b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,f,BaNkEd  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,instr,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_xorwf_0x37_coma_F_coma_1_expect_1b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,f,1  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_xorwf_0x37_coma_1_coma_1_expect_1b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,1,1  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,instr,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,instr,"1"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,instr,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,1,instr,"1"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&FToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
}
void test_XORWF_HASHTAG_tbwtl_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   XORWU    ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,instr,"XORWU"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//

	Try {
		xorwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_XORWF_xorwf_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xorwf      ";
	IdentifierToken xorwfToken = {TOKEN_OPERATOR_TYPE, 3,5,instr,"XORWF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//
	Try {
 		xorwf(instr);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
