#pragma once
#include "bala.h"
#include "Runable.h"
#include "Instruction-def.h"
#include <vector>
#include <map>
START_BALA_NAMESPACE

class Instruction;

struct Word
{
	unsigned code;
	unsigned arg;
};

class Simpletron
	:public Runable
{
	friend class Instruction;
	INS_REG_FRIEND(READ);
	INS_REG_FRIEND(WRITE);
	INS_REG_FRIEND(LOAD);
	INS_REG_FRIEND(STORE);
	INS_REG_FRIEND(ADD);
	INS_REG_FRIEND(SUBTRACT);
	INS_REG_FRIEND(DIVIDE);
	INS_REG_FRIEND(MULTIPLY);
	INS_REG_FRIEND(BRANCH);
	INS_REG_FRIEND(BRANCHNEG);
	INS_REG_FRIEND(BRANCHZERO);
	INS_REG_FRIEND(HUT);
public:
	Simpletron();
	~Simpletron();

	void Run();
private:
	void Welcome();
	void LoadFromFile();
	void SwitchIns();
	void Execute();
	void Show();

	void Init_ins_map();
private:
	std::vector<int> memory;
	Register accumulator;
	Register instruction;
	int counter;
	Word word;
	Instruction *curr_ops;
	bool request_stop;
	bool runtime_error;

	std::map<std::string, unsigned> ins_map;
};

END_BALA_NAMESPACE

