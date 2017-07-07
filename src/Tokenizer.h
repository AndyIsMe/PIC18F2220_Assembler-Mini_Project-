#ifndef _TOKENIZER_H
#define _TOKENIZER_H
#include "Common.h"
#include "Token.h"

INLINE Token *advanceToken(Tokenizer *tokenizer);
INLINE Token *getToken(Tokenizer *tokenizer);
INLINE Token *peepToken(Tokenizer *tokenizer);


#endif // _TOKENIZER_H

