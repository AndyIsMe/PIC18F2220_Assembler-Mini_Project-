#include "bc.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int bc(char *bcCode){
 Tokenizer *tokenizer = initTokenizer(bcCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "bc") == 0) {
		token = getToken(tokenizer);
		if(token->type == TOKEN_INTEGER_TYPE) {
			IntegerToken *intToken = (IntegerToken *)token;
			if(intToken->value > 0xff) {
				printf("Warning Argument out of range.Least significant bits used.\n");
				printf("bc %d\n       ^", intToken->value);
			}

			return 0xe200 + (intToken->value & 0xff);
		}else{
			Throw(NOT_VALID_OPERAND);
		}
	}else{
    Throw(NOT_VALID_INSTRUCTION);
}
}
}
