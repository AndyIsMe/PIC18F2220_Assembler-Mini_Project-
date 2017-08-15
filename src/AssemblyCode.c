#include "AssemblyCode.h"
#include "CException.h"
#include "Token.h"
#include "Tokenizer.h"
#include "checkregister.h"
#include "error.h"
#include "toupper.h"
#include <stdio.h>
#include <string.h>


int addlw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ADDLW") == 0) {
        k(tokenizer, &OperandInfo);
        return 0x0f00 + (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
        "Invalid identifier, expecting 'ADDLW', but received '%s'\n", \
          idToken->str);
            }
                                              }
    else {
      throwException(NOT_VALID_IDENTIFIER, (void *)token,
       "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int addwf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ADDWF") == 0) {
        fda(tokenizer, &OperandInfo);
        return 0x2400 + (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
        "Invalid identifier, expecting 'ADDWF', but received '%s'\n", \
          idToken->str);
            }

                                              }
    else {
      throwException(NOT_VALID_IDENTIFIER, (void *)token,
      "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int addwfc(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ADDWFC") == 0) {
        fda(tokenizer, &OperandInfo);
        return 0x2000 + (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
        "Invalid identifier, expecting 'ADDWFC', but received '%s'\n", \
          idToken->str);
            }
                                              }
    else {
      throwException(NOT_VALID_IDENTIFIER, (void *)token,
      "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int andlw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ANDLW") == 0) {
        k(tokenizer, &OperandInfo);
        return 0x0b00 + (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
         "Invalid identifier, expecting 'ANDLW', but received '%s'\n", \
          idToken->str);
            }
                                              }
    else {
      throwException(NOT_VALID_IDENTIFIER, (void *)token,
       "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int andwf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ANDWF") == 0) {
        fda(tokenizer, &OperandInfo);
        return 0x1400 + (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
        "Invalid identifier, expecting 'ANDWF', but received '%s'\n", \
        idToken->str);
          }
                                              }
    else {
      throwException(NOT_VALID_IDENTIFIER, (void *)token,
      "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int bc(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BC") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe200 + (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
                                              }
        else {
        throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
        "Invalid identifier, expecting 'BC', but received '%s'\n", \
          idToken->str);
            }
                                              }
    else {
      throwException(NOT_VALID_IDENTIFIER, (void *)token,
       "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int bn(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BN") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe600 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
                 "Invalid identifier, expecting 'BN', but received '%s'\n", \
                  idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int bnc(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNC") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe300 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BNC', but received '%s'\n", \
            idToken->str);
        }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
  }

int bnn(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNN") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe700 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
         "Invalid identifier, expecting 'BNN', but received '%s'\n", \
          idToken->str);
            }
      }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int bnov(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNOV") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe500 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BNOV', but received '%s'\n", \
            idToken->str);
            }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
         token->type);
          }
}

int bnz(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNZ") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe100 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BNZ', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int bov(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BOV") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe400 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BOV', but received '%s'\n", \
           idToken->str);
         }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int bra(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BRA") == 0) {
          n1(tokenizer, &OperandInfo, &OperandInfo1);
          return 0xd0000000 + ((OperandInfo.value) << 16) +
                 ((OperandInfo.dirType) << 16) +
                 ((OperandInfo.banktype) << 16) +
                 0x0000d000 +
                 ((OperandInfo1.value1) >> 32) +
                 ((OperandInfo1.dirType1) >> 32) +
                 ((OperandInfo1.banktype1) >> 32);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BRA', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
          }
}

int bz(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BZ") == 0) {
          n(tokenizer, &OperandInfo);
          return 0xe000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BZ', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
         "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int bcf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BCF") == 0) {
          fba(tokenizer, &OperandInfo);
          return 0x9000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BCF', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
         "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int bsf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BSF") == 0) {
          fba(tokenizer, &OperandInfo);
          return 0x8000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BSF', but received '%s'\n", \
            idToken->str);
            }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int btfsc(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BTFSC") == 0) {
          fba(tokenizer, &OperandInfo);
          return 0xb000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
                 "Invalid identifier, expecting 'BTFSC', but received '%s'\n", \
                  idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
         "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int btfss(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BTFSS") == 0) {
          fba(tokenizer, &OperandInfo);
          return 0xa000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
           "Invalid identifier, expecting 'BTFSS', but received '%s'\n", \
            idToken->str);
             }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
        }
}

