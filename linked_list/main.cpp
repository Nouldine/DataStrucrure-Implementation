
#include "read_store.cpp"

int main()
{
	Store R; // create an object of the Read_store class

	std::vector< int > vec{ 1, 2, 4, 5, 7, 8, 9, 10, 12, 13, 16, 18, 20 };
	
	Node< int >* list;

	for( auto it = vec.begin(); it != vec.end(); ++it)

		list = new Node< int >( *it, list );


	R.print_list( list ); 
	
	R.even_nodes_sum( list );

	R.odd_nodes_sum( list );
	

	return 0;
}
