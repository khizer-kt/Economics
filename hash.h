#pragma once

//KT
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
int const capacity2 = 600000;
class Hash__ {
public:
	int hash_(string filename);
	bool isnum(string s);
	void insert(string filename);
	void test();
	bool isnum2(std::string s);
	string function(string filename);
};
void Hash__::insert(string filename) {
	//cout << "CALLED";
	int loc;
	loc = hash_(filename);
	int* arr;
	arr = new int;
	string element = function(filename);
	arr[loc] = stoi(element);
	cout << stoi(element);
	//cout << "Call complete";
}
bool Hash__::isnum(std::string s) { //num checker
	//returns true when num
	//cout << "called numcheck";
	return std::all_of(s.begin(), s.end(), ::isdigit);
}
bool Hash__::isnum2(std::string s) {
	for (char c : s) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}
int Hash__::hash_(string filename) { //get the locations for storage
	string x = function(filename);
	//cout << "calledhash";
	int y = stoi(x);
	return y % capacity2;
}
void Hash__::test() {
	cout << "TEST FUNCTION" << endl;
}
string Hash__::function(string filename) {
	ifstream file(filename);
	string line, firstColumn;
	//cout << "call";
	int temp = 590000;
	char a = ',';
	//cout << "outside loop";
	while (getline(file, line)) {
		// create a stringstream from the line
		stringstream ss(line);

		// get the first value before the comma and store it in firstColumn
		getline(ss, firstColumn, a);
		//cout << "outside if";
		// insert the firstColumn value into the tree
		if (!isnum2(firstColumn)) {
			firstColumn = to_string(temp);
			//cout << firstColumn;
			return firstColumn;
		}
		else {
			//cout << "else";
			//cout << firstColumn;
			return firstColumn;
		}
		temp++;

	}
}
