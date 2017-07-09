#include "bnov.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int bnov(char *bnovCode){
 Tokenizer *tokenizer = initTokenizer(bnovCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "bnov") == 0) {
		token = getToken(tokenizer);
		if(token->type == TOKEN_INTEGER_TYPE) {
			IntegerToken *intToken = (IntegerToken *)token;
			if(intToken->value > 0xff) {
				printf("Warning Argument out of range.Least significant bits used.\n");
				printf("bnov %d\n       ^", intToken->value);
			}

			return 0xe500 + (intToken->value & 0xff);
		}else{
			Throw(NOT_VALID_OPERAND);
		}
	}else{
    Throw(NOT_VALID_INSTRUCTION);
}
}
}
