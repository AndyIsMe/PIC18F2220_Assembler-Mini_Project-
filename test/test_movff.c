#include "unity.h"
#include "AssemblyCode.h"
#include "checkregister.h"
#include "mock_Tokenizer.h"
#include <stdio.h>
#include "Token.h"
#include "error.h"
#include "Exception.h"
#include "toupper.h"

void setUp(void)
{}

void tearDown(void)
{}
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
