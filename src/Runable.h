#pragma once

#include "bala.h"
#include <thread>

START_BALA_NAMESPACE


class Runable
{
public:
	Runable();
	~Runable();
	void Start();
	virtual void Run();
private:
	static void ThreadMain(Runable* r);
private:
	std::thread main_thread;
};

END_BALA_NAMESPACE