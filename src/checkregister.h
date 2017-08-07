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

void fda(Tokenizer *tokenizer , OperandInfo *operandInfo);
void handleDirBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void handleBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void fba(Tokenizer *tokenizer , OperandInfo *operandInfo);
void handleB(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void fa(Tokenizer *tokenizer , OperandInfo *operandInfo);
void ff(Tokenizer *tokenizer , OperandInfo *operandInfo);
void k(Tokenizer *tokenizer , OperandInfo *operandInfo);
void ks(Tokenizer *tokenizer , OperandInfo *operandInfo);
void handleS(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void n(Tokenizer *tokenizer , OperandInfo *operandInfo);

//void fda(Tokenizer *tokenizer , OperandInfo *operandInfo);
//void handleDirBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
//void handleBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
//void handleB(Tokenizer *tokenizer ,OperandInfo *operandInfo);


#endif // _CHECKREGISTER_H
