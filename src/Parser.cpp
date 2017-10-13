#include "Parser.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <direct.h>

START_BALA_NAMESPACE

Parser::Parser()
{
	precedence_map.insert(std::make_pair('+', 1));
	precedence_map.insert(std::make_pair('-', 1));
	precedence_map.insert(std::make_pair('*', 2));
	precedence_map.insert(std::make_pair('/', 2));
	precedence_map.insert(std::make_pair('%', 2));
	precedence_map.insert(std::make_pair('^', 3));
}


Parser::~Parser()
{
}

void Parser::Load()
{
	std::string fileName;
	std::cin >> fileName;

	char   buffer[512];
	_getcwd(buffer, 512);
	std::string path(buffer);

	std::ifstream infile;
STR:std::cout << "\t Please input the file:";

	fileName = path + "\\" + fileName;

	infile.open(fileName);

	if (infile.is_open())
	{
		std::string express_text;		
		std::getline(infile, express_text);		
	}
	else
	{
		std::cout << "Open file failed! Input again!" << std::endl;
		goto STR;
	}
}
void Parser::StringToMid()
{
}
void Parser::MidToPost()
{
}

void Parser::PrintStack()
{
	while (!stack.empty())
	{	
		std::cout << stack.top();
		stack.pop();
	}
}

int Parser::Precedence(char a,char b)
{
	// 确定操作符合规
	auto iter_a = precedence_map.find(a);
	auto iter_b = precedence_map.find(b);
	if (iter_a == precedence_map.end() || iter_b == precedence_map.end())
	{
		std::cout << "invalide op!" << std::endl;
		return -9;
	}		

	if (precedence_map[a] == precedence_map[b])
	{
		return 0;
	}
	else if (precedence_map[a] > precedence_map[b])
	{
		return 1;
	}
	else
	{
		return -1;
	}

}

END_BALA_NAMESPACE
