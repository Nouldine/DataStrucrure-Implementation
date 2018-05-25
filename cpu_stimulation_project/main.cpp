

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "queue.cpp"
//#include "cpu.cpp"

#include "cpu_command.cpp"


int main()
{
	CPU cpu;

	cpu.generate_commands();

}
