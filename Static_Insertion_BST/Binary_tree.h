
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_


template < typename Item_Type >


struct Node
{
	 Item_Type data; // item in the linked list

	 Node* left; // pointer for the left subtree

	 Node* right; // pointer for the right subtree

	 // constructor for Node 
	 Node( const Item_Type& data_item, Node* left_child = nullptr, Node* right_child = nullptr ): 
		 data{ data_item }, left{ left_child }, right{ right_child } { }

	 ~Node()
	 {
		 delete  left; 

		 delete  right; 
	 }

};


class Binary_tree
{

	public:

		int display_tree()  // function to print TREE content
		{
			return tree_contain( Tree );

		}

		int display_node_sum() // function to do the summing of the TREE elements 
		{
			std::cout <<" The Sum is: " << node_sum( Tree ) << std::endl;
		}

		int insert_node(); // insertion function 

		int tree_contain( Node< int >* ); 

		int node_sum( Node< int >* ); // function to do the sum of the list 
		
	private:

		Node< int >* Tree;

};

#endif
