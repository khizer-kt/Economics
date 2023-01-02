#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
const int TABLE_SIZE = 584530;
const int MAX_VALUES = 584530;  // Maximum number of values to store

int* converter() {
    static int values[MAX_VALUES];  // Array to store the values

    // Open the CSV file
    ifstream file("ecom.csv");

    // Read the values from the first column
    string line;
    int nonIntCounter = 584526;
    int i = 0;  // Index into the array
    bool firstLine = true;  // Flag to indicate the first line
    while (getline(file, line)) {
        if (firstLine) {
            // Skip the first line
            firstLine = false;
            continue;
        }

        // Split the line into fields
        stringstream ss(line);
        string value;
        getline(ss, value, ',');

        // Convert the value to an integer
        int val;
        if (!(stringstream(value) >> val)) {
            // Assign a default value if the value is not an integer
            val = nonIntCounter++;
        }

        values[i++] = val;
    }

    return values;
}


//int main() {
//    int* values = converter();
//
//    // Print the integer values
//    for (int i = 0; i < MAX_VALUES; i++) {
//        cout << values[i] << endl;
//    }
//
//    return 0;
//}
int* hash_() {
    int* values = converter();  // Get the values from the CSV file

    // Create the hash table

    int* hashTable = new int[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;  // Initialize the table to -1
    }

    // Compute the hash values and insert them into the table
    for (int i = 0; i < MAX_VALUES; i++) {
        int hashValue = values[i] % TABLE_SIZE;  // Compute the hash value

        // Check for a collision
        if (hashTable[hashValue] != -1) {
            // Linear probing: search for the next available slot
            int probe = hashValue + 1;
            while (hashTable[probe] != -1) {
                probe = (probe + 1) % TABLE_SIZE;
            }
            hashValue = probe;
        }

        // Insert the value into the table
        hashTable[hashValue] = values[i];
    }

    return hashTable;
}
//testing needed on hash search
int search(int value, int* hashTable) {
    cout << "Searching for value " << value << " in the hash table." << endl;

    int hashValue = value % TABLE_SIZE;  // Compute the hash value

    // Search for the value in the table
    int probe = hashValue;
    while (hashTable[probe] != value && hashTable[probe] != -1) {
        probe = (probe + 1) % TABLE_SIZE;
    }

    if (hashTable[probe] == value) {
        cout << "Value found at index " << probe << " in the table." << endl;
        return probe;
    }
    else {
        cout << "Value not found in the table." << endl;
        return -1;
    }
}
//code working for hashtable entries just a little slower
//int main() {
//
//    int* hashTable = hash_();
//
//    // Print the values in the hash table
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        cout << hashTable[i] << endl;
//    }
//
//}

/*
I have a dataset that i am reading from a csv that has the following columns:
Item Id	Status	Customer ID	SKU	Price	Quantity	Grand Total	Created at	Category	Sales Comission Code	Discount amount	Payment Method	Fiscal Year	BI Status	MV	Customer Since

Now I have a Hash Function that is getting the item_id values as an integer and assigning them their locations in the hash table,
Now I want to implement the following function on it 
*/