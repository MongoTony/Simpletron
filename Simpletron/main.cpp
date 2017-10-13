

#include <iostream>
#include <thread>
#include "Simpletron.h"

int main()
{

	//std::cout << "Hello,Bala" << std::endl;


	bala::Simpletron machine;
	machine.Start();
	//machine.Show();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}