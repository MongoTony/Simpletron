

#pragma once


#define START_BALA_NAMESPACE namespace bala{
#define END_BALA_NAMESPACE }


#define MAX_MEM_SIZE 1000

//PROG ADDR [0,50)
#define START_ADDR_PROG 0
#define END_ADDR_PROG 1000

#define PROG_ADDR(x) (START_ADDR_PROG+x)

// DATA ADDR [50,100)
#define START_ADDR_DATA 0
#define END_ADDR_DATA 1000
#define DATA_ADDR(x) (START_ADDR_DATA+x)

#define MAX_NUM 9999
#define MIN_NUM -9999

#define CTRL_END_INPUT -99999

typedef int Register;


/**
*@指令头文件定义宏
*/
#define INS_REG_H(X)  class INS_##X:public Instruction\
	{	virtual void Work(Simpletron &sim);}

/**
*@友元类宏
*/
#define INS_REG_FRIEND(X) friend class INS_##X


