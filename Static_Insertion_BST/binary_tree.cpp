
#include <iostream> 
#include "Binary_tree.h"

// This function is used to manually insert 
// numbers in the Binary Search Tree according to its
// Properties

int  Binary_tree::insert_node()
{
	Tree = new Node< int >( 50 ); // insert 50 at the root of tree

	Tree->left = new Node< int >( 40 ); // insert in the left subtree

	Node< int >* tmp = Tree->left; // store left subtree in tmp

	tmp = new Node< int >( 20 ); // insert in the left subtree

	Tree->left->left = tmp; // insert in the left subtree 

	Tree->right = new Node< int >( 60 ); // insert in the right subtree

	Tree->right->right = new Node< int > ( 75 ); // insert in the right subtree
	
	tmp = new Node< int >( 85 );
	
	Tree->right->right->right = tmp; // insert in the right subtree

	tmp = new Node< int >( 90 ); // insert in tmp

	Tree->right->right->right->right = tmp; // insert in the right subtree 

}

/* This function is used to print the content 
 * of the Tree from the left Subtree to Right Subtree
 *
 * @param: Tree is a list of integers
 */

int Binary_tree::tree_contain( Node< int >* Tree )
{
	
	if( Tree == nullptr )  //  if the Tree is empty return 0
	
		return 0;


	else // Otherwise return the contain of the tree starting from the root element 
	{
		std::cout << Tree->data << " ";
			
			tree_contain( Tree->left );
			tree_contain( Tree->right );

		std::cout << std::endl;
			
	} // end else


} // end function

/* This function is used to sum the contain of the Tree element 
 * From left to right
 *
 * @param: List that is a list of integers 
 *
 */

int Binary_tree::node_sum( Node< int >* List )
{
	 if( List == nullptr ) // return 0 if the list is empty

		 return 0;

	 else // Sum the contain of the linked list starting by the root element

		 return ( List->data + node_sum( List->left ) + node_sum( List->right ) );

}// end function





