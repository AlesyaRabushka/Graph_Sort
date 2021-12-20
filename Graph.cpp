#include <iostream>
#include "Directed.h"

using namespace std;


int main() {

	graph<int> g;


	//добавление элементов
	g.add_element(8);
	g.add_element(7);
	g.add_element(6);
	g.add_element(2);


	//добавление ребер
	g.add_edge(8, 6);
	g.add_edge(6, 8);
	g.add_edge(2, 7);
	g.add_edge(7, 6);

	//вывод
	cout << "MATRIX #1" << endl;
	g.print();
	cout << endl;

	//поиск элементов
	cout << "SEARCHING OF ELEMENTS '6', '4', '2'" << endl;
	g.find_vertex(6);
	g.find_vertex(4);
	g.find_vertex(2);
	cout << endl;

	//поиск ребер
	cout << "SEARCHING OF ARCS '7-6', '2-8', '6-7'" << endl;
	g.find_edge(7, 6);
	g.find_edge(2, 8);
	g.find_edge(6, 7);
	cout << endl;

	//степени вершин и ребер
	cout << "SEARCHING OF DEGREES" << endl;
	cout << "Degree of vertex 6: " << g.vertex_degree(6) << endl;
	cout << "Degree of vertex 2: " << g.vertex_degree(2) << endl;
	cout << "Degree of vertex 6-8: " << g.edge_degree(6, 8) << endl;
	cout << "Degree of vertex 2-8: " << g.edge_degree(2, 8) << endl;
	cout << endl;

	
	//удаление ребра
	g.remove_edge(7, 6);
	cout << "MATRIX #2 AFTER REMOVING ARC '7-6' " << endl;
	g.print();
	cout << endl;

	//удаление вершины
	g.remove_element(7);
	cout << "MATRIX #3 AFTER REMOVING ELEMENT '7' " << endl;
	g.print();
	cout << endl;

	//вывод вершин графа
	cout << "ELEMENTS OF GRAPH:";
	g.print_element();
	cout << endl;

	//вторая матрица для проверки перегрузки операторов
	graph<int> g1;
	g1.add_element(1);
	g1.add_element(2);


	//проверка перегрузки операторов
	cout << g;
	cout << "\n\n";
	cout << g1;
	cout << "\n\n";


	if (g == g1)
		cout << "g == g1 " << endl;
	else
		cout << "g != g1" << endl;

	if (g > g1)
		cout << "g > g1 " << endl;
	else
		cout << "g < g1" << endl;

	return 0;
}
