#include "addwf.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "toupper.h"
#include "checkregister.h"

int addwf(char *instr){
  OperandInfo OperandInfo;
 instr = touppercase(instr);
 Tokenizer *tokenizer = initTokenizer(instr);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "ADDWF") == 0){
		fda(tokenizer,&OperandInfo);
  }
  return 0x2400 + (OperandInfo.value) + (OperandInfo.dirType) + (OperandInfo.banktype);
}
else{
  Throw(NOT_VALID_IDENTIFIER);
}
}
