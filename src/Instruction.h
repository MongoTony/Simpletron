#pragma once

#include "bala.h"



START_BALA_NAMESPACE

struct Word;
class Simpletron;

class Instruction
{
public:
	Instruction();
	~Instruction();
	virtual void Work(Simpletron &sim);
	static Word Parse(Register ins_reg);//处理指令寄存器中指令
	
private:
	//int oper_code;
	//int oper_arg;
	
};


INS_REG_H(READ);
INS_REG_H(WRITE);
INS_REG_H(LOAD);
INS_REG_H(STORE);
INS_REG_H(ADD);
INS_REG_H(SUBTRACT);
INS_REG_H(DIVIDE);
INS_REG_H(MULTIPLY);
INS_REG_H(BRANCH);
INS_REG_H(BRANCHNEG);
INS_REG_H(BRANCHZERO);
INS_REG_H(HUT);


END_BALA_NAMESPACE