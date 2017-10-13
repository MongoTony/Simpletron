#pragma once

#include "bala.h"
#include <stack>
#include <vector>
#include <map>


START_BALA_NAMESPACE

//class OpSymbol
//{
//public:
//	OpSymbol();
//	OpSymbol(char c);
//	~OpSymbol();
//	int Precedence(OpSymbol a, OpSymbol b);
//	
//private:
//	char symbol;
//	int level;//”≈œ»º∂
//
//};
class Parser
{
public:
	Parser();
	~Parser();
	void Load();
	void MidToPost();
	void IsOperator();
	int Precedence(char a,char b);
	void PrintStack();
	void StringToMid();
private:
	std::stack<char> stack;
	std::vector<char> mid_express;
	std::vector<char> postfixed_express;
	std::map<char, int> precedence_map;
};


END_BALA_NAMESPACE

