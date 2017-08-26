#include "AssemblyCode.h"
#include "CException.h"
#include "Token.h"
#include "Tokenizer.h"
#include "checkregister.h"
#include "error.h"
#include "toupper.h"
#include <stdio.h>
#include <string.h>
#include "Exception.h"

int addlw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ADDLW") == 0) {
        k(tokenizer, &OperandInfo);
          code[0] = 0x0f;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                 (OperandInfo.banktype);
        *memoryPtr+=2;
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

int addwf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ADDWF") == 0) {
        fda(tokenizer, &OperandInfo);
        code[0] = 0x24+(OperandInfo.dirType) +
               (OperandInfo.banktype);
        code[1] = (OperandInfo.value);
        *memoryPtr += 2;
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

int addwfc(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ADDWFC") == 0) {
        fda(tokenizer, &OperandInfo);
        code[0] = 0x20+(OperandInfo.dirType) +
               (OperandInfo.banktype);
        code[1] = (OperandInfo.value);
        *memoryPtr+=2;
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

int andlw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ANDLW") == 0) {
        k(tokenizer, &OperandInfo);
        code[0] = 0x0b;
        code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
               (OperandInfo.banktype);
      *memoryPtr+=2;
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

int andwf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "ANDWF") == 0) {
        fda(tokenizer, &OperandInfo);
        code[0] = 0x14+(OperandInfo.dirType) +
               (OperandInfo.banktype);
        code[1] = (OperandInfo.value);
        *memoryPtr+=2;
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

int bc(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BC") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe2;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

//
int bn(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BN") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe6;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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
//
int bnc(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNC") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe3;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int bnn(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNN") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe7;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int bnov(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNOV") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe5;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int bnz(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BNZ") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe1;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int bov(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BOV") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe4;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int bra(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BRA") == 0) {
          n1(tokenizer, &OperandInfo);
          code[0] = 0xd0 + (OperandInfo.value);
          code[1] = (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;

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

int bz(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BZ") == 0) {
          n(tokenizer, &OperandInfo);
          code[0] = 0xe0;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int bcf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BCF") == 0) {
          fba(tokenizer, &OperandInfo);
          code[0] = 0x90+((OperandInfo.dirType)<<1) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int bsf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BSF") == 0) {
          fba(tokenizer, &OperandInfo);
          code[0] = 0x80+((OperandInfo.dirType)<<1) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int btfsc(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BTFSC") == 0) {
          fba(tokenizer, &OperandInfo);
          code[0] = 0xb0+((OperandInfo.dirType)<<1) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int btfss(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BTFSS") == 0) {
          fba(tokenizer, &OperandInfo);
          code[0] = 0xa0+((OperandInfo.dirType)<<1) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int btg(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "BTG") == 0) {
          fba(tokenizer, &OperandInfo);
          code[0] = 0x70+((OperandInfo.dirType)<<1) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int call(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CALL") == 0) {
          ks(tokenizer, &OperandInfo, &OperandInfo1);
          code[0] = 0xec + (OperandInfo.dirType);
          code[1] = (OperandInfo.value) +
                    (OperandInfo.banktype);
          code[2] = 0xf0;
          code[3] = (OperandInfo1.value1) + (OperandInfo1.dirType1) +
                    (OperandInfo1.banktype1);
          *memoryPtr+=4;

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

int clrf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CLRF") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x6a+(OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) ;
          *memoryPtr+=2;
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

int clrwdt(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CLRWDT") == 0) {
          code[0] = 0x00;
          code[1] = 0x04;
          *memoryPtr+=2;
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

int comf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
       if (strcmp(idToken->str, "COMF") == 0) {
        fda(tokenizer, &OperandInfo);
        code[0] = 0x1c+ (OperandInfo.dirType) +
                  (OperandInfo.banktype);
        code[1] = (OperandInfo.value);
        *memoryPtr+=2;
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

int cpfseq(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "CPFSEQ") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x62 + (OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType);
          *memoryPtr+=2;
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

int cpfsgt(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "CPFSGT") == 0) {
        fa(tokenizer, &OperandInfo);
        code[0] = 0x64+(OperandInfo.banktype);
        code[1] = (OperandInfo.value) + (OperandInfo.dirType) ;
        *memoryPtr+=2;
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

int cpfslt(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "CPFSLT") == 0) {
        fa(tokenizer, &OperandInfo);
        code[0] = 0x60+(OperandInfo.banktype);
        code[1] = (OperandInfo.value) + (OperandInfo.dirType) ;
        *memoryPtr+=2;
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

int daw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "DAW") == 0) {
        code[0] = 0x00;
        code[1] = 0x07;
        *memoryPtr+=2;
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

int decf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
  if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "DECF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x04+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int decfsz(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "DECFSZ") == 0) {
        fda(tokenizer, &OperandInfo);
        code[0] = 0x2c+ (OperandInfo.dirType) +
                  (OperandInfo.banktype);
        code[1] = (OperandInfo.value);
        *memoryPtr+=2;
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

int dcfsnz(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
      if (strcmp(idToken->str, "DCFSNZ") == 0) {
        fda(tokenizer, &OperandInfo);
        code[0] = 0x4c+ (OperandInfo.dirType) +
                  (OperandInfo.banktype);
        code[1] = (OperandInfo.value);
        *memoryPtr+=2;
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

int _goto(char *instr,char**memoryPtr) {
    instr = touppercase(instr);
    OperandInfo OperandInfo;
    OperandInfo1 OperandInfo1;
    Tokenizer *tokenizer = initTokenizer(instr);
    Token *token = getToken(tokenizer);
    IdentifierToken *idToken;
    IntegerToken *intToken;
    uint8_t *code = *memoryPtr;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "GOTO") == 0) {
          n2(tokenizer, &OperandInfo, &OperandInfo1);
          code[0] = 0xef;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[2] = 0xf0;
          code[3] = (OperandInfo1.value1) + (OperandInfo1.dirType1) +
                    (OperandInfo1.banktype1);
          *memoryPtr+=4;

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

int incf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "INCF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x28+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int incfsz(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "INCFSZ") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x3c+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int infsnz(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "INFSNZ") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x48+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int iorlw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "IORLW") == 0) {
          k(tokenizer, &OperandInfo);
          code[0] = 0x09;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int movlb(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVLB") == 0) {
          k(tokenizer, &OperandInfo);
          printf("value %x\n",OperandInfo.value);
          printf("dir %x\n",OperandInfo.dirType);
          printf("bank %x\n",OperandInfo.banktype);
          code[0] = 0x01;
          code[1] = 0x00 + ((OperandInfo.value) & 0x0f) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int movlw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVLW") == 0) {
          k(tokenizer, &OperandInfo);
          code[0] = 0x0e;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int movwf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVWF") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x6e + (OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType);
          *memoryPtr+=2;
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

int movf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x50+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int movff(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MOVFF") == 0) {
          ff(tokenizer, &OperandInfo, &OperandInfo1);
          code[0] = 0xc0;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[2] = 0xf0;
          code[3] = (OperandInfo1.value1) + (OperandInfo1.dirType1) +
                    (OperandInfo1.banktype1);
          *memoryPtr+=4;
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

int mullw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MULLW") == 0) {
          k(tokenizer, &OperandInfo);
          code[0] = 0x0d;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int mulwf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "MULWF") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x02+(OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType);
          *memoryPtr+=2;
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

int negf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "NEGF") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x6c+(OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType);
          *memoryPtr+=2;
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

int pop(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "POP") == 0) {
          code[0] = 0x00;
          code[1] = 0x06;
          *memoryPtr+=2;
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

int push(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "PUSH") == 0) {
          code[0] = 0x00;
          code[1] = 0x05;
          *memoryPtr+=2;
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

int retlw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RETLW") == 0) {
          k(tokenizer, &OperandInfo);
          code[0] = 0x0c;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int reset(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RESET") == 0) {
          code[0] = 0x00;
          code[1] = 0xff;
          *memoryPtr+=2;
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

int retfie(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RETFIE") == 0) {
          handleS(tokenizer, &OperandInfo);
          code[0] = 0x00;
          code[1] = 0x10 +(OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int _return(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RETURN") == 0) {
          handleS(tokenizer, &OperandInfo);
          code[0] = 0x00;
          code[1] = 0x12 +(OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int rlcf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RLCF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x34+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int rlncf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RLNCF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x44+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int rrcf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RRCF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x30+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int rrncf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "RRNCF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x40+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int setf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SETF") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x68+(OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType);
          *memoryPtr+=2;
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

int sleep(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SLEEP") == 0) {
          code[0] = 0x00;
          code[1] = 0x03;
          *memoryPtr+=2;
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

int sublw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBLW") == 0) {
          k(tokenizer, &OperandInfo);
          code[0] = 0x08;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int subwf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBWF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x5c+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int subwfb(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBWFB") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x58+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int subfwb(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SUBFWB") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x54+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int swapf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "SWAPF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x38+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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

int tblrd_star(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "*") == 0) {
                  code[0] = 0x00;
                  code[1] = 0x08;
                  *memoryPtr+=2;

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

int tblrd_star_plus(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
          if (token->type == TOKEN_OPERATOR_TYPE) {
            opToken = (OperatorToken *)token;
            if (strcmp(opToken->str, "*+") == 0) {
              code[0] = 0x00;
              code[1] = 0x09;
              *memoryPtr+=2;
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

int tblrd_star_minus(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "*-") == 0) {
                  code[0] = 0x00;
                  code[1] = 0x0a;
                  *memoryPtr+=2;
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

int tblrd_plus_star(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLRD") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "+*") == 0) {
                  code[0] = 0x00;
                  code[1] = 0x0b;
                  *memoryPtr+=2;
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

int tblwt_star(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
          if (token->type == TOKEN_OPERATOR_TYPE) {
            opToken = (OperatorToken *)token;
              if (strcmp(opToken->str, "*") == 0) {
                code[0] = 0x00;
                code[1] = 0x0c;
                *memoryPtr+=2;
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

int tblwt_star_plus(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
          if (token->type == TOKEN_OPERATOR_TYPE) {
            opToken = (OperatorToken *)token;
              if (strcmp(opToken->str, "*+") == 0) {
                code[0] = 0x00;
                code[1] = 0x0d;
                *memoryPtr+=2;
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

int tblwt_star_minus(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "*-") == 0) {
                  code[0] = 0x00;
                  code[1] = 0x0e;
                  *memoryPtr+=2;
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

int tblwt_plus_star(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TBLWT") == 0) {
          token = getToken(tokenizer);
            if (token->type == TOKEN_OPERATOR_TYPE) {
              opToken = (OperatorToken *)token;
                if (strcmp(opToken->str, "+*") == 0) {
                  code[0] = 0x00;
                  code[1] = 0x0f;
                  *memoryPtr+=2;
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

int tstfsz(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "TSTFSZ") == 0) {
          fa(tokenizer, &OperandInfo);
          code[0] = 0x66+(OperandInfo.banktype);
          code[1] = (OperandInfo.value) + (OperandInfo.dirType);
          *memoryPtr+=2;
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

int xorlw(char *instr,char**memoryPtr) {
  instr = touppercase(instr);
  OperandInfo OperandInfo;
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "XORLW") == 0) {
          k(tokenizer, &OperandInfo);
          code[0] = 0x0a;
          code[1] = (OperandInfo.value) + (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          *memoryPtr+=2;
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

int xorwf(char *instr,char**memoryPtr) {
  OperandInfo OperandInfo;
  instr = touppercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  IntegerToken *intToken;
  OperatorToken *opToken;
  uint8_t *code = *memoryPtr;
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "XORWF") == 0) {
          fda(tokenizer, &OperandInfo);
          code[0] = 0x18+ (OperandInfo.dirType) +
                    (OperandInfo.banktype);
          code[1] = (OperandInfo.value);
          *memoryPtr+=2;
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
