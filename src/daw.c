#include "daw.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int daw(char *dawCode){
 Tokenizer *tokenizer = initTokenizer(dawCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "daw") == 0) {

  }	return 0x0007 ;

    }else{
      Throw(NOT_VALID_INSTRUCTION);
    }
	}
