#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
const int T = 584525;
const int C = 115327;
class Queue {
public:
    int* hash2();
	int* parser();
};
int* Queue::parser() {
    static int values[C];  // Array to store the unique values
    bool seen[C];  // Array to track which values have been seen

    // Initialize the seen array
    for (int i = 0; i < C; i++) {
        seen[i] = false;
    }

    ifstream file("ecom.csv");
    string line;
    int i = 0;  // Index into the values array
    bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) {
            // Skip the first line
            firstLine = false;
            continue;
        }

        // Skip the first two fields
        stringstream ss(line);
        string value;
        getline(ss, value, ',');
        getline(ss, value, ',');

        // Read the third field
        getline(ss, value, ',');
        // Convert the value to an integer
        int val;
        if (!(stringstream(value) >> val)) {
            // Assign a default value if the value is not an integer
            val = 0;
        }

        // Store the value in the values array if it has not been seen before
        if (!seen[val]) {
            values[i++] = val;
            seen[val] = true;
        }
    }
    return values;
}

int* Queue::hash2() {
    int* values = parser();
    int* hashTable = new int[C];
    for (int i = 0; i < C; i++) {
        hashTable[i] = -1;  // Initialize the table to -1
    }
    for (int i = 0; i < C; i++) {
        int hashValue = values[i] % C;  // Compute the hash value

        // Check for a collision
        if (hashTable[hashValue] != -1) {
            // Linear probing: search for the next available slot
            int probe = hashValue + 1;
            while (hashTable[probe] != -1) {
                probe = (probe + 1) % C;
            }
            hashValue = probe;
        }

        // Insert the value into the table
        hashTable[hashValue] = values[i];
    }
    for (int i = 0; i < C; i++) {
        cout << hashTable[i] << endl;
    }
    return hashTable;
}
