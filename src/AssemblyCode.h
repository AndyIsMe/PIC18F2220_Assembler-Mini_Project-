#ifndef _ASSEMBLYCODE_H
#define _ASSEMBLYCODE_H
#include "Tokenizer.h"
#include "Token.h"

int addlw(char *instr);
int addwf(char *instr);
int addwfc(char *instr);
int andlw(char *instr);
int andwf(char *instr);
int bc(char *instr);
int bn(char *instr);
int bnc(char *instr);
int bnn(char *instr);
int bnov(char *instr);
int bnz(char *instr);
int bov(char *instr);
int bz(char *instr);
int bcf(char *instr);
int bsf(char *instr);
int btfsc(char *instr);
int btfss(char *instr);
int btg(char *instr);
int clrf(char *instr);
int clrwdt(char *instr);
int comf(char *instr);
int cpfseq(char *instr);
int cpfsgt(char *instr);
int cpfslt(char *instr);
int daw(char *instr);
int iorlw(char *instr);
int movlw(char *instr);
int movwf(char *instr);
int mullw(char *instr);
int mulwf(char *instr);
int negf(char *instr);
int pop(char *instr);
int push(char *instr);
int reset(char *instr);
int setf(char *instr);
int sleep(char *instr);
int sublw(char *instr);
int tblrd_star(char *instr);
int tblrd_star_plus(char *instr);
int tblrd_star_minus(char *instr);
int tblrd_plus_star(char *instr);
int tblwt_star(char *instr);
int tblwt_star_plus(char *instr);
int tblwt_star_minus(char *instr);
int tblwt_plus_star(char *instr);
int tstfsz(char *instr);
int xorwf(char *instr);






#endif // _ASSEMBLYCODE_H
