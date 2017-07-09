#include "tblrd_star-.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int tblrd_star_minus(char *tblrd_star_minusCode){
 Tokenizer *tokenizer = initTokenizer(tblrd_star_minusCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "tblrd") == 0) {
		token = getToken(tokenizer);

      if(token->type == TOKEN_OPERATOR_TYPE){
        opToken = (OperatorToken *)token;
        if(strcmp(opToken->str,"*-") ==0){
        }
        else{
        			Throw(NOT_VALID_OPERAND);
      }
			
		}
      return 0x000a ;
		}else{
      Throw(NOT_VALID_INSTRUCTION);
	}

}
}
