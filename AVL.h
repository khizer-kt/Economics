#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class node {
public:
	node* Lchild;
	node* Rchild;
	string data;
};
class tree {
public:
	node* loc;
	node* ploc;
	node* root;
	//Functions:
	tree();
	bool isEmpty();
	void search(string value);
	void insert(string value);
	void preorder(node* root);
	void postorder(node* root);
	void inorder(node* root);
	int HeightOfTree(node* root);
	int DepthOfTree(node* root, int ParentDepth);
	void DestroyTree(node* root);
	void DeleteNode(string Value);
	int HeightDifference(node* alpha);
	void AVLcaller(node* root1, node* parent);
	void AVLconverter(node* root2, node* parent);
	void avlCSVparser(string filename);
	node* getRoot();
	void test(node* root);
	void avlCSVparser_2(string filename);
};
tree::tree() { //CONSTRUCTOR
	loc = NULL;
	ploc = NULL;
	root = NULL; 
	//this will ensure that every time a new tree is created the above attributes are set to NULL
}
bool tree::isEmpty() {
	return root = NULL; //Return true if root equals to NULL
}
void tree::search(string value) {
	ploc = NULL;
	loc = root;
	while (loc != NULL && loc->data != value) {
		if (loc->data > value) {
			ploc = loc;
			loc = loc->Lchild;
		}
		else {
			ploc = loc;
			loc = loc->Rchild;
		}
	}
}
 /*
  ploc is used to store the address of the parent node of the current node being searched,
  loc is used to store the address of the current node being searched.
  */
