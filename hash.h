#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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
