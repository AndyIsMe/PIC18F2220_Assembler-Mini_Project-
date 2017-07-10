#include "andwf.h"
#include <string.h>
#include <stdio.h>
#include "Tokenizer.h"
#include "Token.h"
#include "error.h"
#include "CException.h"



int andwf(char *andwfCode){
 Tokenizer *tokenizer = initTokenizer(andwfCode);
 Token *token = getToken(tokenizer);
 IdentifierToken *idToken;
 IntegerToken *intToken;
 OperatorToken *opToken;

if(token->type == TOKEN_IDENTIFIER_TYPE){
	idToken = (IdentifierToken *)token;
	if((strcmp(idToken->str, "andwf") == 0)||(strcmp(idToken->str, "ANDWF") == 0)) {
		token = getToken(tokenizer);
		if(token->type == TOKEN_INTEGER_TYPE) {
			IntegerToken *intToken = (IntegerToken *)token;
      token = getToken(tokenizer);
			if(intToken->value > 0xff) {
				printf("Warning Argument out of range.Least significant bits used.\n");
				printf("andwf %d\n       ^", intToken->value);
			}
    if(token->type == TOKEN_OPERATOR_TYPE){
      opToken = (OperatorToken *)token;
      if(strcmp(opToken->str,",")==0){
        token = getToken(tokenizer);
        if(token->type == TOKEN_IDENTIFIER_TYPE){
        idToken = (IdentifierToken *)token;
        if((strcmp(idToken->str, "w")==0)||(strcmp(idToken->str,"WREG")==0)){
          token = getToken(tokenizer);
          if(token->type == TOKEN_OPERATOR_TYPE){
            opToken = (OperatorToken *)token;
            if(strcmp(opToken->str,",")==0){
              token = getToken(tokenizer);
              if(token->type == TOKEN_IDENTIFIER_TYPE){
                idToken = (IdentifierToken *)token;
                if(strcmp(idToken->str,"BANKED")==0){
                  return 0x1500 + (intToken->value & 0xff);
                }
                else if(strcmp(idToken->str,"ACCESS")==0){
                  return 0x1400 + (intToken->value & 0xff);
                } else {
                  Throw(NOT_VALID_IDENTIFIER);
                }
              }
            } else {
              Throw(NOT_VALID_OPERATOR);
            }
          }

        } else if((strcmp(idToken->str,"f")==0)||(strcmp(idToken->str,"F")==0)){
           token = getToken(tokenizer);
                  if(token->type == TOKEN_OPERATOR_TYPE){
                    opToken = (OperatorToken *)token;
                    if(strcmp(opToken->str,",")==0){
                      token = getToken(tokenizer);
                      if(token->type == TOKEN_IDENTIFIER_TYPE){
                        idToken = (IdentifierToken *)token;
                        if(strcmp(idToken->str,"BANKED")==0){
                          return 0x1700 + (intToken->value & 0xff);
                        }
                        if(strcmp(idToken->str,"ACCESS")==0){
                          return 0x1600 + (intToken->value & 0xff);
                        }
                      }
                    }
                  }

        } else{
          Throw(NOT_VALID_IDENTIFIER);
        }
      }


    }else{
			Throw(NOT_VALID_OPERATOR);
		}
		}
	}else{
    Throw(NOT_VALID_INSTRUCTION);
}
}
}
}
