#include <iostream>
#include "Sort.h"
#include <vector>

using namespace std;


int main() {
	
	int a[5] = { 6, 8, 3, 9, 11 };
	//double a[6] = { 2.1, 4.5, 7.3, 4.05, 2.16, 7.2 };
	//vector<int> a = {6, 2, 5, 1, 3, 11};
	//vector<double> a = {4.3, 4.7, 5.9, 2.3, 2.4};


	GnomeSort<int> s(a, 6);
	
	s.Sort();
	s.Print();

	return 0;
}