int btg(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BTG") == 0) {
          fba(tokenizer, &OperandInfo);
          return 0x7000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'BTG', but received '%s'\n", \
            idToken->str);
             }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int call(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CALL") == 0) {
          ks(tokenizer, &OperandInfo, &OperandInfo1);
          return 0xec000000 + ((OperandInfo.value) << 16) +
                 ((OperandInfo.dirType) << 24) +
                 ((OperandInfo.banktype) << 16) +
                 0x0000f000 +
                 ((OperandInfo1.value1) >> 32) +
                 ((OperandInfo1.dirType1) >> 32) +
                 ((OperandInfo1.banktype1) >> 32);

        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'CALL', but received '%s'\n", \
            idToken->str);
        }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
        }
}

int clrf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CLRF") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x6a00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'CLRF', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
         }
}

int clrwdt(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CLRWDT") == 0) {
          return 0x0004;
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'CLRWDT', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
         }
}

int comf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
       if (strcmp(idToken->str, "COMF") == 0) {
        fda(tokenizer, &OperandInfo);
        return 0x1c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'COMF', but received '%s'\n", \
           idToken->str);
         }
                                                }
  else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
         token->type);
       }
}

int cpfseq(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CPFSEQ") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x6200 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'CPFSEQ', but received '%s'\n", \
          idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
        token->type);
           }
}

int cpfsgt(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "CPFSGT") == 0) {
        fa(tokenizer, &OperandInfo);
        return 0x6400 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
      else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'CPFSGT', but received '%s'\n", \
            idToken->str);
            }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
         }
}

int cpfslt(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "CPFSLT") == 0) {
        fa(tokenizer, &OperandInfo);
        return 0x6000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        }
      else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'CPFSLT', but received '%s'\n", \
           idToken->str);
           }
                                              }
  else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
        }
}

int daw(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "DAW") == 0) {
        return 0x0007;
        }
      else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'DAW', but received '%s'\n", \
            idToken->str);
            }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int decf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "DECF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x0400 + (OperandInfo.value) + (OperandInfo.dirType) +
                   (OperandInfo.banktype);
          }
        else {
            throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
             "Invalid identifier, expecting 'DECF', but received '%s'\n", \
              idToken->str);
              }
                                              }
  else {
          throwException(NOT_VALID_IDENTIFIER, (void *)token,
          "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
           token->type);
        }
}

int decfsz(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "DECFSZ") == 0) {
        fda(tokenizer, &OperandInfo);
        return 0x2c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
      else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'DECFSZ', but received '%s'\n", \
            idToken->str);
            }
      }
  else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
       }
}

int dcfsnz(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "DCFSNZ") == 0) {
        fda(tokenizer, &OperandInfo);
        return 0x4c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
       else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'DCFSNZ', but received '%s'\n", \
            idToken->str);
            }
                                            }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
        }
}

int _goto(char *instr) {
    instr = touppercase(instr);
    OperandInfo OperandInfo;
    OperandInfo1 OperandInfo1;
    Tokenizer *tokenizer = initTokenizer(instr);
    Token *token = getToken(tokenizer);
    IdentifierToken *idToken;
    IntegerToken *intToken;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "GOTO") == 0) {
          n2(tokenizer, &OperandInfo, &OperandInfo1);
          return 0xef000000 + ((OperandInfo.value) << 16) +
                 ((OperandInfo.dirType) << 16) +
                 ((OperandInfo.banktype) << 16) +
                 0x0000f000 +
                 ((OperandInfo1.value1) >> 32) +
                 ((OperandInfo1.dirType1) >> 32) +
                 ((OperandInfo1.banktype1) >> 32);

        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'GOTO', but received '%s'\n", \
            idToken->str);
        }
                                                  }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int incf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "INCF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x2800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                              }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'INCF', but received '%s'\n", \
            idToken->str);
            }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int incfsz(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "INCFSZ") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x3c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'INCFSZ', but received '%s'\n", \
            idToken->str);
            }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int infsnz(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "INFSNZ") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x4800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'INFSNZ', but received '%s'\n", \
            idToken->str);
            }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int iorlw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "IORLW") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0900 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'IORLW', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
        }
}

