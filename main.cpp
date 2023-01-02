//#include <iostream>
//#include "AVL.h"
//#include "hash.h"
//#include "AVL.h"
//#include "linkedlist.h"
//using namespace std;
//int main() {
	//tree a;
	//a.avlCSVparser("ecom.csv");
	//node* root = a.getRoot();
	//a.preorder(root);
	//foo("test.csv");
	//tree b;
	//b.avlCSVparser_2("ecom.csv");
	//node* root = b.getRoot();
	//b.preorder(root);
	//int* arr = new int;
	//Hash__ obj;
	//obj.insert("ecom.csv", arr);
	//LinkedList a;
	//a.CSVparser("ecom.csv");
	//a.print();
//}

#include "hash.h"



int main() {
    int* values = converter();

    // Print the integer values
    for (int i = 0; i < MAX_VALUES; i++) {
        cout << values[i] << endl;
    }

    return 0;
}

