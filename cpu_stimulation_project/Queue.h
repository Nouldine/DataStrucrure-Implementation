
#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h>

#ifndef QUEUE_H
#define QUEUE_H

template< typename Item_Type > 
 
struct Node
{

	Item_Type data; 

	Node* next; // pointer to the next element in the queue
	
	Node( const Item_Type& data_item, Node* next_ptr = NULL ): 
		
		data{ data_item }, next { next_ptr } { }


};


class Queue
{
	
	public:

		Queue()
		{
			  Q = nullptr; 

			  size = 0;
 
		}
	

		void insert_node( int  ); // constructor to insert an int into queue
		
		int pop_node(); // function to delete item from the queue

		void print_queue(); // function to print elements in the queue
		
		int increase_size(); // function to increase the queue size

		int decrease_size(); // function to decrease the queue size 

		int get_size() // function to get the size of the queue
		{
			return this->size; 

		}

	private:

		Node< int >* Q; 

		int size; 
};

#endif
