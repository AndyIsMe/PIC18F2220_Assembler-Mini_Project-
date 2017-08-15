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

void test_fda_0xff1_expect_overflow_occur(void)
          {
            CEXCEPTION_T ex;
            OperandInfo operandInfo;
            Tokenizer *tokenizer = (Tokenizer *)0x0badface;
            char *instr = "   0xff1 ";
            IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,5,instr,"0xff1",0xff1};
            getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

            Try {
              fda(tokenizer ,&operandInfo);
            }Catch(ex) {
              dumpErrorMessage(ex, 1);
            }
            freeException(ex);
          }
void test_fda_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
        {
          CEXCEPTION_T ex;
          OperandInfo operandInfo;
          Tokenizer *tokenizer = (Tokenizer *)0x0badface;
          char *instr = "   0x37 ";
          IntegerToken intToken = {TOKEN_OPERATOR_TYPE,3,4,instr,"0x37",0x37};
          getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

          Try {
            fda(tokenizer ,&operandInfo);
          }Catch(ex) {
            dumpErrorMessage(ex, 1);
          }
          freeException(ex);
        }
void test_handleDirBank_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_INTEGER_TYPE, 7,1,instr,","};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

        Try {
          fda(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
      }
void test_handleDirBank_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,"."};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

        Try {
          fda(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
      }
void test_handleDirBank_0x37_coma_WREG_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
    {
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      char *instr = "   0x37,WREG, ";
      IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
      OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
      IdentifierToken WREGToken = {TOKEN_INTEGER_TYPE, 8,4,instr,"WREG"};

      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
      getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);

      Try {
        fda(tokenizer ,&operandInfo);
      }Catch(ex) {
        dumpErrorMessage(ex, 1);
      }
      freeException(ex);
    }
void test_handleDirBank_0x37_coma_D_expect_INVALID_IDENTIFIER_TYPE(void)
        {
          CEXCEPTION_T ex;
          OperandInfo operandInfo;
          Tokenizer *tokenizer = (Tokenizer *)0x0badface;
          char *instr = "   0x37,D ";
          IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
          OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
          IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,instr,"D"};

          getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
          getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
          getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);

          Try {
            fda(tokenizer ,&operandInfo);
          }Catch(ex) {
            dumpErrorMessage(ex, 1);
          }
          freeException(ex);
        }
void test_handleDirBank_0x37_coma_WREG_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
  {
    CEXCEPTION_T ex;
    OperandInfo operandInfo;
    Tokenizer *tokenizer = (Tokenizer *)0x0badface;
    char *instr = "   0x37,WREG, ";
    IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
    OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
    IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,instr,"WREG"};
    OperatorToken op1Token = {TOKEN_IDENTIFIER_TYPE, 12,1,instr,","};

    getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
    getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
    getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);

    Try {
      fda(tokenizer ,&operandInfo);
    }Catch(ex) {
      dumpErrorMessage(ex, 1);
    }
    freeException(ex);
  }
void test_handleDirBank_0x37_coma_WREG_fullstop__expect_INVALID_OPERATOR_TYPE(void)
    {
      CEXCEPTION_T ex;
      OperandInfo operandInfo;
      Tokenizer *tokenizer = (Tokenizer *)0x0badface;
      char *instr = "   0x37,WREG. ";
      IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
      OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
      IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,instr,"WREG"};
      OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 12,1,instr,"."};

      getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
      getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
      getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);

      Try {
        fda(tokenizer ,&operandInfo);
      }Catch(ex) {
        dumpErrorMessage(ex, 1);
      }
      freeException(ex);
    }
void test_handlebank_0x37_coma_WREG_coma_ACCESS_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *instr = "   0x37,WREG,ACCESS ";
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_OPERATOR_TYPE, 13,6,instr,"ACCESS"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    fda(tokenizer ,&operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
  freeException(ex);
}
void test_handlebank_0x37_coma_WREG_coma_ACCESS_expect_INVALID_IDENTIFIER_TYPE(void){
  CEXCEPTION_T ex;
  OperandInfo operandInfo;
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  char *instr = "   0x37,WREG,F ";
  IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
  IdentifierToken WREGToken = {TOKEN_IDENTIFIER_TYPE, 8,4,instr,"WREG"};
  OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 12,1,instr,","};
  IdentifierToken ACCESSToken = {TOKEN_IDENTIFIER_TYPE, 13,1,instr,"F"};

  getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
  getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&WREGToken);
  getToken_ExpectAndReturn(tokenizer, (Token *)&op1Token);
  getToken_ExpectAndReturn(tokenizer, (Token *)&ACCESSToken);

  Try {
    fda(tokenizer ,&operandInfo);
  }Catch(ex) {
    dumpErrorMessage(ex, 1);
  }
  freeException(ex);
}



