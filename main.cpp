#include <iostream>
#include "AVL.h"
using namespace std;
int main() {
	tree a;
	a.avlCSVparser("test.csv");
	//a.insert("Value i inserted");
	node* root = a.getRoot();
	a.preorder(root);
}
