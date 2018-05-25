
#include <iostream> 
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>

#include "Queue.h"

class CPU
{
	public:

		CPU()
		{
			new_process_id = 0; // set the process id to 0
		}

		void  generate_commands(); // function to generate commands

		void implement_commands( int ); // function to implement cpu command

		void print_queues(); 	// function to print the content of the queues

		int get_new_process(); // function to get new process id


	private: 

		Queue Running; // Running Queue
		
		Queue Ready; // Ready Queue

		Queue Blocked; // Blocking Queue

		int new_process_id; // new process id

};
