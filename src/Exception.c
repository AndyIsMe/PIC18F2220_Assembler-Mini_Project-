#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>
#include "Exception.h"
#include "CException.h"
#include "Token.h"

void dumpErrorMessage(Exception *e, int lineNo) {
  Token *token = (Token *)e->data;
  int i = token->length - 1;
  if(i < 0) i = 0;

  printf("Error %d:\n", lineNo);
  printf("%s\n", e->msg);
  printf("%s\n", token->originalStr);
  printf("%*s", token->startColumn + 1, "^");
  while(i--)
    printf("~");
  putchar('\n');
}

void throwException(int errorCode, void *data, char *message, ...) {
  va_list args;
  char *buffer;
  int length;
  Exception *e;

  va_start(args, message);
  e = malloc(sizeof(Exception));

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length + 1);
  vsnprintf(buffer, length + 1, message, args);

  e->msg = buffer;
  e->errorCode = errorCode;
  e->data = data;

  Throw(e);
}

void freeException(Exception *e) {
  if(e) {
    if(e->msg)
      free(e->msg);
    free(e);
  }
}

void dumpException(Exception *e) {
  printf("%s (err=%d)\n", e->msg, e->errorCode);
}
