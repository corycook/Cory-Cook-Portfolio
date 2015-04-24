#include "VirtualMachine.h"


VirtualMachine::VirtualMachine()
{
	mem = new int16[MEM_SIZE];
	r = new int16[REG_FILE_SIZE];
}


VirtualMachine::~VirtualMachine()
{
}
