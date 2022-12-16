#pragma once
#include "LinkedList.h"
using namespace std;

void parse_all(LinkedList& list) {
    string fname;
    cout << "Enter the file name: ";
    cin >> fname;

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else {
        cout << "Could not open the file\n";
    }

    // Use the append function to insert the data read from the file into the list
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[i].size(); j++) {
            list.append(content[i][j]);
        }
    }
}
