

#include "Runable.h"
#include <iostream>

START_BALA_NAMESPACE


Runable::Runable()
{
}


Runable::~Runable()
{
}

void Runable::Start()
{
	main_thread = std::thread(ThreadMain,this);	
	main_thread.join();
}
void Runable::Run()
{
	std::cout << "Need to override this function:Run()" << std::endl;

}
void Runable::ThreadMain(Runable *r)
{
	r->Run();
}

END_BALA_NAMESPACE