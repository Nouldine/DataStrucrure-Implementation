
#include <iostream>
#include "Cpu.h"

void CPU::generate_commands()
{
	int commands;

	std::cout << "\n\nStimulation.... \n ***********************************************************************************************\n ****************************\n\n";

	// generate  random commands 1 to 5 and call cpu implement_command function
	while( 1 )
	{
		 commands = ( rand() % 5 ) + 1;

		 implement_commands( commands );

		 sleep( 1 );

	}


}// end generate_commands()


// The implement_commands will make sure that appropriate commands are assigened 

/******************************************************************************************************************************************
 * 
 * These are the five commands the function will handle
 *
 * 1. Block Running process: Move what's in Running Queue to tail of Blocked Queue, place head of Read Queue into the Rinning Queue
 *
 * 2. Preempt Running Queue process: Move  what's in Runing Queue Queue to tail of Ready Queue, place head of Read  Queue Running Queue
 *
 * 3. Unblock a blocked process: Move head of Blocked Queue to tail to tail of Running Queue
 *
 * 4. Terminate the Running Process: Remove what's in the Running  Queue; place  head of Ready Queue into Running Queue
 *
 * 5. Start a new Process: Create a new process at the tail of  the Ready Queue 
 *
 *******************************************************************************************************************************************/

void CPU::implement_commands( int commands )
{

       	 std::cout <<"Commands: " << commands << std::endl;

	 switch( commands )
	 {
		 case 1: // Running Process 

			 if( Running.get_size() == 0 ) // if Running Queue is empty then move a Ready Queue element to  Running Queue and don't block
			  {
				  if( Ready.get_size() != 0 )

					  Running.insert_node( Ready.pop_node() );

			  }

			  else // Otherwise Move Running Queue elements to Blocked Queue and move a new  Ready Queue element to Running Queue
			  {
				   Blocked.insert_node( Running.pop_node() ); 

				   if(  Ready.get_size() != 0 )

					   Running.insert_node( Ready.pop_node() );

			  }

			  print_queues();

			  break;

		 case 2: // preempt the Running process

			  if( Running.get_size() == 0 ) // if Running Queue is empty move head of Ready Queue into Running Queue 
			  {
				if( Ready.get_size() != 0 ) // If Ready Queue is not empty move its element in Running Queue
					
					Running.insert_node( Ready.pop_node() );


			  }

			  else // else move What's in Running Queue in Ready Queue and move New Ready Queue elements 	
			  {
				 Ready.insert_node( Running.pop_node() );

					 if( Ready.get_size() != 0 )  

						 Running.insert_node( Ready.pop_node() );

			  }

			  print_queues();

			  break;

		 case 3: // Unblocked a block process

			  if( Blocked.get_size() == 0 )  // Verify if Blocked Queue is empty
			  {
				  if( Running.get_size() == 0 ) // if Running Queue is empty omove head of Ready Queue Running Queue

					  if( Ready.get_size() != 0 )

						   Running.insert_node( Ready.pop_node() );

			  }

			  else // Otherwise move the Blocked Queue elements to Running Queue if only if the  Running Queue is empty 
			  {
				  if( Running.get_size() == 0 ) // The Runnning Queue is empty move the Blocked Queue element in it 
				  
					  Running.insert_node( Blocked.pop_node() );

				  else // Otherwise move the move the elements to Ready Queue 
					  
					  Ready.insert_node( Blocked.pop_node() );

			  }

			  print_queues();

			  break;

		case 4: // Terminate the Running process
			  
			  if( Running.get_size() != 0 ) // if Running Queue is not empty, the process needs to be terminated 
			  {
				   Running.pop_node();

				   if( Ready.get_size() != 0 ) // if Ready Queue is not empty move its elements in Running Queue

					   Running.insert_node( Ready.pop_node() );

			  }

			  else
			  {
				  if(  Ready.get_size() != 0 ) // Only move element if  Ready Queue isn not empty
					  
					  Running.insert_node( Ready.pop_node() );

			  }

			  print_queues();

			  break;


		 case 5: // start a new process

			  int new_process = get_new_process();

			  if( Running.get_size() != 0 ) // if Running Queue is not empty insert a new process in Ready Queue 
				  
				  Ready.insert_node( new_process );

			  else // Otherwise insert a new process in the Running Queue

				  Running.insert_node( new_process );


			  print_queues();

			  break;

	 }// end switch

}


// Use this function to generate IDs by incrementing the new_process_id

int CPU::get_new_process()
{
	 return ++new_process_id;

}


// Display all the processes with this function

void CPU::print_queues() 
{
	 std::cout << "Ready Queue: ";

	 Ready.print_queue();

	 std::cout << "Running Queue: ";

	 Running.print_queue();

	 std::cout << "Blocked Queue: ";

	 Blocked.print_queue();

}



