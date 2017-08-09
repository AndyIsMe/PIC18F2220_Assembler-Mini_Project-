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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }

  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
             ((OperandInfo.dirType) << 16) + ((OperandInfo.banktype) << 16) +
             0x0000f000 + ((OperandInfo1.value1) >> 32) +
             ((OperandInfo1.dirType1) >> 32) + ((OperandInfo1.banktype1) >> 32);
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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

        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }

    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }

    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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

        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }

    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }

    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }

    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
        } else {
          Throw(NOT_VALID_OPERATOR);
        }
      }

    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }
  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }

  } else {
    Throw(NOT_VALID_INSTRUCTION);
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
    } else {
      Throw(NOT_VALID_IDENTIFIER);
    }

  } else {
    Throw(NOT_VALID_INSTRUCTION);
  }
}
