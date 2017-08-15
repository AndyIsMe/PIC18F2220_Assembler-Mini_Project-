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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
