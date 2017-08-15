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

  void test_TBLWT_tblwt_star_expect_0x000c(void){
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
  void test_TBLWT_tbwtl_expect_NOT_VALID_IDENTIFIER(void){
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
  	}
  	freeException(ex);
  }
  void test_TBLWT_tbwtl_minus_expect_NOT_VALID_OPERATOR(void){
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_IDENTIFIER,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
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
      TEST_ASSERT_EQUAL(NOT_VALID_OPERATOR,ex->errorCode);
  	}
  	freeException(ex);
  }
