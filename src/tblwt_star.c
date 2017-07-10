#include "tblwt_star.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int tblwt_star(char *tblwt_starCode){
 Tokenizer *tokenizer = initTokenizer(tblwt_starCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "tblwt") == 0) {
		token = getToken(tokenizer);
      if(token->type == TOKEN_OPERATOR_TYPE){
        opToken = (OperatorToken *)token;
        if(strcmp(opToken->str,"*") ==0){

        }
        else{
          Throw(NOT_VALID_OPERAND);
      }
		} return 0x000c ;

    }else{
      Throw(NOT_VALID_INSTRUCTION);

		}
	}

}

int tblwt_star_plus(char *tblwt_star_plusCode){
 Tokenizer *tokenizer = initTokenizer(tblwt_star_plusCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "tblwt") == 0) {
		token = getToken(tokenizer);
      if(token->type == TOKEN_OPERATOR_TYPE){
        opToken = (OperatorToken *)token;
        if(strcmp(opToken->str,"*+") ==0){
        }
        else{
        			Throw(NOT_VALID_OPERAND);
        		}
      }
      return 0x000d ;
		}else{
      Throw(NOT_VALID_INSTRUCTION);
    }

	}

}

int tblwt_star_minus(char *tblwt_star_minusCode){
 Tokenizer *tokenizer = initTokenizer(tblwt_star_minusCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "tblwt") == 0) {
		token = getToken(tokenizer);
      if(token->type == TOKEN_OPERATOR_TYPE){
        opToken = (OperatorToken *)token;
        if(strcmp(opToken->str,"*-") ==0){
        }
        else{
        			Throw(NOT_VALID_OPERAND);
      }

		}
      return 0x000e ;
		}else{
      Throw(NOT_VALID_INSTRUCTION);
	}

}
}

int tblwt_plus_star(char *tblwt_plus_starCode){
 Tokenizer *tokenizer = initTokenizer(tblwt_plus_starCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if(strcmp(idToken->str, "tblwt") == 0) {
		token = getToken(tokenizer);
      if(token->type == TOKEN_OPERATOR_TYPE){
        opToken = (OperatorToken *)token;
        if(strcmp(opToken->str,"+*") ==0){
        }
        else{
        			Throw(NOT_VALID_OPERAND);
        		}
      }
      return 0x000f ;
		}else{
      Throw(NOT_VALID_INSTRUCTION);
    }

	}

}