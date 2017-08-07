#ifndef _CHECKREGISTER_H
#define _CHECKREGISTER_H
#include "Tokenizer.h"
#include "Token.h"

typedef struct OperandInfo OperandInfo;
struct OperandInfo {
  int value;
  int dirType;
  int banktype;
};
//void fda(Tokenizer *tokenizer , OperandInfo *operandInfo);
//void handleDirBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
//void handleBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
//void handleB(Tokenizer *tokenizer ,OperandInfo *operandInfo);


#endif // _CHECKREGISTER_H
