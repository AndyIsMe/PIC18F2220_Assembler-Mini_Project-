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

void tearDown(void){}

void xtest_ADDLW_addlw_0x37_expect_0x0f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aDdLw   0x37  ";
	IdentifierToken addlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = addlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_ADDMW_addmw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDvF    ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDvF"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_ADDWF_addwf_0x37_coma_WREG_coma_ACCESS_expect_0x2437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,WREG,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ADDWF_addwf_0x37_coma_WREG_coma_BANKED_expect_0x2537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,WREG,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ADDWF_addwf_0x37_coma_F_coma_ACCESS_expect_0x2637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,f,ACCESS  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ADDWF_addwf_0x37_coma_F_coma_BANKED_expect_2737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwF   0x37,f,BaNkEd  ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_ADDvF_addvf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDvF    ";
	IdentifierToken addwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDvF"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//

	Try {
		machineCode = addwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}


void xtest_ADDWFC_addwfc_0x37_coma_WREG_coma_ACCESS_expect_0x2037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc   0x37,WREG,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ADDWFC_addwfc_0x37_coma_WREG_coma_BANKED_expect_0x2137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc   0x37,WREG,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ADDWFC_addwfc_0x37_coma_F_coma_ACCESS_expect_0x2237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc  0x37,f,ACCESS  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ADDWFC_addwfc_0x37_coma_F_coma_BANKED_expect_2337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwFc  0x37,f,BaNkEd  ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWFC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_ADDWDF_addwdf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AdDwdF    ";
	IdentifierToken addwfcToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ADDWDF"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&addwfcToken);//

	Try {
		machineCode = addwfc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_ANDLW_addlw_0x37_expect_0xf37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   aNdLw   0x37  ";
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = andlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_ANDWW_anddw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ANDwW    ";
	IdentifierToken andlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andlwToken);//

	Try {
		machineCode = andlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_ANDWF_andwf_0x37_coma_WREG_coma_ACCESS_expect_0x1437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDwF   0x37,WREG,ACCESS  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ANDWF_andwf_0x37_coma_WREG_coma_BANKED_expect_0x1537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDwF   0x37,WREG,ACCESS  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ANDWF_andwf_0x37_coma_F_coma_ACCESS_expect_0x1637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDwF   0x37,f,ACCESS  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_ANDWF_andwf_0x37_coma_F_coma_BANKED_expect_1737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   AnDwF   0x37,f,BaNkEd  ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_ANDDW_anddw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ANDdW    ";
	IdentifierToken andwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"ANDDW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&andwfToken);//

	Try {
		machineCode = andwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BC_bc_0x37_expect_0xe21a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bC   0x37  ";
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"BC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BS_bs_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bs    ";
	IdentifierToken bcToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"Bs"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcToken);//

	Try {
		machineCode = bc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BN_bn_0x37_expect_0xe61a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bN   0x37  ";
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"BN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BD_bd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bd    ";
	IdentifierToken bnToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"BD"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnToken);//

	Try {
		machineCode = bn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BNC_bnc_0x37_expect_0xe31a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNC   0x37  ";
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BNC"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BC_bc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bc    ";
	IdentifierToken bncToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"BC"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bncToken);//

	Try {
		machineCode = bnc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BNN_bnn_0x37_expect_0xe71a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNN   0x37  ";
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BNN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BNM_bnm_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bnm    ";
	IdentifierToken bnnToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BNM"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnnToken);//

	Try {
		machineCode = bnn(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BNOV_bnov_0x37_expect_0xe51a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNoV   0x37  ";
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"BNOV"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BNOW_bnow_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BnoW    ";
	IdentifierToken bnovToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"BNOW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnovToken);//

	Try {
		machineCode = bnov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BNZ_bnz_0x37_expect_0xe11a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bNZ   0x37  ";
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BNX_bnx_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bnx    ";
	IdentifierToken bnzToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BNX"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bnzToken);//

	Try {
		machineCode = bnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BOV_bov_0x37_expect_0xe41a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   boV   0x37  ";
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BOV"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BOW_bow_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bow    ";
	IdentifierToken bovToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BOW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bovToken);//

	Try {
		machineCode = bov(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BRA_bra_0x37_expect_0xdo1ad7ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA   0x37  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BRA"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_BRA_bra_0x1_expect_0xd7ffd7ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   brA   0x1  ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BRA"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,3,"0x1",0x1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BRB_brb_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Brb    ";
	IdentifierToken braToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BRB"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&braToken);//

	Try {
		machineCode = bra(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BZ_bz_0x37_expect_0xe01a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   bZ   0x37  ";
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"BZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = bz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_BA_ba_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Ba    ";
	IdentifierToken bzToken = {TOKEN_IDENTIFIER_TYPE, 3,2,"BA"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bzToken);//

	Try {
		machineCode = bz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BCF_bcf_0x37_4_ACCESS_expect_0x9837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,6,ACCESS  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,"ACCESS"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void xtest_BCF_bcf_0x37_4_BANKED_expect_0x9937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bCf   0x37,4,BANKED  ";
  IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE,3,3,"BCF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,"BANKED"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_BCD_bcd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BcD    ";
	IdentifierToken bcfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BCD"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bcfToken);//

	Try {
		machineCode = bcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BSF_bsf_0x37_4_ACCESS_expect_0x8837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,6,ACCESS  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,"ACCESS"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void xtest_BSF_bsf_0x37_4_BANKED_expect_0x8937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bSf   0x37,4,BANKED  ";
  IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE,3,3,"BSF"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,"BANKED"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_BSD_bsd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BsD    ";
	IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BSD"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//

	Try {
		machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BTFSC_btfsc_0x37_4_ACCESS_expect_0xb837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsc   0x37,6,ACCESS  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void xtest_BTFSC_bsfsc_0x37_4_BANKED_expect_0xb937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSC   0x37,4,BANKED  ";
  IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE,3,5,"BTFSC"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_BRBBF_brbbf_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BrbbF    ";
	IdentifierToken btfscToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"BRBBF"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfscToken);//

	Try {
		machineCode = btfsc(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BTFSS_btfss_0x37_4_ACCESS_expect_0xa837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   bTfsS   0x37,6,ACCESS  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void xtest_BTFSS_btfss_0x37_4_BANKED_expect_0xa937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btfSS   0x37,4,BANKED  ";
  IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE,3,5,"BTFSS"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 16,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_BTFSE_btfse_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   BtFSe    ";
	IdentifierToken btfssToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"BTFSE"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btfssToken);//

	Try {
		machineCode = btfss(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BTG_btg_0x37_4_ACCESS_expect_0x7837(void){
  CEXCEPTION_T ex;
  int machineCode;
  //OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,4,ACCESS  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 16,6,"ACCESS"};

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
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_BTT_btt_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Btt    ";
	IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BTT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);//

	Try {
		machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_BSF_bsf_0x37_4_BANKED_expect_0x7937(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  int machineCode;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   btG   0x37,4,BANKED  ";
  IdentifierToken btgToken = {TOKEN_IDENTIFIER_TYPE,3,3,"BTG"};
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,9,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,1,"4",4};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 16,6,"BANKED"};

  initTokenizer_ExpectAndReturn(instr,tokenizer);
  getToken_ExpectAndReturn(tokenizer, (Token *)&btgToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    machineCode = btg(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
void test_BSR_bsr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Bsr    ";
	IdentifierToken bsfToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"BSR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&bsfToken);//

	Try {
		machineCode = bsf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_CALL_call_0xbff_coma_1_expect_0xedfff005(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xbff,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,"0xbff",0xbff};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,15,1,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,16,1,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CALL_call_0xfe_coma_1_expect_0xed7ff000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xfe,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0xfe",0xfe};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,14,1,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,15,1,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CALL_call_0xf_coma_1_expect_0xed07f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0xf,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0xf",0xf};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,14,1,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CALL_call_0x0_coma_1_expect_0xed00f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cAlL   0x0,1  ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CALL"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x0",0x0};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,13,1,","};
	IntegerToken int1Token = {TOKEN_INTEGER_TYPE,14,1,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);
	getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_CALR_calr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CaLr    ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CALR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_CLRF_clrf_0x37_coma_ACCESS_expect_0x6a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF   0x37,ACCESS  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CLRF_clrf_0x37_coma_BANKED_expect_0x6b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cLrF   0x37,BANKED  ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CLRF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 12,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_CLRR_clrr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CLrr    ";
	IdentifierToken clrfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"CLRR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrfToken);//

	Try {
		machineCode = clrf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_CLRWDT__clrwdt_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   cLrWDt  ";
	IdentifierToken clrwdtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CLRWDT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrwdtToken);//

	Try {
		machineCode = clrwdt(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_CLRWED_clrwed_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CLrwEd    ";
	IdentifierToken clrwdtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CLRWED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&clrwdtToken);//

	Try {
		machineCode = clrwdt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_COMF_comf_0x37_coma_WREG_coma_ACCESS_expect_0x1c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,WREG,ACCESS  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_COMF_comf_0x37_coma_WREG_coma_BANKED_expect_0x1d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,WREG,BANKED  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_COMF_comf_0x37_coma_F_coma_ACCESS_expect_0x1e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,F,ACCESS  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_COMF_comf_0x37_coma_WREG_coma_BANKED_expect_0x1f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cOmF    0x37,F,BANKED  ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"COMF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_COME_come_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CoME    ";
	IdentifierToken comfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"COME"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&comfToken);//

	Try {
		machineCode = comf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_CPFSEQ_cpfseq_0x37_coma_ACCESS_expect_0x6237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsEq   0x37,ACCESS  ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSEQ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CPFSEQ_cpfseq_0x37_coma_BANKED_expect_0x6337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSEq   0x37,BANKED  ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSEQ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_CPFSEF_cpfsef_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CpFSef    ";
	IdentifierToken cpfseqToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSEF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfseqToken);//

	Try {
		machineCode = cpfseq(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_CPFSGT_cpfsgt_0x37_coma_ACCESS_expect_0x6437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsGt   0x37,ACCESS  ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSGT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CPFSGT_cpfsgt_0x37_coma_BANKED_expect_0x6537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSGt   0x37,BANKED  ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSGT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_CPFSGD_cpfsgd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CpFsGd    ";
	IdentifierToken cpfsgtToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSGD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsgtToken);//

	Try {
		machineCode = cpfsgt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_CPFSLT_cpfslt_0x37_coma_ACCESS_expect_0x6037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPFsLt   0x37,ACCESS  ";
	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSLT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_CPFSLT_cpfslt_0x37_coma_BANKED_expect_0x6137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   cPfSLt   0x37,BANKED  ";
	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPFSLT"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_CPFSLD_cpfsld_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   CPlSlD    ";
	IdentifierToken cpfsltToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"CPLSLD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&cpfsltToken);//

	Try {
		machineCode = cpfslt(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_DAW_daw_expect_0x0007(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   daW     ";
	IdentifierToken dawToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"DAW"};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dawToken);//


	Try {
		machineCode = daw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_DAE_dae_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DaE    ";
	IdentifierToken dawToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"DAE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dawToken);//

	Try {
		machineCode = daw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_DECF_decf_0x37_coma_WREG_coma_ACCESS_expect_0x0437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,WREG,ACCESS  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DECF_decf_0x37_coma_WREG_coma_BANKED_expect_0x0537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,WREG,BANKED  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DECF_decf_0x37_coma_F_coma_ACCESS_expect_0x0637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,F,ACCESS  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DECF_decf_0x37_coma_F_coma_BANKED_expect_0x0737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcF    0x37,F,BANKED  ";
	IdentifierToken decfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"DECF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_DECD_decd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DeCd    ";
	IdentifierToken callToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"DECD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&callToken);//

	Try {
		machineCode = call(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_DECFSZ_decfsz_0x37_coma_WREG_coma_ACCESS_expect_0x2c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,WREG,ACCESS  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DECFSZ_decfsz_0x37_coma_WREG_coma_BANKED_expect_0x2d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,WREG,BANKED  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DECFSZ_decfsz_0x37_coma_F_coma_ACCESS_expect_0x2e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,F,ACCESS  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DECFSZ_decfsz_0x37_coma_F_coma_BANKED_expect_0x2f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dEcFsZ  0x37,F,BANKED  ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DECFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_DECFSD_decfsd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DeCFsd    ";
	IdentifierToken decfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DECFSD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&decfszToken);//

	Try {
		machineCode = decfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_DCFSNZ_dcfsnz_0x37_coma_WREG_coma_ACCESS_expect_0x4c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dcFsnZ  0x37,WREG,ACCESS  ";
	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DCFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DCFSNZ_dcfsnz_0x37_coma_WREG_coma_BANKED_expect_0x4d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dcFsnZ  0x37,WREG,BANKED  ";
	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DCFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DCFSNZ_dcfsnz_0x37_coma_F_coma_ACCESS_expect_0x4e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dcFsnZ  0x37,F,ACCESS  ";
	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DCFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_DCFSNZ_dcfsnz_0x37_coma_F_coma_BANKED_expect_0x4f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   dcFsnZ  0x37,F,BANKED  ";
	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DCFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_DCFSND_dcfsnd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   DCFsNd    ";
	IdentifierToken dcfsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"DCFSND"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&dcfsnzToken);//

	Try {
		machineCode = dcfsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_GOTO_goto_0xbff_expect_0xeffff005(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0xbff  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,5,"0xbff",0xbff};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//


	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_GOTO_goto_0xfe_expect_0xef7ff000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0xfe  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0xfe",0xfe};


	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_GOTO_goto_0xf_expect_0xef07f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0xf  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0xf",0xf};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_GOTO_goto_0x0_expect_0xef00f000(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   goTO   0x0  ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"GOTO"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x0",0x0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_GOtD_gotd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   gOtD    ";
	IdentifierToken gotoToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"GOTD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&gotoToken);//

	Try {
		machineCode = _goto(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_INCF_incf_0x37_coma_WREG_coma_ACCESS_expect_0x2837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   incF    0x37,WREG,ACCESS  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INCF_incf_0x37_coma_WREG_coma_BANKED_expect_0x2937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   IncF    0x37,WREG,BANKED  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INCF_incf_0x37_coma_F_coma_ACCESS_expect_0x2a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcF    0x37,F,ACCESS  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INCF_incf_0x37_coma_F_coma_BANKED_expect_0x2b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcF    0x37,F,BANKED  ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"INCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_INFE_infe_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNfE    ";
	IdentifierToken incfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"INFE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfToken);//

	Try {
		machineCode = incf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_INCFSZ_incfsz_0x37_coma_WREG_coma_ACCESS_expect_0x3c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,WREG,ACCESS  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_WREG_coma_BANKED_expect_0x3d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,WREG,BANKED  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_F_coma_ACCESS_expect_0x3e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,F,ACCESS  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INCFSZ_incfsz_0x37_coma_F_coma_BANKED_expect_0x3f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcFsZ  0x37,F,BANKED  ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INCFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_INCFEC_incfec_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNcfEC    ";
	IdentifierToken incfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INCFEC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&incfszToken);//

	Try {
		machineCode = incfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_INFSNZ_infsnz_0x37_coma_WREG_coma_ACCESS_expect_0x4837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,WREG,ACCESS  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_WREG_coma_BANKED_expect_0x4937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,WREG,BANKED  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_F_coma_ACCESS_expect_0x4a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,F,ACCESS  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_INFSNZ_infsnz_0x37_coma_F_coma_BANKED_expect_0x4b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   inFsnZ  0x37,F,BANKED  ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INFSNZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_INFSNC_infsnc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iNfsNC    ";
	IdentifierToken infsnzToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"INFSNC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&infsnzToken);//

	Try {
		machineCode = infsnz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_IORLW_iorlw_0x37_expect_0x0937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   IoRLw   0x37  ";
	IdentifierToken iorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"IORLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

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
void test_IORLE_iorle_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   iOrLe    ";
	IdentifierToken iorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"IORLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&iorlwToken);//

	Try {
		machineCode = iorlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void test_MOVLB_movlb_0x9_expect_0x0109(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   MoVLb   0x9  ";
	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVLB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,"0x9",0x9};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = movlb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MOVLB_movlb_0xff_expect_0x010f(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   MoVLb   0xf9  ";
	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVLB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,3,"0xf9",0xf9};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = movlb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MVOLE_mvole_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mVoLe    ";
	IdentifierToken movlbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MVOLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlbToken);//

	Try {
		machineCode = movlb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_MOVLW_movlw_0x37_expect_0x0e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   MoVLw   0x37  ";
	IdentifierToken movlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = movlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MOVLD_movld_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvLD    ";
	IdentifierToken movlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVLD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movlwToken);//

	Try {
		machineCode = movlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_MOVWF_movwf_0x37_coma_ACCESS_expect_0x6e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVwF   0x37,ACCESS  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = movwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MOVWR_movwr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvwR    ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVWR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//

	Try {
		machineCode = movwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_MOVF_movf_0x37_coma_WREG_coma_ACCESS_expect_0x5037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,WREG,ACCESS  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_MOVF_movf_0x37_coma_WREG_coma_BANKED_expect_0x5137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,WREG,BANKED  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_MOVF_movf_0x37_coma_F_coma_ACCESS_expect_0x5237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,F,ACCESS  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_MOVF_movf_0x37_coma_F_coma_BANKED_expect_0x5337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvF   0x37,F,BANKED  ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MOVD_movd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvD    ";
	IdentifierToken movfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"MOVD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movfToken);//

	Try {
		machineCode = movf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void test_MOVFF_movff_0x222_coma_movff_0xff_expect_0xc222_0xf0ff(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MoVfF   0x222,0xff  ";
	IdentifierToken movwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVFF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,5,"0x222",0x222};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 13,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 14,4,"0xff",0xff};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);

	Try {
		machineCode = movff(instr);
		printf("\nthe instruction[   %s   ] opcode is %#8x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MOVFT_movft_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mOvfT    ";
	IdentifierToken movffToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MOVFT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&movffToken);//

	Try {
		machineCode = movff(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_MULLW_mullw_0x37_expect_0x0d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   mUlLw   0x37  ";
	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MULLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = mullw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MULLD_mulld_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   mulLD    ";
	IdentifierToken mullwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MULLD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mullwToken);//

	Try {
		machineCode = mullw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_MULWF_mulwf_0x37_coma_ACCESS_expect_0x0237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MuLWf   0x37,ACCESS  ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MULWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_MULWF_mulwf_0x37_coma_BANKED_expect_0x0337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   MuLWf   0x37,BANKED  ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MULWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_MULLE_mulle_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   muLLe    ";
	IdentifierToken mulwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"MULLE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&mulwfToken);//

	Try {
		machineCode = mulwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_NEGF_negf_0x37_coma_ACCESS_expect_0x6c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Negf   0x37,ACCESS  ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"NEGF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_NEGF_negf_0x37_coma_BANKED_expect_0x6d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Negf   0x37,BANKED  ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"NEGF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_NEGD_negd_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   nEGD    ";
	IdentifierToken negfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"NEGD"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&negfToken);//

	Try {
		machineCode = negf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_POP_pop_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   PoP  ";
	IdentifierToken popToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"POP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//

	Try {
		machineCode = pop(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_POF_pof_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   poF    ";
	IdentifierToken popToken = {TOKEN_IDENTIFIER_TYPE, 3,3,"POF"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&popToken);//

	Try {
		machineCode = pop(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_PUSH_push_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   PUSH  ";
	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"PUSH"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//

	Try {
		machineCode = push(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_PUHS_puhs_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   pUhS    ";
	IdentifierToken pushToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"PUHS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&pushToken);//

	Try {
		machineCode = push(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_RESET_reset_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   RESET  ";
	IdentifierToken resetToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RESET"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//

	Try {
		machineCode = reset(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RESTE_reste_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReSTe    ";
	IdentifierToken resetToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RESTE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&resetToken);//

	Try {
		machineCode = reset(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void test_RETFIE_retfie_0_expect_0x0010(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rEtFIE   0  ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETFIE"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0",0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RETFIE_retfie_1_expect_0x0011(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rEtFIE   1  ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETFIE"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RETFIE_retfie_2_expect_0x0010(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rEtFIE   2  ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETFIE"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"2",2};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RETFEI_retfei_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   ReTFei    ";
	IdentifierToken retfieToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETFEI"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&retfieToken);//

	Try {
		machineCode = retfie(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void test_RETURN_return_0_expect_0x0012(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rETuRn   0  ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETURN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0",0};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RETURN_return_1_expect_0x0013(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rETuRn   1  ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETURN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"1",1};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RETURN_return_2_expect_0x0012(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   rETuRn   2  ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"RETURN"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"2",2};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RETUNR_retunr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   REtunr    ";
	IdentifierToken returnToken = {TOKEN_IDENTIFIER_TYPE,3 ,6,"RETUNR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&returnToken);//

	Try {
		machineCode = _return(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_RLCF_rlcf_0x37_coma_WREG_coma_ACCESS_expect_0x3437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,WREG,ACCESS  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RLCF_rlcf_0x37_coma_WREG_coma_BANKED_expect_0x3537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,WREG,BANKED  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RLCF_rlcf_0x37_coma_F_coma_ACCESS_expect_0x3637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,F,ACCESS  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RLCF_rlcf_0x37_coma_F_coma_BANKED_expect_0x3737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlcF    0x37,F,BANKED  ";
	IdentifierToken rlcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RLCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RLFC_rlfc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RLfC    ";
	IdentifierToken rlfcToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RLFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlfcToken);//

	Try {
		machineCode = rlcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_RLNCF_rlncf_0x37_coma_WREG_coma_ACCESS_expect_0x4437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,WREG,ACCESS  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_WREG_coma_BANKED_expect_0x4537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,WREG,BANKED  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_F_coma_ACCESS_expect_0x4637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,F,ACCESS  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RLNCF_rlncf_0x37_coma_F_coma_BANKED_expect_0x4737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RlncF   0x37,F,BANKED  ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RLNCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RLNFC_rlnfc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RLnfC    ";
	IdentifierToken rlncfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"RLNFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rlncfToken);//

	Try {
		machineCode = rlncf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_RRCF_rrcf_0x37_coma_WREG_coma_ACCESS_expect_0x3037(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,WREG,ACCESS  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RRCF_rrcf_0x37_coma_WREG_coma_BANKED_expect_0x3137(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,WREG,BANKED  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RRCF_rrcf_0x37_coma_F_coma_ACCESS_expect_0x3237(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,F,ACCESS  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_RRCF_rrcf_0x37_coma_F_coma_BANKED_expect_0x3337(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrcF    0x37,F,BANKED  ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RRCF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_RRFC_rrfc_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   RrFc    ";
	IdentifierToken rrcfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"RRFC"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&rrcfToken);//

	Try {
		machineCode = rrcf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SETF_setf_0x37_coma_ACCESS_expect_0x6837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Setf   0x37,ACCESS  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,10,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 11,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 12,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SETF_setf_0x37_coma_BANKED_expect_0x6937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   Setf   0x37,BANKED  ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SETF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SEFT_seft_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SEfT    ";
	IdentifierToken setfToken = {TOKEN_IDENTIFIER_TYPE, 3,4,"SEFT"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&setfToken);//

	Try {
		machineCode = setf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SLEEP_sleep_expect_exception(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   SLEEP  ";
	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SLEEP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//

	Try {
		machineCode = sleep(instr);
		printf("\nthe instruction opcode is %#4x",machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SLEPE_slepe_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SlEpe    ";
	IdentifierToken sleepToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SLEPE"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sleepToken);//

	Try {
		machineCode = sleep(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SUBLW_sublw_0x37_expect_0x0837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   SuBLw   0x37  ";
	IdentifierToken sublwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = sublw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SUBWL_subwl_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwl    ";
	IdentifierToken sublwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBWL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&sublwToken);//

	Try {
		machineCode = sublw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SUBWF_subwf_0x37_coma_WREG_coma_ACCESS_expect_0x5c37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,WREG,ACCESS  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBWF_subwf_0x37_coma_WREG_coma_BANKED_expect_0x5d37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,WREG,BANKED  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBWF_subwf_0x37_coma_F_coma_ACCESS_expect_0x5e37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,F,ACCESS  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBWF_subwf_0x37_coma_F_coma_BANKED_expect_0x5f37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwF   0x37,F,BANKED  ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SBUFW_sbufw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sbUfW    ";
	IdentifierToken subwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SBUFW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfToken);//

	Try {
		machineCode = subwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SUBWFB_subwfb_0x37_coma_WREG_coma_ACCESS_expect_0x5837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,WREG,ACCESS  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBWFB_subwfb_0x37_coma_WREG_coma_BANKED_expect_0x5937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,WREG,BANKED  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBWFB_subwfb_0x37_coma_F_coma_ACCESS_expect_0x5a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,F,ACCESS  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBWFB_subwfb_0x37_coma_F_coma_BANKED_expect_0x5b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBwFb  0x37,F,BANKED  ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SUBWFB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SBUFWB_sbufwb_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sbUfWb    ";
	IdentifierToken subwfbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SBUFWB"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subwfbToken);//

	Try {
		machineCode = subwfb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SUBFWB_subfwb_0x37_coma_WREG_coma_ACCESS_expect_0x5437(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFWb  0x37,WREG,ACCESS  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBFWB_subfwb_0x37_coma_WREG_coma_BANKED_expect_0x5537(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,WREG,BANKED  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBFWB_subfwb_0x37_coma_F_coma_ACCESS_expect_0x5637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,F,ACCESS  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,1,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SUBFWB_subfwb_0x37_coma_F_coma_BANKED_expect_0x5737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SuBFwb  0x37,F,BANKED  ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"SUBFWB"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SUBBFW_subbfw_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sUbBfW    ";
	IdentifierToken subfwbToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SUBBFW"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&subfwbToken);//

	Try {
		machineCode = subfwb(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_SWAPF_swapf_0x37_coma_WREG_coma_ACCESS_expect_0x3837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,WREG,ACCESS  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SWAPF_swapf_0x37_coma_WREG_coma_BANKED_expect_0x3937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,WREG,BANKED  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SWAPF_swapf_0x37_coma_F_coma_ACCESS_expect_0x3a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,F,ACCESS  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_SWAPF_swapf_0x37_coma_F_coma_BANKED_expect_0x3b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   SwApF   0x37,F,BANKED  ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SWAPF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_SWAFP_swafp_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   sWafP    ";
	IdentifierToken swapfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"SWAFP"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&swapfToken);//

	Try {
		machineCode = swapf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLRD_STAR_tblrd_star_expect_0x0008(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd*  ";
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,"*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBLDR_tbldr_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR    ";
	IdentifierToken tblrd_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLDR"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_starToken);//

	Try {
		machineCode = tblrd_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLRD_STAR_PLUS_tblrd_star_plus_expect_0x0009(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd*+  ";
	IdentifierToken tblrd_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star_plus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBLDR_HASHTAG_tbldr_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR#    ";
	IdentifierToken tblrd_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"TBLDR#"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_plusToken);//

	Try {
		machineCode = tblrd_star_plus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLRD_STAR_MINUS_tblrd_star_minus_expect_0x000a(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd*-  ";
	IdentifierToken tblrd_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_star_minus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBLDR_HASHTAG_STAR_tbldr_hashtag_star_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR#*    ";
	IdentifierToken tblrd_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,7,"TBLDR#*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_star_minusToken);//

	Try {
		machineCode = tblrd_star_minus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLRD_PLUS_STAR_tblrd_plus_star_expect_0x000b(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tblrd+*  ";
	IdentifierToken tblrd_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLRD"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"+*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_plus_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblrd_plus_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBLDR_HASHTAG_MINUS_tbldr_hashtag_minus_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBlDR#-    ";
	IdentifierToken tblrd_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,7,"TBLDR#-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblrd_plus_starToken);//

	Try {
		machineCode = tblrd_plus_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLWT_STAR_tblwt_star_expect_0x000c(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT*  ";
	IdentifierToken tblwt_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,1,"*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBWTL_tbwtl_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl    ";
	IdentifierToken tblwt_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBWTL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_starToken);//

	Try {
		machineCode = tblwt_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLWT_STAR_PLUS_tblwt_star_plus_expect_0x000d(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT*+  ";
	IdentifierToken tblwt_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*+"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_plusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star_plus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBWTL_HASHTAG_tbwtl_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl#    ";
	IdentifierToken tblwt_star_plusToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"TBWTL#"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_plusToken);//

	Try {
		machineCode = tblwt_star_plus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLWT_STAR_MINUS_tblwt_star_minus_expect_0x000e(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT*-  ";
	IdentifierToken tblwt_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"*-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_minusToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_star_minus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBWTL_HASHTAG_MINUS_tbwtl_hashtag_minus_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl#-    ";
	IdentifierToken tblwt_star_minusToken = {TOKEN_IDENTIFIER_TYPE, 3,7,"TBWTL#-"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_star_minusToken);//

	Try {
		machineCode = tblwt_star_minus(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TBLWT_PLUS_STAR_tblwt_plus_star_expect_0x000f(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   TBLWT+*  ";
	IdentifierToken tblwt_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"TBLWT"};
	OperatorToken opToken = {TOKEN_OPERATOR_TYPE,8,2,"+*"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_plus_starToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&opToken);//

	Try {
		machineCode = tblwt_plus_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TBWTL_MINUS_HASHTAG_tbwtl_minus_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TBwtl-#    ";
	IdentifierToken tblwt_plus_starToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"TBWTL-#"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tblwt_plus_starToken);//

	Try {
		machineCode = tblwt_plus_star(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_TSTFSZ_tstfsz_0x37_coma_ACCESS_expect_0x6637(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tstfsz   0x37,ACCESS  ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"TSTFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"ACCESS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_TSTFSZ_tstfsz_0x37_coma_BANKED_expect_0x6737(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   tstfsz   0x37,BANKED  ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"TSTFSZ"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,12,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 16,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 17,6,"BANKED"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_TSTFZS_tstfzs_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   TstFzS    ";
	IdentifierToken tstfszToken = {TOKEN_IDENTIFIER_TYPE, 3,6,"TSTFZS"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&tstfszToken);//

	Try {
		machineCode = tstfsz(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void test_XORLW_xorlw_0x37_expect_0x0a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char instr[] = "   xOrLw   0x37  ";
	IdentifierToken xorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORLW"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//
	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		machineCode = xorlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_XORWL_xorwl_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   XoRwl    ";
	IdentifierToken xorlwToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORWL"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorlwToken);//

	Try {
		machineCode = xorlw(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}

void xtest_XORWF_xorwf_0x37_coma_WREG_coma_ACCESS_expect_0x1837(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,WREG,ACCESS  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_XORWF_xorwf_0x37_coma_WREG_coma_BANKED_expect_0x1937(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,WREG,BANKED  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 20,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 21,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_XORWF_xorwf_0x37_coma_F_coma_ACCESS_expect_0x1a37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,f,ACCESS  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"ACCESS"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void xtest_XORWF_xorwf_0x37_coma_F_coma_BANKED_expect_1b37(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   xOrwF   0x37,f,BaNkEd  ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORWF"};
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,11,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 15,1,","};
  IdentifierToken FToken = {TOKEN_IDENTIFIER_TYPE, 16,4,"F"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 17,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 18,6,"BANKED"};

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
		TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
	}
}
void test_XORWU_HASHTAG_tbwtl_hashtag_expect_NOT_VALID_IDENTIFIER(void){
	CEXCEPTION_T ex;
	int machineCode;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char instr[] = "   XORWU    ";
	IdentifierToken xorwfToken = {TOKEN_IDENTIFIER_TYPE, 3,5,"XORWU"};

	initTokenizer_ExpectAndReturn(instr,tokenizer);
	getToken_ExpectAndReturn(tokenizer, (Token *)&xorwfToken);//

	Try {
		machineCode = xorwf(instr);
		printf("\nthe instruction[   %s   ] opcode is %#4x",instr,machineCode);
	}Catch(ex) {
		TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER, ex);
	}
}