int movlb(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVLB") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0100 + ((OperandInfo.value) & 0x0f) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MOVLB', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int movlw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVLW") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0e00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MOVLW', but received '%s'\n", \
            idToken->str);
            }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int movwf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVWF") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x6e00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MOVWF', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int movf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x5000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MOVF', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int movff(char *instr) {
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVFF") == 0) {
          ff(tokenizer, &OperandInfo, &OperandInfo1);
          return 0xc0000000 + ((OperandInfo.value) << 16) +
                 ((OperandInfo.dirType) << 16) +
                 ((OperandInfo.banktype) << 16) +
                 0x0000f000 +
                 ((OperandInfo1.value1) >> 32) +
                 ((OperandInfo1.dirType1) >> 32) +
                 ((OperandInfo1.banktype1) >> 32);
                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MOVFF', but received '%s'\n", \
            idToken->str);
              }
                                                  }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int mullw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MULLW") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0d00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MULLW', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int mulwf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MULWF") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x0200 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'MULWF', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int negf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "NEGF") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x6c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'NEGF', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int pop(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "POP") == 0) {
          return 0x0006;
                                              }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'POP', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int push(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "PUSH") == 0) {
          return 0x0005;
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'PUSH', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int retlw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RETLW") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RETLW', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int reset(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RESET") == 0) {
          return 0x00ff;
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RESET', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int retfie(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RETFIE") == 0) {
          handleS(tokenizer, &OperandInfo);
          return 0x0010 + (OperandInfo.dirType) + (OperandInfo.banktype);
                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RETFIE', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int _return(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RETURN") == 0) {
          handleS(tokenizer, &OperandInfo);
          return 0x0012 + (OperandInfo.dirType) + (OperandInfo.banktype);
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RETURN', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int rlcf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RLCF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x3400 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RLCF', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int rlncf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RLNCF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x4400 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RLNF', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int rrcf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RRCF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x3000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RRCF', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int rrncf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RRNCF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x4000 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'RRNCF', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int setf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SETF") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x6800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SETF', but received '%s'\n", \
            idToken->str);
              }
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int sleep(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SLEEP") == 0) {
          return 0x0003;
        }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SLEEP', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int sublw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBLW") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SUBLW', but received '%s'\n", \
            idToken->str);
              }
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int subwf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBWF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x5c00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SUBWF', but received '%s'\n", \
            idToken->str);
              }

                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int subwfb(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBWFB") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x5800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SUBWFB', but received '%s'\n", \
            idToken->str);
              }
                                              }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int subfwb(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBFWB") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x5400 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SUBFWB', but received '%s'\n", \
            idToken->str);
              }

                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int swapf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SWAPF") == 0) {
          fda(tokenizer, &OperandInfo);
            return 0x3800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'SWAPF', but received '%s'\n", \
            idToken->str);
              }
                                                }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int tblrd_star(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "*") == 0) {
                  return 0x0008;

                                                    }
                else {
              throwException(NOT_VALID_OPERATOR, (void *)opToken,
              "Invalid operator, expecting ',', but received '%s'\n",
               opToken->str);
                     }
                                                    }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
            "received '%d'\n",
              token->type);
                  }
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLRD_STAR', but received '%s'\n", \
            idToken->str);
              }
                                                  }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int tblrd_star_plus(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
          if (token->type == TOKEN_OPERATOR_TYPE) {
            opToken = (OperatorToken *)token;
            if (strcmp(opToken->str, "*+") == 0) {
              return 0x0009;
                                                  }
            else {
              throwException(NOT_VALID_OPERATOR, (void *)opToken,
              "Invalid operator, expecting ',', but received '%s'\n",
                opToken->str);
                  }
                                                  }
          else {
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
            "received '%d'\n",
              token->type);
               }
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLRD_STAR_PLUS', but received '%s'\n", \
            idToken->str);
              }
                                               }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int tblrd_star_minus(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "*-") == 0) {
                  return 0x000a;
                                                      }
                else {
              throwException(NOT_VALID_OPERATOR, (void *)opToken,
              "Invalid operator, expecting ',', but received '%s'\n",
              opToken->str);
                      }
                                                    }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
            "received '%d'\n",
             token->type);
                }

                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLRD_STAR_MINUS', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int tblrd_plus_star(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "+*") == 0) {
                  return 0x000b;
                                                      }
                else {
                  throwException(NOT_VALID_OPERATOR, (void *)opToken,
                  "Invalid operator, expecting ',', but received '%s'\n",
                    opToken->str);
                      }
                                                    }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
                           "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
                           "received '%d'\n",
                           token->type);
                }

                                                    }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLRD_PLUS_STAR', but received '%s'\n", \
            idToken->str);
              }
                                                  }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int tblwt_star(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
          if (token->type == TOKEN_OPERATOR_TYPE) {
            opToken = (OperatorToken *)token;
              if (strcmp(opToken->str, "*") == 0) {
                return 0x000c;

                                                  }
              else {
              throwException(NOT_VALID_OPERATOR, (void *)opToken,
              "Invalid operator, expecting ',', but received '%s'\n",
               opToken->str);
                    }
                                                  }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
            "received '%d'\n",
             token->type);
                }

                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLWT_STAR', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int tblwt_star_plus(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
          if (token->type == TOKEN_OPERATOR_TYPE) {
            opToken = (OperatorToken *)token;
              if (strcmp(opToken->str, "*+") == 0) {
                return 0x000d;
                                                    }
              else {
              throwException(NOT_VALID_OPERATOR, (void *)opToken,
              "Invalid operator, expecting ',', but received '%s'\n",
               opToken->str);
                    }
                                                  }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
             "received '%d'\n",
               token->type);
                }

                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLWT_STAR_PLUS', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int tblwt_star_minus(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "*-") == 0) {
                  return 0x000e;
                                                      }
                else {
                  throwException(NOT_VALID_OPERATOR, (void *)opToken,
                  "Invalid operator, expecting ',', but received '%s'\n",
                   opToken->str);
                      }
                                                      }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
            "received '%d'\n",
             token->type);
                }
                                                    }
      else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLWT_STAR_MINUS', but received '%s'\n", \
            idToken->str);
            }
                                                  }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int tblwt_plus_star(char *instr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "+*") == 0) {
                  return 0x000f;
                                                      }
                else {
                throwException(NOT_VALID_OPERATOR, (void *)opToken,
                "Invalid operator, expecting ',', but received '%s'\n",
                  opToken->str);
                      }
                                                    }
            else{
            throwException(NOT_VALID_OPERATOR, (void *)token,
            "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
            "received '%d'\n",
             token->type);
                }

                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TBLWT_PLUS_STAR', but received '%s'\n", \
            idToken->str);
              }
                                                  }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int tstfsz(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TSTFSZ") == 0) {
          fa(tokenizer, &OperandInfo);
          return 0x6600 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                  }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'TFTFSZ', but received '%s'\n", \
            idToken->str);
              }
                                              }
    else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}

int xorlw(char *instr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "XORLW") == 0) {
          k(tokenizer, &OperandInfo);
          return 0x0a00 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'XORLW', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
            }
}

int xorwf(char *instr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "XORWF") == 0) {
          fda(tokenizer, &OperandInfo);
          return 0x1800 + (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
                                                }
        else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'XORWF', but received '%s'\n", \
            idToken->str);
              }
                                                }
      else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
        "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but received '%d'\n", \
          token->type);
          }
}
