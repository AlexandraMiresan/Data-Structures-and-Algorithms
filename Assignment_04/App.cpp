#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
using namespace std;




int main() {
//using hashtable with open addressing and double hashing
	testAll();
	testAllExtended();

	cout << "That's all!" << endl;
	system("pause");

}



