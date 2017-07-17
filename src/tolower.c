#include "tolower.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char *tolowercase(char *name){
  int i = 0;
  printf("original : %s",name);
  while(name[i] != '\0'){
    name[i] = tolower(name[i]);
    i++;
  }
  printf("\nafter convert to uppercase : %s",name);
  return name;

}
