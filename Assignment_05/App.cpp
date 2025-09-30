
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;

//Matrix - represented as  a sparse matrix <line,column,value> triples (value != 0) are memorized.
//The elements are stored in a BST with linked representation with dynamic allocation.
int main() {


	testAll();
	testAllExtended();
	cout << "That's All..." << endl;
	system("pause");
}