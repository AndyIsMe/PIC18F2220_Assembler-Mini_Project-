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

typedef struct OperandInfo1 OperandInfo1;
struct OperandInfo1 {
  int value1;
  int dirType1;
  int banktype1;
};

void fda(Tokenizer *tokenizer , OperandInfo *operandInfo);
void handleDirBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void handleBank(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void fba(Tokenizer *tokenizer , OperandInfo *operandInfo);
void handleB(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void fa(Tokenizer *tokenizer , OperandInfo *operandInfo);
void ff(Tokenizer *tokenizer , OperandInfo *operandInfo , OperandInfo1 *operandInfo1);
void k(Tokenizer *tokenizer , OperandInfo *operandInfo);
void ks(Tokenizer *tokenizer , OperandInfo *operandInfo , OperandInfo1 *operandInfo1);
int check2ndDigit(int data);
int checkdataOdd(int data);
int checkdataEven(int data);
void handleS(Tokenizer *tokenizer ,OperandInfo *operandInfo);
void n(Tokenizer *tokenizer , OperandInfo *operandInfo);
void n1(Tokenizer *tokenizer , OperandInfo *operandInfo, OperandInfo1 *operandInfo1);
void n2(Tokenizer *tokenizer, OperandInfo *operandInfo,
        OperandInfo1 *operandInfo1);


#endif // _CHECKREGISTER_H
