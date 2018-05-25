
#include "Queue.h"

// This function is used to insert item in the Queue
// @param: item is the element that will be inserted in the
//		queue
void Queue::insert_node( int item )
{
 	if( item > 0 ) {

		Q = new Node< int >( item, Q ); 

		increase_size();

	}


}

// this function is used to remove item
// from the front of the node

int Queue::pop_node()
{
	Node< int >* tmp = Q;

	// if the Queue is empty return 0

	if( Q == nullptr )
		
		return 0; 

	decrease_size(); // decrement the size of the queue if queue is not empty

	// Verify if the tmp->next == nullptr, if so 
	// next is the last element in the list
	
	if( tmp->next == nullptr ) 
	{
		int node = tmp->data;

		delete tmp;

		Q = nullptr; // now Q points to null 

		return node; 
	
	} // end if 

	// Make sure that elements in the 
	// queue are being checked to ensure 
	// a perfect removal using the while loop 
	while( tmp->next->next != nullptr )
	
		tmp = tmp->next; // move to the next node

	// assigned the next node to a new location
	Node< int >* node_to_delete = tmp->next;

	// point tmp to nullptr
	tmp->next = nullptr;

	//  get the value from the node_to_delete 
	//  to  return it before remove it
	int new_node = node_to_delete->data;

	// remove the node the node
	delete node_to_delete; 

	//  return the value
	return new_node;

}// end pop_node()

// this function is used to print the content of the queue
void Queue::print_queue()
{
	Node< int >* tmp = Q;

	std::cout << "The size is: " << get_size() << std::endl;

	while( tmp != nullptr )
	{
		std::cout << tmp->data << " "; // print out the data

		tmp = tmp->next; // advance the pointer

	}

	std::cout << std::endl; 

} // end print_queue()


// This function is used to increase the size 
// the contenaire when elements are added

int Queue::increase_size()
{
	 this->size += 1; 

} // end increase_size()


// This function is used to decrease the size of 
// the contenaire when elements are removed 

int Queue::decrease_size()
{
	this->size -= 1;

} // end decrease_size() 
























