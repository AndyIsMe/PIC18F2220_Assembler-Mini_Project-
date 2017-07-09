#include "push.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int push(char *pushCode){
 Tokenizer *tokenizer = initTokenizer(pushCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "push") == 0) {

  }	return 0x0005 ;

    }else{
      Throw(NOT_VALID_INSTRUCTION);
    }
	}