void test_fba_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,8,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		fba(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_fba_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		fba(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_fba_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_INTEGER_TYPE, 7,1,instr,","};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

        Try {
          fba(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
      }
void test_fba_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,"."};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

        Try {
          fba(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_handleb_0x37_coma_8_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37,8 ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
        IntegerToken int1Token = {TOKEN_OPERATOR_TYPE,8,1,instr,"8",8};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
        Try {
          fba(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_handleb_0x37_coma_8_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37,8, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
        IntegerToken int1Token = {TOKEN_INTEGER_TYPE,8,1,instr,"8",8};
        OperatorToken op1Token = {TOKEN_INTEGER_TYPE, 9,1,instr,","};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
        getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
        Try {
          fba(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_handleb_0x37_coma_8_coma_1_with_false_token_type_expect_INVALID_TOKEN_TYPE(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37,8,1 ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
        IntegerToken int1Token = {TOKEN_INTEGER_TYPE,8,1,instr,"8",8};
        OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 9,1,instr,","};
        IdentifierToken idToken = {TOKEN_INTEGER_TYPE,10,1,instr,"1"};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
        getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
        getToken_ExpectAndReturn(tokenizer,(Token *)&idToken);
        Try {
          fba(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_handleb_0x37_coma_8_coma_D_expect__INVALID_IDENTIFIER_TYPE(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37,8,D ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
        IntegerToken int1Token = {TOKEN_INTEGER_TYPE,8,1,instr,"8",8};
        OperatorToken op1Token = {TOKEN_OPERATOR_TYPE, 9,1,instr,","};
        IdentifierToken idToken = {TOKEN_IDENTIFIER_TYPE,10,1,instr,"D"};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
        getToken_ExpectAndReturn(tokenizer,(Token *)&op1Token);
        getToken_ExpectAndReturn(tokenizer,(Token *)&idToken);
        Try {
          fba(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}

void test_fa_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,8,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		fa(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_fa_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		fa(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_fa_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_INTEGER_TYPE, 7,1,instr,","};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

        Try {
          fa(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
      }
void test_fa_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void){
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37. ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,"."};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);

        Try {
          fa(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}

void test_ff_0xfff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xfff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,6,instr,"0xff1",0xfff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		ff(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ff_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,8,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		ff(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ff_0x37_coma_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_INTEGER_TYPE, 7,1,instr,","};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        Try {
          ff(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_ff_0x37_fullstop_expect_INVALID_OPERATOR_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37, ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,"."};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        Try {
          ff(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_ff_0x37_coma_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37,0x37 ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
        IntegerToken int1Token = {TOKEN_OPERATOR_TYPE,8,4,instr,"0x37",0x37};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
        Try {
          ff(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}
void test_ff_0x37_coma_0xfff1_expect_overflow_occur(void)
      {
        CEXCEPTION_T ex;
        OperandInfo operandInfo;
        Tokenizer *tokenizer = (Tokenizer *)0x0badface;
        char *instr = "   0x37,0x37 ";
        IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,4,instr,"0x37",0x37};
        OperatorToken opToken = {TOKEN_OPERATOR_TYPE, 7,1,instr,","};
        IntegerToken int1Token = {TOKEN_INTEGER_TYPE,8,6,instr,"0xfff1",0xfff1};

        getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//
        getToken_ExpectAndReturn(tokenizer,(Token *)&opToken);
        getToken_ExpectAndReturn(tokenizer, (Token *)&int1Token);
        Try {
          ff(tokenizer ,&operandInfo);
        }Catch(ex) {
          dumpErrorMessage(ex, 1);
        }
        freeException(ex);
}

void test_k_0xfff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,8,5,instr,"0xff1",0xff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		k(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_k_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,8,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		k(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_ks_0xfff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xfff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,6,instr,"0xfff1",0xfff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		ks(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_ks_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,3,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		ks(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_handleS_1_with_false_token_expect_INVALID_TOKEN_TYPE(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   1  ";
	IntegerToken intToken = {TOKEN_OPERATOR_TYPE,3,6,instr,"1",1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		handleS(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_n_0xff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,5,instr,"0xff1",0xff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		n(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_n_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,3,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		n(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_n1_0x802_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,5,instr,"0x802",0x802};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		n1(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_n1_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,3,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		n1(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}

void test_n2_0xfff1_expect_overflow_occur(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0xfff1  ";
	IntegerToken intToken = {TOKEN_INTEGER_TYPE,3,6,instr,"0xfff1",0xfff1};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		n2(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
void test_n2_0x37_with_false_token_type_expect_INVALID_TOKEN_TYPE_(void){
	CEXCEPTION_T ex;
	OperandInfo operandInfo;
	Tokenizer *tokenizer = (Tokenizer *)0x0badface;
	char *instr = "   0x37  ";
	IntegerToken intToken = {TOKEN_IDENTIFIER_TYPE,3,4,instr,"0x37",0x37};

	getToken_ExpectAndReturn(tokenizer, (Token *)&intToken);//

	Try {
		n2(tokenizer ,&operandInfo);
	}Catch(ex) {
		dumpErrorMessage(ex, 1);
	}
	freeException(ex);
}
