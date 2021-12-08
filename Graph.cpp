#include <iostream>
#include "Undirected.h"
#include "Directed.h"

using namespace std;


int main() {

	graph<int> g;
	
	g.add_element(8);
	g.add_element(7);
	g.add_element(6);
	g.add_element(2);
	
	g.add_edge(7, 6);
	g.add_edge(8, 6);
	g.add_edge(8, 6);
	g.add_edge(2, 7);
	g.print();
	g.remove_edge(7, 6);
	g.remove_element(7);
	cout << "Matrix: " << endl;
	g.print();
	cout << "Elements: ";
	g.print_element();

	return 0;
}