#include "Simpletron.h"
#include "Instruction.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>

#include <direct.h>

START_BALA_NAMESPACE

Simpletron::Simpletron()
{
	memory.resize(MAX_MEM_SIZE);
	accumulator = 0;
	instruction =0;
	counter =0 ;
	curr_ops = NULL;
	request_stop = false;
	runtime_error = false;

	Init_ins_map();
}

Simpletron::~Simpletron()
{
}

void Simpletron::Run()
{
	Welcome();
	LoadFromFile();
	Execute();
}


void Simpletron::Welcome()
{
	std::cout << "* * * Welcome to Simpletron!  * * *" << std::endl;	
};
void Simpletron::LoadFromFile()
{
	STR:
	std::cout << "\t Please input the program file:";
	std::string fileName;
	std::cin >> fileName;

	char   buffer[512];
	_getcwd(buffer, 512);
	std::string path(buffer);

	fileName = path + "\\"+fileName;

	std::ifstream infile;
	infile.open(fileName);
	
	if (infile.is_open())
	{
		int ins;
		int i=0;
		while (infile >> ins)
		{
			//终止载入标志
			if (ins == CTRL_END_INPUT)
			{
				break;
			}	
			//指令合规检查
			if (MIN_NUM < ins&& ins < MAX_NUM)
			{
				memory[PROG_ADDR(i)] = ins;
				i++;
			}
			else
			{
				runtime_error = true;
				request_stop = true;
				std::cout << "* * * Attempt to load Invalid Instruction * * * " << std::endl;
				return;
			}
			
			if (PROG_ADDR(i) >= END_ADDR_PROG)
			{
				std::cout << "Out of END_ADDR_PROG of memory size!" << std::endl;
				runtime_error = true;
				request_stop = true;
				return;
			}
		};
		std::cout << "* * * Program loading completed! * * *"<<std::endl;
	}
	else
	{
		std::cout << "Open file failed! Input again!" << std::endl;
		goto STR;
	}
};
void Simpletron::SwitchIns()
{
	switch (word.code)
	{
	case READ:
		curr_ops = new INS_READ(); break;
	case WRITE:
		curr_ops = new INS_WRITE(); break;
	case LOAD:
		curr_ops = new INS_LOAD(); break;
	case STORE:
		curr_ops = new INS_STORE(); break;
	case ADD:
		curr_ops = new INS_ADD(); break;
	case SUBTRACT:
		curr_ops = new INS_SUBTRACT(); break;
	case DIVIDE:
		curr_ops = new INS_DIVIDE(); break;
	case MULTIPLY:
		curr_ops = new INS_MULTIPLY(); break;
	case BRANCH:
		curr_ops = new INS_BRANCH(); break;
	case BRANCHNEG:
		curr_ops = new INS_BRANCHNEG(); break;
	case BRANCHZERO:
		curr_ops = new INS_BRANCHZERO(); break;
	case HUT:
		curr_ops = new INS_HUT(); break;	
	default:
		curr_ops = NULL; runtime_error = true; request_stop = true;
		break;
	}
};
void Simpletron::Execute()
{
	std::cout << "* * * Progtam execution begins * * *" << std::endl;
	while (!request_stop && counter <END_ADDR_PROG)
	{
		
		instruction = memory[PROG_ADDR(counter)];
		++counter;
		word = Instruction::Parse(instruction);
		SwitchIns();
		if (curr_ops != NULL)
		{
			curr_ops->Work(*this);
		}
	}
	Show();
};
void Simpletron::Show()
{
	std::cout << "REGISTERS:" << std::endl;
	std::cout.setf(std::ios::left);
	std::cout << std::setw(25) << "accumulator";
	std::cout.setf(_IOSshowpos);
	std::cout << std::setw(5) << accumulator<<std::endl;

	std::cout.unsetf(_IOSshowpos);
	std::cout << std::setw(25) << "counter";
	std::cout << std::setw(2) << counter << std::endl;

	std::cout << std::setw(25) << "runtime_error";
	std::cout << std::setw(2) << runtime_error << std::endl;

	std::cout << std::setw(25) << "request_stop";
	std::cout << std::setw(2) << request_stop << std::endl;

	std::cout << std::setw(25) << "instruction";
	std::cout.setf(_IOSshowpos);
	std::cout << std::setw(5) << instruction << std::endl;

	std::cout.unsetf(_IOSshowpos);
	std::cout << std::setw(25) << "word.code";
	std::cout << std::setw(2) << word.code<<std::endl;

	std::cout << std::setw(25) << "word.arg";
	std::cout << std::setw(2) << word.arg << std::endl;

	std::cout << "MEMORY:" << std::endl;

	std::cout.setf(std::ios::right);
	std::cout << std::setw(2) << " ";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << std::setw(8) << i;
	}
	std::cout<<std::endl;

	
	for (int j = 0; j < 10; ++j)
	{
		std::cout << std::setw(2) << 10*j;
		std::cout.setf(_IOSshowpos);
		for (int k = 0; k < 10; ++k)
		{
			std::cout <<std::setw(8)<< memory[j * 10 + k];
		}
		std::cout << std::endl;
		std::cout.unsetf(_IOSshowpos);
	}
};
void Simpletron::Init_ins_map()
{
	ins_map.insert(std::make_pair("READ", 10));
	ins_map.insert(std::make_pair("WRITE", 11));
	ins_map.insert(std::make_pair("LOAD", 20));
	ins_map.insert(std::make_pair("STORE", 21));
	ins_map.insert(std::make_pair("ADD", 30));
	ins_map.insert(std::make_pair("SUBTRACT", 31));
	ins_map.insert(std::make_pair("DIVIDE", 32));
	ins_map.insert(std::make_pair("MULTIPLY", 33));
	ins_map.insert(std::make_pair("BRANCH", 40));
	ins_map.insert(std::make_pair("BRANCHNEG", 41));
	ins_map.insert(std::make_pair("BRANCHZERO", 42));
	ins_map.insert(std::make_pair("HUT", 43));
}

END_BALA_NAMESPACE