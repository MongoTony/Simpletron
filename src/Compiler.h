#pragma once
#include "bala.h"

START_BALA_NAMESPACE

class Compiler
{
public:
	Compiler();
	~Compiler();

	void Load();
	void Compile();
	void Save();
private:


};

END_BALA_NAMESPACE