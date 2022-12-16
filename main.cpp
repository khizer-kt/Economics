#pragma once
#include <iostream>
#include "LinkedList.h"
#include "parser.h"
using namespace std;

int main() {
    // Create an empty linked list
    LinkedList list;

    // Read the data from a file and store it in the list
    parse_all(list);

    // Print the list
    list.print();
}

