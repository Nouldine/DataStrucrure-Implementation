

#include "Read_store.h"
#include <fstream>
#include<iostream>


int main() { 
    
    
     Store R; //create a Store object
     R.read_data();  //function to read data from file
     R.display_list(); // function to display list contain
     
     std::cout << "\n" << std::endl; 

     R.print_even_node_sum(); // function to sum even nodes
     R.print_odd_node_sum(); // function to sum odd nodes
    
    
}

int Store::read_data() {
  
     int data; // variable for data in file
     
     std::ifstream inFile; 
   
     inFile.open("number.txt");// open the file

     inFile >> num;  // read number of data
    
     //  get data from the file and insert them in
     //  the list
     for (int i = 0 ; i < num; ++i )
     { 
       	 inFile >> data; // read data in file 
         
     	 list = new Node<int>( data, list ); // store the data in linked list

      }// end for loop


} // end function
  
int Store::print_list( Node<int>* list ){

    if( list == NULL) // recursive base case
 
           return 0;
      
    else
    {
	    std::cout<< list->data << " ";

	    return  print_list( list->next );// print out the next nodes
	    
	    std::cout << std::endl;     

     } 
} 

 
int Store::odd_nodes_sum( Node<int>* list ) { 
   
    // verify if the next node is null
   if( list->next== NULL )  
       
          return list->data; // return data
     
   else
          return ( list->data + odd_nodes_sum( list->next->next ) );  // return the sum of the next nodes           

    
}

int Store::even_nodes_sum( Node<int>* list ) {

    if ( list == NULL )
          
	    return 0;

 
    else if( list->data % 2 != 0 )  // verify the data is an even
              
    
          return ( 0 +  even_nodes_sum( list->next ) ); // return the sum of even


    else
              
         return ( list->data + even_nodes_sum( list->next ) ); // sum the nodes that are evens

 }
 
 


