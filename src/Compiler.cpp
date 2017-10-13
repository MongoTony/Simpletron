#include "Compiler.h"


#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>

#include <direct.h>

START_BALA_NAMESPACE
Compiler::Compiler()
{
}


Compiler::~Compiler()
{
}

void Compiler::Load()
{
	std::string fileName;
	std::cin >> fileName;

	char   buffer[512];
	_getcwd(buffer, 512);
	std::string path(buffer);

	fileName = path + "\\" + fileName;

	std::ifstream infile;
	infile.open(fileName);

	if (infile.is_open())
	{
		std::string text;
		int i = 0;
		while (infile >> text)
		{
		}
	}
}


END_BALA_NAMESPACE