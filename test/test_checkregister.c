#include "unity.h"
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

void xtest_checkregister_0x37_WREG_ACCESS(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"ACCESS"};

  //getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    fda(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1," "};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);



  Try {
    fda(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_WREG(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,"WREG"};


  //getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);


  Try {
    fda(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_WREG_BANKED(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 12,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 13,6,"BANKED"};

  //getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    fda(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_4_ACCESS(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 8,1,"4"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 9,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 10,6,"ACCESS"};

  //getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    fba(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_4_BANKED(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 8,1,"4"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 9,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 10,6,"BANKED"};

  //getToken_ExpectAndReturn(tokenizer, (Token *)&addwfToken);//
  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);

  Try {
    fba(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_ACCESS(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 8,4,"ACCESS"};



  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);


  Try {
    fa(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_BANKED(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IdentifierToken BANKEDToken = {TOKEN_IDENTIFIER_TYPE, 8,4,"BANKED"};



  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&BANKEDToken);


  Try {
    fa(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x37_0x123(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE, 8,5,"0x123",0x123};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);


  Try {
    ff(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_0x40_(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x40",0x40};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//



  Try {
    k(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void test_checkregister_0x40_1_(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,"0x40",0x40};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE,7,1,","};
  IntegerToken int1Token = {TOKEN_INTEGER_TYPE,8,1,"1",1};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);



  Try {
    ks(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}

void xtest_checkregister_1_(void)
{
  CEXCEPTION_T ex;
  OperandInfo operandInfo;

  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,1,1,"1",1};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);



  Try {
    handleS(tokenizer ,operandInfo);

  }Catch(ex) {
    TEST_ASSERT_EQUAL(EXTRA_OPERAND, ex);
  }
}
