
#ifndef READSTORE_H
#define READSTORE_H

#include <fstream>
#include <vector>
#include <iostream>

template< typename Item_Type >


struct Node
  {

    Item_Type data;// data pointed
    Node* next; // the pointer to the next node
    Node(const Item_Type& data_item, Node* next_ptr = NULL):
             data(data_item), next(next_ptr){}

};

class Store
{ 

	private:

   		int num; // variable of number of data in file

   		Node<int>* list; // pointer to store data in file
	public :

	   int print_odd_node_sum() // function to print sum
  	   { 

	  	std::cout <<"\n"  << "The odd sum is : " << (odd_nodes_sum( list )) << std::endl; // print out the sum of nodes


  	    }

  	   int print_even_node_sum() // function to print sum
	   { 

		   std::cout<< "The even sum : "<<( even_nodes_sum( list ) )<< std::endl; // print the even sum

  	   }

  	   int display_list() // function to print list
	   { 

  		 return  print_list( list ); // return data in file
	

	    }



     int read_data(); // read data in file
     int odd_nodes_sum( Node<int>* list ); //  function to sum odd nodes
     int even_nodes_sum( Node<int>* list );  // function to sum even nodes
     int print_list( Node<int>* list); // function to print list content 

};


#endif