/*In this code, the comparison is being used to determine whether to continue searching in the left or right subtree of the current node.
If loc->data is greater than value,
it means that the value being searched for is somewhere in the left subtree of the current node, so the search should continue in that subtree. 
Otherwise, the value is somewhere in the right subtree, and the search should continue in that subtree.*/
void tree::insert(string value) {
	//cout << "Before Search called" << endl;
	search(value);
	//cout << "Search called" << endl;
	if (loc == NULL) {
		//cout << "loc is null" << endl;
		node* nn = new node();
		nn->data = value;
		if (ploc == NULL && root == NULL) { //checks if tree is empty
			//cout << "Root and Ploc are null";
			root = nn;
			//cout << "Inner if" << endl;
			//cout << root->data;
		}
		else {
			if (value < ploc->data) {
				ploc->Lchild = nn;
				//cout << "Caller";
				//cout << ploc->data;
			}
			else {
				//cout << "Caller2";
				ploc->Rchild = nn;
				//cout << ploc->data;
			}
		}
	}
}
void tree::preorder(node* root) {
	//cout << "Test" << endl;
	if (root != NULL) {
		cout << root->data << " \n";
		preorder(root->Lchild);
		preorder(root->Rchild);
	}
}
void tree::postorder(node* root) {
	if (root != NULL) {
		postorder(root->Lchild);
		postorder(root->Rchild);
		cout << root->data << " ";
	}
}
void tree::inorder(node* root) {
	if (root != NULL) {
		inorder(root->Lchild);
		cout << root->data << " ";
		inorder(root->Rchild);
	}
}
int tree::HeightOfTree(node* root) {
	if (root == NULL) {
		return -1;
	}
	else {
		return (max(HeightOfTree(root->Lchild), HeightOfTree(root->Rchild)));
	}
}
int tree::DepthOfTree(node* root, int ParentDepth) {
	if (root == NULL) {
		return ParentDepth;
	}
	return (max(DepthOfTree(root->Rchild, ParentDepth + 1), DepthOfTree(root->Lchild, ParentDepth + 1)));
}
void tree::DestroyTree(node* root) {
	if (root != NULL) {
		DestroyTree(root->Lchild);
		DestroyTree(root->Rchild);
		delete root;
	}
}
void tree::DeleteNode(string value) {
	search(value);
	if (loc != NULL) {
		node* plocTemp;
		node* locTemp;
		locTemp = loc;
		plocTemp = ploc;
		if (loc->Rchild != NULL && loc->Lchild != NULL) {
			ploc = loc;
			loc = loc->Rchild;
			while (loc->Rchild != NULL) {
				ploc = loc;
				loc = loc->Rchild;
			}
		}
		if (loc->Rchild == NULL && loc->Lchild == NULL) {
			if (loc == root) {
				root = NULL;
			}
			else if (loc == ploc->Lchild) {
				ploc->Lchild = NULL;
			}
			else if (loc == ploc->Rchild) {
				ploc->Rchild = NULL;
			}
		}
		else if (loc->Lchild != NULL && loc->Rchild != NULL) {
			if (ploc) {
				if (loc == ploc->Lchild) {
					ploc->Lchild = loc->Lchild;
				}
				else {
					ploc->Rchild = loc->Lchild;
				}
			}
			else {
				root = loc->Lchild;
			}
		}
		else if (loc->Rchild==NULL && loc->Lchild==NULL){
			if (ploc) {
				if (loc == ploc->Lchild) {
					ploc->Lchild = loc->Lchild;
				}
				else {
					ploc->Rchild = loc->Lchild;
				}
			}
			else {
				root = loc->Rchild;
			}
		}
		if (value == loc->data) {
			delete loc;
		}
		else {
			loc->Lchild = locTemp->Lchild;
			loc->Rchild = locTemp->Rchild;
			if (plocTemp) {
				if (locTemp == plocTemp->Lchild) {
					plocTemp->Lchild = loc;
				}
				else {
					plocTemp->Rchild = loc;
				}
			}
			else {
				root = loc;
			}
		}
		AVLcaller(root, NULL);
	}
	else {
		cout << "The Value Does Not Exist" << endl;
	}
}
void tree::AVLcaller(node* root1, node* parent) {
	if (root1 != NULL) {
		AVLcaller(root1->Lchild, root1);
		AVLcaller(root1->Rchild, root1);
		int var = HeightDifference(root1);
		if (var == 2 || var == -2) {
			AVLconverter(root1, parent);
		}
	}
	else {
		cout << "";
	}
}
int tree::HeightDifference(node* alpha) {
	if (alpha != NULL) {
		int LHeight = 0;
		LHeight = HeightOfTree(alpha->Lchild);
		int RHeight = 0;
		RHeight = HeightOfTree(alpha->Rchild);
		int DiffHeight;
		DiffHeight = LHeight - RHeight;
		return DiffHeight;
	}
	else {
		return 0;
	}
}
void tree::AVLconverter(node* root2, node* parent) {
	int NodeDiff = HeightDifference(root2);
	//LEFT
	if (NodeDiff == -2) {
		node* x;
		node* y;
		x = root2;
		y = root2->Rchild;
		int LHeight = HeightOfTree(y->Lchild);
		int RHeight = HeightOfTree(y->Rchild);
		if (RHeight + 1 == LHeight) {
			node* x1;
			node* y1;
			x1 = y;
			y1 = y->Lchild;
			x1->Lchild = y1->Rchild;
			y->Rchild = x1;
			x->Rchild = y1;
			y = y1;
		}
		x->Rchild = y->Lchild;
		y->Lchild = x;
		if (parent != NULL) {
			if (parent->Lchild == x) {
				parent->Lchild = y;
			}
			else {
				parent->Rchild = y;
			}
		}
		else {
			root = y;
		}
	}
	//RIGHT
	if (NodeDiff == 2) {
		node* x;
		node* y;
		x = root2;
		y = x->Lchild;
		int LHeight = HeightOfTree(y->Lchild);
		int RHeight = HeightOfTree(y->Rchild);
		if (LHeight + 1 == RHeight) {
			node* x1;
			node* y1;
			x1 = y;
			y1 = y->Rchild;
			x1->Rchild = y1->Lchild;
			y1->Lchild = x1;
			x->Lchild = y1;
			y = y1;
		}
		x->Lchild = y->Rchild;
		y->Rchild = x;
		if (parent != NULL) {
			if (parent->Lchild == x) {
				parent->Lchild = y;
			}
			else {
				parent->Rchild = y;
			}
		}
		else {
			root = y;
		}
	}
	cout << "PreOrder" << endl;
	preorder(root);
	cout << endl;
}
void tree::avlCSVparser(string filename) {
	ifstream file(filename);
	string line;
	char a = ',';
	while (getline(file, line)) {
		stringstream ss(line);
		string value_;
		string row_value;
		while (getline(ss, value_, a)) {
			row_value += value_ + " ";
		}
		insert(row_value);
	}
}

void tree::avlCSVparser_2(string filename) {
	ifstream file(filename);
	string line;
	char a = ',';
	while (getline(file, line)) {
		stringstream ss(line);
		string value_;
		while (getline(ss, value_, a)) {
			insert(value_);
		}
	}
}

node* tree::getRoot() {
	//cout << "Called" << endl;
	return root;
}
void tree::test(node* root) {
	cout << root->data ;
	//cout << "After root ";
}
