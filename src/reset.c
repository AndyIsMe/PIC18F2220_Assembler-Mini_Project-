#include "reset.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"
#include "tolower.h"


int reset(char *instr){
  instr = tolowercase(instr);
  Tokenizer *tokenizer = initTokenizer(instr);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "reset") == 0) {

  }	return 0x00ff ;

    }else{
      Throw(NOT_VALID_INSTRUCTION);
    }
	}
