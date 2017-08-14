#include "checkregister.h"
#include "CException.h"
#include "Token.h"
#include "Tokenizer.h"
#include "error.h"
#include "toupper.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fda(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value > 0xff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '0x%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->value);
    } else {
      operandInfo->value = ((IntegerToken *)token)->value;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_OPERATOR_TYPE) {
    opToken = (OperatorToken *)token;
    if (opToken->str == NULL) {
      operandInfo->dirType = 0x0200;
    } else if (strcmp(opToken->str, ",") == 0) {
      handleDirBank(tokenizer, operandInfo);
    } else {
      throwException(NOT_VALID_OPERATOR, (void *)opToken,
                     "Invalid operator, expecting ',', but received '%s'\n",
                     opToken->str);
    }
  } else {
    throwException(NOT_VALID_OPERATOR, (void *)token,
                   "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void handleDirBank(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_IDENTIFIER_TYPE) {
    idToken = (IdentifierToken *)token;
    if ((strcmp(idToken->str, "W") == 0) ||
        (strcmp(idToken->str, "WREG") == 0) || (strcmp(idToken->str,"0")==0)){
      operandInfo->dirType = 0x0000;
    } else if ((strcmp(idToken->str, "F") == 0) || (strcmp(idToken->str,"1")==0)){
      operandInfo->dirType = 0x0200;
    } else {
      throwException(
          NOT_VALID_IDENTIFIER, (void *)idToken,
          "Invalid identifier, expecting 'W/WREG/F/0/1', but received '%s'\n",
          idToken->str);
    }
  } else {
    throwException(NOT_VALID_IDENTIFIER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_OPERATOR_TYPE) {
    opToken = (OperatorToken *)token;
    if (opToken->str == NULL) {
      operandInfo->banktype = 0x0000;
    } else if (strcmp(opToken->str, ",") == 0) {
      handleBank(tokenizer, operandInfo);
    } else {
      throwException(NOT_VALID_OPERATOR, (void *)opToken,
                     "Invalid operator, expecting ',', but received '%s'\n",
                     opToken->str);
    }
  } else {
    throwException(NOT_VALID_OPERATOR, (void *)token,
                   "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void handleBank(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  if (token->type == TOKEN_IDENTIFIER_TYPE) {
    idToken = (IdentifierToken *)token;
    if ((strcmp(idToken->str, "ACCESS") == 0) || (strcmp(idToken->str,"0") == 0)) {
      operandInfo->banktype = 0x0000;
    } else if ((strcmp(idToken->str, "BANKED") ==
               0) || (strcmp(idToken->str, "1")==0)) {
      operandInfo->banktype = 0x0100;
    } else {
      throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
                     "Invalid identifier, expecting 'ACCESS/BANKED/0/1', but "
                     "received '%s'\n",
                     idToken->str);
    }
  } else {
    throwException(NOT_VALID_IDENTIFIER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void fba(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->str);
    } else {
      operandInfo->value = ((IntegerToken *)token)->value;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_OPERATOR_TYPE) {
    opToken = (OperatorToken *)token;
    if (opToken->str == NULL) {
      throwException(NOT_VALID_OPERATOR, (void *)opToken,
                     "Invalid operator, expecting ',', but received '%s'\n",
                     opToken->str);
    } else if (strcmp(opToken->str, ",") == 0) {
      handleB(tokenizer, operandInfo);
    } else {
      throwException(NOT_VALID_OPERATOR, (void *)opToken,
                     "Invalid operator, expecting ',', but received '%s'\n",
                     opToken->str);
    }
  } else {
    throwException(NOT_VALID_OPERATOR, (void *)token,
                   "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void handleB(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  IntegerToken *intToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value == 0x8) {
      operandInfo->dirType = 0x0000;
    }else if(intToken->value == 0x9){
      operandInfo->dirType = ((IntegerToken *)token)->value - 0x8;
      operandInfo->dirType = (operandInfo->dirType) << 9;
    }
    else if(intToken->value >= 0x10){
      operandInfo->dirType = ((IntegerToken *)token)->value - 0x10;
      operandInfo->dirType = (operandInfo->dirType) << 9;
    }
     else {
      operandInfo->dirType = ((IntegerToken *)token)->value;
      operandInfo->dirType = (operandInfo->dirType) << 9;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_OPERATOR_TYPE) {
    opToken = (OperatorToken *)token;
    if (opToken->str == NULL) {
      operandInfo->banktype = 0x0000;
    } else if (strcmp(opToken->str, ",") == 0) {
      Token *token = getToken(tokenizer);
      IdentifierToken *idToken;
      if (token->type == TOKEN_IDENTIFIER_TYPE) {
        idToken = (IdentifierToken *)token;
        if (strcmp(idToken->str, "ACCESS") == 0) /*|| (idToken->str == 0))*/ {
          operandInfo->dirType = operandInfo->dirType + 0x0000;
          operandInfo->banktype = 0x0000;
        } else if (strcmp(idToken->str, "BANKED") == 0) /*||
                   (idToken->str == 1))*/ {
          operandInfo->dirType = operandInfo->dirType + 0x0100;
          operandInfo->banktype = 0x0000;
        } else {
          throwException(NOT_VALID_IDENTIFIER, (void *)idToken,
                         "Invalid IDENTIFIER, expecting 'ACCESS/BANKED/1/0', "
                         "but received '%s'\n",
                         idToken->str);
        }
      } else {
        throwException(NOT_VALID_IDENTIFIER, (void *)token,
                       "Invalid token type, expecting 'TOKEN_IDENTIFIER_TYPE', "
                       "but received '%d'\n",
                       token->type);
      }
    }
  } else {
    throwException(NOT_VALID_OPERATOR, (void *)token,
                   "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void fa(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->str);
    } else {
      operandInfo->value = ((IntegerToken *)token)->value;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_OPERATOR_TYPE) {
    opToken = (OperatorToken *)token;
    if (opToken->str == NULL) {
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
    } else if (strcmp(opToken->str, ",") == 0) {
      handleBank(tokenizer, operandInfo);
    } else {
      throwException(NOT_VALID_OPERATOR, (void *)opToken,
                     "Invalid operator, expecting ',', but received '%s'\n",
                     intToken->str);
    }
  } else {
    throwException(NOT_VALID_OPERATOR, (void *)token,
                   "Invalid token type , expecting 'TOKEN_OPERATOR_TYPE',but "
                   "received '%s'\n",
                   token->type);
  }
}

void ff(Tokenizer *tokenizer, OperandInfo *operandInfo,
        OperandInfo1 *operandInfo1) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xfff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->str);
    } else {

      operandInfo->value = ((IntegerToken *)token)->value;
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
    }
    token = getToken(tokenizer);
    if (token->type == TOKEN_OPERATOR_TYPE) {
      opToken = (OperatorToken *)token;
      if (opToken->str == NULL) {
        throwException(NOT_VALID_OPERATOR, (void *)opToken,
                       "Invalid operator, expecting ',', but received '%s'\n",
                       opToken->str);
      } else if (strcmp(opToken->str, ",") == 0) {
      }
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xfff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->str);
    } else {
      operandInfo1->value1 = ((IntegerToken *)token)->value;
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void k(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value > 0xff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '0x%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->value);
    } else {
      operandInfo->value = ((IntegerToken *)token)->value;
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void ks(Tokenizer *tokenizer, OperandInfo *operandInfo,
        OperandInfo1 *operandInfo1) {
  Token *token = getToken(tokenizer);
  int result;
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xfff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->str);
    } else if ((intToken->value <= 0xfff) && (intToken->value > 0xff)) {
      operandInfo1->value1 = (((intToken->value) >> 8) & 0xf) / 2;
      printf("\nopInfo1 value%x\n", operandInfo1->value1);
      printf("inttoken value%x\n", intToken->value);
      printf("opinfo1 value%x\n", operandInfo1->value1);
      result = check2ndDigit(intToken->value);
      printf("result %x\n", result);
      operandInfo->value = result;
      printf("value %x\n", operandInfo->value);
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    } else if ((intToken->value <= 0xff) &&
               (intToken->value > 0xf)) { //(intToken->value <= 0xff)
      operandInfo1->value1 = 0x0000;
      operandInfo->value = ((intToken->value >> 4) & 0xf) / 2;
      printf("\nvalue111 %x\n", operandInfo->value);
      printf("inttoken value%x\n", intToken->value);
      printf("opinfo1 value%x\n", operandInfo1->value1);
      result = check2ndDigit(intToken->value);
      printf("result %x\n", result);
      printf("opppvalue %x\n", operandInfo->value << 4);
      operandInfo->value = result + ((operandInfo->value) << 4);
      printf("value %x\n", operandInfo->value);
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    } else { // intToken->value <= 0xf
      operandInfo1->value1 = 0x0000;
      operandInfo->value = 0x0000;
      result = check2ndDigit(intToken->value);
      printf("result %x\n", result);
      operandInfo->value = result;
      printf("value %x\n", operandInfo->value);
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
  token = getToken(tokenizer);
  if (token->type == TOKEN_OPERATOR_TYPE) {
    opToken = (OperatorToken *)token;
    if (opToken->str == NULL) {
      operandInfo->dirType = 0x0000;
    } else if (strcmp(opToken->str, ",") == 0) {
      handleS(tokenizer, operandInfo);
    } else {
      throwException(NOT_VALID_OPERATOR, (void *)opToken,
                     "Invalid operator, expecting ',', but received '%s'\n",
                     opToken->str);
    }
  } else {
    throwException(NOT_VALID_OPERATOR, (void *)token,
                   "Invalid token type, expecting 'TOKEN_OPERATOR_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

int check2ndDigit(int data) {
  int temp1;
  int value;
  if ((data <= 0xfff) && (data > 0xff)) {
    temp1 = data & 0x0f0;
  } else if ((data <= 0xff) && (data > 0xf)) {
    temp1 = data & 0xf0;
  } else if (data < 0x1) {
    return data;
  } else { // data < 0xf
    temp1 = data & 0x0;
  }
  printf("checkdata %x \n", data);
  printf("checktemp1 %x \n", temp1);
  switch (temp1) {
  case (0x00):
    temp1 = 0x080;
    value = checkdataEven(data);
    break;
  case (0x10):
    temp1 = 0x080;
    value = checkdataOdd(data);
    break;
  case (0x20):
    temp1 = 0x090;
    value = checkdataEven(data);
    break;
  case (0x30):
    temp1 = 0x090;
    value = checkdataOdd(data);
    break;
  case (0x40):
    temp1 = 0x0a0;
    value = checkdataEven(data);
    break;
  case (0x50):
    temp1 = 0x0a0;
    value = checkdataOdd(data);
    break;
  case (0x60):
    temp1 = 0x0b0;
    value = checkdataEven(data);
    break;
  case (0x70):
    temp1 = 0x0b0;
    value = checkdataOdd(data);
    break;
  case (0x80):
    temp1 = 0x0c0;
    value = checkdataEven(data);
    break;
  case (0x90):
    temp1 = 0x0c0;
    value = checkdataOdd(data);
    break;
  case (0xa0):
    temp1 = 0x0d0;
    value = checkdataEven(data);
    break;
  case (0xb0):
    temp1 = 0x0d0;
    value = checkdataOdd(data);
    break;
  case (0xc0):
    temp1 = 0x0e0;
    value = checkdataEven(data);
    break;
  case (0xd0):
    temp1 = 0x0e0;
    value = checkdataOdd(data);
    break;
  case (0xe0):
    temp1 = 0x0f0;
    value = checkdataEven(data);
    break;
  case (0xf0):
    temp1 = 0x0f0;
    value = checkdataOdd(data);
    break;
  default:
    temp1 = 0x000;
    break;
  }
  if ((data <= 0xfff) && (data > 0xff)) {
    data = temp1 + value;
    printf("value1 %x \n", value);
    printf("temp1 %x \n", temp1);
    printf("data %x \n", data);
    return data;
  } else if ((data <= 0xff) && (data > 0xf)) {
    data = value;
    printf("data %x \n", data);
    return data;
  } else { // data < 0xf
    data = value;
    printf("data %x \n", data);
    return data;
  }
}

int checkdataOdd(int data) {
  int check;
  printf("datavalue%x\n", data);
  if ((data <= 0xfff) && (data > 0xff)) {
    check = (0xf - ((data)&0x00f)) / 2;
    printf("checkvalue%x\n", check);
  } else if ((data <= 0xff) && (data > 0xf)) {
    check = (0xf - ((data)&0x0f)) / 2;
    printf("checkvalue%x\n", check);
  } else {
    check = (0xf - data) / 2;
    printf("checkvalue%x\n", check);
  }
  int temp;
  temp = 0x00f - check;
  printf("value%x\n", temp);
  return temp;
}

int checkdataEven(int data) {
  int check;
  int temp;
  printf("datavalue%x\n", data);
  if ((data <= 0xfff) && (data > 0xff)) {
    check = (0xf - ((data)&0x00f)) / 2;
    printf("checkvalue%x\n", check);
    temp = 0x007 - check;
    printf("value%x\n", temp);
    return temp;
  } else if ((data <= 0xff) && (data > 0xf)) {
    check = (0xf - ((data)&0x0f)) / 2;
    printf("checkvalue%x\n", check);
    temp = 0x007 - check;
    printf("value%x\n", temp);
    return temp;
  } else {
    check = (0xf - data) / 2;
    printf("checkvalue%x\n", check);
    temp = 0x007 - check;
    printf("value%x\n", temp);
    return temp;
  }
}

void handleS(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    intToken = (IntegerToken *)token;
    if (intToken->value % 2 == 0) {
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
    } else {
      operandInfo->dirType = ((IntegerToken *)token)->value;
      operandInfo->banktype = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void n(Tokenizer *tokenizer, OperandInfo *operandInfo) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '0x%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->value);
    } else {
      operandInfo->value = ((((IntegerToken *)token)->value) / 2) - 1;
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}

void n1(Tokenizer *tokenizer, OperandInfo *operandInfo,
        OperandInfo1 *operandInfo1) {
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0x802) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0x802<', but received '%x' "
                     "that exceeded the value of '0x802'\n",
                     intToken->value);
    } else if (intToken->value <= 0x1) {
      operandInfo->value = 0x7ff;
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
      operandInfo1->value1 = 0x7ff;
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    } else {
      operandInfo->value = ((((IntegerToken *)token)->value) / 2) - 1;
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
      operandInfo1->value1 = 0x7ff;
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}
void n2(Tokenizer *tokenizer, OperandInfo *operandInfo,
        OperandInfo1 *operandInfo1) {
  Token *token = getToken(tokenizer);
  int result;
  OperandInfo OperandInfo;
  OperandInfo1 OperandInfo1;
  IntegerToken *intToken;
  OperatorToken *opToken;
  if (token->type == TOKEN_INTEGER_TYPE) {
    IntegerToken *intToken = (IntegerToken *)token;
    if (intToken->value >= 0xfff) {
      printf("Warning Argument out of range.Least significant bits used.\n");
      throwException(NOT_VALID_INTEGER, (void *)intToken,
                     "Overflow occured, expecting '0xff<', but received '%x' "
                     "that exceeded the value of '0xff'\n",
                     intToken->str);
    } else if ((intToken->value <= 0xfff) && (intToken->value > 0xff)) {
      operandInfo1->value1 = (((intToken->value) >> 8) & 0xf) / 2;
      printf("\nopInfo1 value%x\n", operandInfo1->value1);
      printf("inttoken value%x\n", intToken->value);
      printf("opinfo1 value%x\n", operandInfo1->value1);
      result = check2ndDigit(intToken->value);
      printf("result %x\n", result);
      operandInfo->value = result;
      printf("value %x\n", operandInfo->value);
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    } else if ((intToken->value <= 0xff) &&
               (intToken->value > 0xf)) { //(intToken->value <= 0xff)
      operandInfo1->value1 = 0x0000;
      operandInfo->value = ((intToken->value >> 4) & 0xf) / 2;
      printf("\nvalue111 %x\n", operandInfo->value);
      printf("inttoken value%x\n", intToken->value);
      printf("opinfo1 value%x\n", operandInfo1->value1);
      result = check2ndDigit(intToken->value);
      printf("result %x\n", result);
      printf("opppvalue %x\n", operandInfo->value << 4);
      operandInfo->value = result + ((operandInfo->value) << 4);
      printf("value %x\n", operandInfo->value);
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    } else { // intToken->value <= 0xf
      operandInfo1->value1 = 0x0000;
      operandInfo->value = 0x0000;
      result = check2ndDigit(intToken->value);
      printf("result %x\n", result);
      operandInfo->value = result;
      printf("value %x\n", operandInfo->value);
      operandInfo->dirType = 0x0000;
      operandInfo->banktype = 0x0000;
      operandInfo1->dirType1 = 0x0000;
      operandInfo1->banktype1 = 0x0000;
    }
  } else {
    throwException(NOT_VALID_INTEGER, (void *)token,
                   "Invalid token type, expecting 'TOKEN_INTEGER_TYPE', but "
                   "received '%d'\n",
                   token->type);
  }
}
