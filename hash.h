#pragma once
//KT
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int const capacity = 600000;
int arr[capacity];



class Hash{
public:
	int hash_(string filename);
	string get_(string filename);
	bool isnum(string s);
	void insert(int arr[], string filename);
};
void Hash::insert(int arr[], string filename) {
	int loc;
	loc = hash_(filename);
	string element = get_(filename);
	arr[loc] = stoi(element);
}
bool Hash::isnum(std::string s) { //num checker
	//returns true when num
	return std::all_of(s.begin(), s.end(), ::isdigit);
}
string Hash::get_(string filename) {
	ifstream file(filename);
	string line, column;
	char a = ',';
	int column_temp = 590000;
	while (getline(file, line)) {
		// create a stringstream from the line
		stringstream ss(line);

		// get the first value before the comma and store it in firstColumn
		getline(ss, column, a);

		// insert the firstColumn value into the tree
		if (!isnum(column)) {
			column = to_string(column_temp);
		}
		column_temp++;
		
		return column;

	}
}
int Hash::hash_(string filename) { //get the locations for storage
	string x = get_(filename);
	int y = stoi(x);
	return y % capacity;
}
