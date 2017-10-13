

#include "Instruction.h"
#include "Simpletron.h"
#include <iostream>


START_BALA_NAMESPACE


Instruction::Instruction()
{

}
Instruction::~Instruction()
{
}
void Instruction::Work(Simpletron &sim)
{
	std::cout << "make sure the instruction is the son the mine!" << std::endl;
}
Word Instruction::Parse(Register ins_reg)
{
	Word word;
	word.code = ins_reg / 100;
	word.arg = ins_reg % 100;
	return word;
}

void INS_READ::Work(Simpletron &sim)
{
	std::cout << "\t please input a number (which will write memory address offset (" << sim.word.arg << ") base(" << START_ADDR_DATA<<"):";
	int n=0;
	std::cin >> n;
	if (std::cin.fail())
	{
		std::cout << "\t Error:input invalid !" << std::endl;
		sim.runtime_error = true;
	}
	else
	{
		sim.memory[DATA_ADDR(sim.word.arg)] = n;
	}
	
}
void INS_WRITE::Work(Simpletron &sim)
{
	std::cout <<"\t "<< sim.memory[DATA_ADDR(sim.word.arg)]<<std::endl;
}
void INS_LOAD::Work(Simpletron &sim)
{
	sim.accumulator = sim.memory[DATA_ADDR(sim.word.arg)];
}
void INS_STORE::Work(Simpletron &sim)
{
	sim.memory[DATA_ADDR(sim.word.arg)] = sim.accumulator;
}
void INS_ADD::Work(Simpletron &sim)
{
	sim.accumulator += sim.memory[DATA_ADDR(sim.word.arg)];	
}
void INS_SUBTRACT::Work(Simpletron &sim)
{
	sim.accumulator = sim.accumulator-sim.memory[DATA_ADDR(sim.word.arg)] ;
}
void INS_DIVIDE::Work(Simpletron &sim)
{
	if (sim.accumulator != 0)
	{
		sim.accumulator = sim.memory[DATA_ADDR(sim.word.arg)] / sim.accumulator;
	}
	else
	{
		std::cout << "Can't Divide by zero!" << std::endl;
		sim.request_stop = true;
		sim.runtime_error = true;
	}
}
void INS_MULTIPLY::Work(Simpletron &sim)
{
	sim.accumulator = sim.accumulator*sim.memory[DATA_ADDR(sim.word.arg)];
}
void INS_BRANCH::Work(Simpletron &sim)
{
	if (PROG_ADDR(sim.word.arg) < END_ADDR_PROG && PROG_ADDR(sim.word.arg) >= START_ADDR_PROG)
	{
		sim.counter = PROG_ADDR(sim.word.arg);
	}
	else
	{
		sim.runtime_error = true;
		sim.request_stop = true;
	}
	
}
void INS_BRANCHNEG::Work(Simpletron &sim)
{
	if (sim.accumulator >= 0)
		return;

	if (PROG_ADDR(sim.word.arg) < END_ADDR_PROG && PROG_ADDR(sim.word.arg) >= START_ADDR_PROG)
	{
		sim.counter = PROG_ADDR(sim.word.arg);
	}
	else
	{
		sim.runtime_error = true;
		sim.request_stop = true;
	}
}
void INS_BRANCHZERO::Work(Simpletron &sim)
{
	if (sim.accumulator != 0)
		return;

	if (PROG_ADDR(sim.word.arg) < END_ADDR_PROG && PROG_ADDR(sim.word.arg) >= START_ADDR_PROG)
	{
		sim.counter = PROG_ADDR(sim.word.arg);
	}
	else
	{
		sim.runtime_error = true;
		sim.request_stop = true;
	}
}
void INS_HUT::Work(Simpletron &sim)
{
	std::cout << "* * * Simpletron execution tenminated * * *" << std::endl;
	sim.request_stop = true;
}



END_BALA_NAMESPACE