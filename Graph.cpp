#include <iostream>
#include "Undirected.h"
#include "Directed.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");


	graph<int> g;
	
	g.add_element(1);
	g.add_element(2);
	g.add_element(3);
	g.add_element(4);
	
	g.add_edge(1, 2);
	g.add_edge(3, 4);
	
	graph<int> g1;
	g1.add_element(9);
	
	g1 = g;
	
	if (g != g1) cout << "no" << endl;
	else cout << "yes" << endl;
	
	cout << g;
	return 0;
}
