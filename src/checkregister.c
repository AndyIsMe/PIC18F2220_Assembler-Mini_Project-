#include "checkregister.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "toupper.h"

void fda(Tokenizer *tokenizer , OperandInfo *operandInfo){
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if(token->type == TOKEN_INTEGER_TYPE){
    IntegerToken *intToken = (IntegerToken *)token;
    if(intToken->value > 0xff){
      printf("Warning Argument out of range.Least significant bits used.\n");
      printf("This value has just caused an overflow : %d\n       ^", intToken->value);
    }
    else{
      operandInfo->value = ((IntegerToken *)token)->value;
    }
  }
    token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE){
      opToken = (OperatorToken *)token;
        if(opToken->str == NULL){
          operandInfo->dirType = 0x0400;
        }
        else if(strcmp(opToken->str,",")==0){
          handleDirBank(tokenizer,operandInfo);
        }
        else{
          Throw(NOT_VALID_OPERATOR);
        }
      }
}

void handleDirBank(Tokenizer *tokenizer ,OperandInfo *operandInfo){
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
    idToken = (IdentifierToken *)token;
    if((strcmp(idToken->str,"W")==0)||(strcmp(idToken->str,"WREG")==0)||(idToken->str==0)){
      operandInfo->dirType = 0x0000;
  }
    else if((strcmp(idToken->str,"F")==0)||(idToken->str==1)){
      operandInfo->dirType = 0x0400;
    }
    else{
      Throw(NOT_VALID_IDENTIFIER);
    }
  }
    token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE){
      opToken = (OperatorToken *)token;
        if(opToken->str == NULL){
          operandInfo->banktype = 0x0000;
        }
        else if(strcmp(opToken->str,",")==0){
          handleBank(tokenizer,operandInfo);
        }
        else{
          Throw(NOT_VALID_OPERATOR);
        }
      }
}

void handleBank(Tokenizer *tokenizer ,OperandInfo *operandInfo){
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  if(token->type == TOKEN_IDENTIFIER_TYPE){
    idToken = (IdentifierToken *)token;
    if((strcmp(idToken->str,"ACCESS")==0)||(idToken->str==0)){
      operandInfo->banktype = 0x0000;
  }
    else if((strcmp(idToken->str,"BANKED")==0)||(idToken->str==1)){
      operandInfo->banktype = 0x0100;
    }
    else{
      Throw(NOT_VALID_IDENTIFIER);
    }
  }
}

void fba(Tokenizer *tokenizer , OperandInfo *operandInfo){
  Token *token = getToken(tokenizer);
  IntegerToken *intToken;
  OperatorToken *opToken;
  if(token->type == TOKEN_INTEGER_TYPE){
    IntegerToken *intToken = (IntegerToken *)token;
    if(intToken->value > 0xff){
      printf("Warning Argument out of range.Least significant bits used.\n");
      printf("This value has just caused an overflow : %d\n       ^", intToken->value);
    }
    else{
      operandInfo->value = ((IntegerToken *)token)->value;
    }
  }
    token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE){
      opToken = (OperatorToken *)token;
        if(opToken->str == NULL){
          Throw(NOT_VALID_OPERATOR);
        }
        else if(strcmp(opToken->str,",")==0){
          handleB(tokenizer,operandInfo);
        }

      }
}

void handleB(Tokenizer *tokenizer ,OperandInfo *operandInfo){
  Token *token = getToken(tokenizer);
  IdentifierToken *idToken;
  OperatorToken *opToken;
  IntegerToken *intToken;
  if(token->type == TOKEN_INTEGER_TYPE){
    IntegerToken *intToken = (IntegerToken *)token;
    if(intToken->value > 0x7){
      operandInfo->dirType = 0x0000;
    }
    else {
      operandInfo->dirType = ((IntegerToken *)token)->value;
    }
  }
  else{
        Throw(NOT_VALID_IDENTIFIER);
      }
    token = getToken(tokenizer);
    if(token->type == TOKEN_OPERATOR_TYPE){
      opToken = (OperatorToken *)token;
        if(opToken->str == NULL){
          operandInfo->banktype = 0x0000;
        }
        else if(strcmp(opToken->str,",")==0){
          handleBank(tokenizer,operandInfo);
        }
        else{
          Throw(NOT_VALID_OPERATOR);
        }
      }
}
