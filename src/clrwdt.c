#include "clrwdt.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int clrwdt(char *clrwdtCode){
 Tokenizer *tokenizer = initTokenizer(clrwdtCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "clrwdt") == 0) {

        }	return 0x0004 ;

    }else{
      Throw(NOT_VALID_INSTRUCTION);
    }
	}
