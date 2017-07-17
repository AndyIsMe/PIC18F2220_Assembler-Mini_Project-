#include "toupper.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *touppercase(char *name){
  int i = 0;
  printf("original : %s",name);
  while(name[i] != '\0'){
    name[i] = toupper(name[i]);
    i++;
  }
  printf("\nafter convert to uppercase : %s",name);
  return name;

}
