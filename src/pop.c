#include "pop.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "tolower.h"





int pop(char *instr){
  instr = tolowercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "pop") == 0) {

  }	return 0x0006 ;

    }else{
      Throw(NOT_VALID_INSTRUCTION);
    }
	}
