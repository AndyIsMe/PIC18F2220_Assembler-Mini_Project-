#ifndef _ASSEMBLYCODE_H
#define _ASSEMBLYCODE_H
#include "Tokenizer.h"
#include "Token.h"
#include "checkregister.h"


int addlw(char *instr,char**memoryPtr);
int addwf(char *instr,char**memoryPtr);
int addwfc(char *instr,char**memoryPtr);
int andlw(char *instr,char**memoryPtr);
int andwf(char *instr,char**memoryPtr);
int bc(char *instr,char**memoryPtr);
int bn(char *instr,char**memoryPtr);
int bnc(char *instr,char**memoryPtr);
int bnn(char *instr,char**memoryPtr);
int bnov(char *instr,char**memoryPtr);
int bnz(char *instr,char**memoryPtr);
int bov(char *instr,char**memoryPtr);
int bra(char *instr,char**memoryPtr);
int bz(char *instr,char**memoryPtr);
int bcf(char *instr,char**memoryPtr);
int bsf(char *instr,char**memoryPtr);
int btfsc(char *instr,char**memoryPtr);
int btfss(char *instr,char**memoryPtr);
int btg(char *instr,char**memoryPtr);
int call(char *instr,char**memoryPtr);
int clrf(char *instr,char**memoryPtr);
int clrwdt(char *instr,char**memoryPtr);
int comf(char *instr,char**memoryPtr);
int cpfseq(char *instr,char**memoryPtr);
int cpfsgt(char *instr,char**memoryPtr);
int cpfslt(char *instr,char**memoryPtr);
int daw(char *instr,char**memoryPtr);
int decf(char *instr,char**memoryPtr);
int decfsz(char *instr,char**memoryPtr);
int dcfsnz(char *instr,char**memoryPtr);
int _goto(char *instr,char**memoryPtr);
int incf(char *instr,char**memoryPtr);
int incfsz(char *instr,char**memoryPtr);
int infsnz(char *instr,char**memoryPtr);
int iorlw(char *instr,char**memoryPtr);
int movlb(char *instr,char**memoryPtr);
int movlw(char *instr,char**memoryPtr);
int movwf(char *instr,char**memoryPtr);
int movf(char *instr,char**memoryPtr);
int movff(char *instr,char**memoryPtr);
int mullw(char *instr,char**memoryPtr);
int mulwf(char *instr,char**memoryPtr);
int negf(char *instr,char**memoryPtr);
int pop(char *instr,char**memoryPtr);
int push(char *instr,char**memoryPtr);
int reset(char *instr,char**memoryPtr);
int rlcf(char *instr,char**memoryPtr);
int rlncf(char *instr,char**memoryPtr);
int rrcf(char *instr,char**memoryPtr);
int retfie(char *instr,char**memoryPtr);
int _return(char *instr,char**memoryPtr);
int setf(char *instr,char**memoryPtr);
int sleep(char *instr,char**memoryPtr);
int sublw(char *instr,char**memoryPtr);
int subwf(char *instr,char**memoryPtr);
int subwfb(char *instr,char**memoryPtr);
int subfwb(char *instr,char**memoryPtr);
int swapf(char *instr,char**memoryPtr);
int tblrd_star(char *instr,char**memoryPtr);
int tblrd_star_plus(char *instr,char**memoryPtr);
int tblrd_star_minus(char *instr,char**memoryPtr);
int tblrd_plus_star(char *instr,char**memoryPtr);
int tblwt_star(char *instr,char**memoryPtr);
int tblwt_star_plus(char *instr,char**memoryPtr);
int tblwt_star_minus(char *instr,char**memoryPtr);
int tblwt_plus_star(char *instr,char**memoryPtr);
int tstfsz(char *instr,char**memoryPtr);
int xorlw(char *instr,char**memoryPtr);
int xorwf(char *instr,char**memoryPtr);


#endif // _ASSEMBLYCODE_H
