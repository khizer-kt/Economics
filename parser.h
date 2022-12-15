#pragma once
#include "LinkedList.h"

void parse_all(LinkedList& list) {
    std::string fname;
    std::cout << "Enter the file name: ";
    std::cin >> fname;

    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

    std::fstream file(fname, std::ios::in);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            row.clear();

            std::stringstream str(line);

            while (std::getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else {
        std::cout << "Could not open the file\n";
    }

    // Use the append function to insert the data read from the file into the list
    for (int i = 0; i < content.size(); i++) {
        for (int j = 0; j < content[i].size(); j++) {
            list.append(content[i][j]);
        }
    }
}


