#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Define the Node class
class Node {
public:
    string data;
    Node* next;

    // Constructor to initialize the data and next members
    Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize the head member
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert a new node at the front of the list
    void push(string data) {
        // Allocate a new node and set its data
        Node* new_node = new Node(data);
        // Set the next pointer of the new node to the current head of the list
        new_node->next = head;
        // Set the head of the list to the new node
        head = new_node;
    }

    // Function to print the data of each node in the list
    void print() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void append(string data) {
        // Allocate a new node and set its data
        Node* new_node = new Node(data);

        if (head == NULL) {
            // If the list is empty, set the new node as the head and tail of the list
            head = new_node;
            tail = new_node;
        }
        else {
            // Otherwise, set the next pointer of the current tail of the list to the new node
            tail->next = new_node;
            // Then set the tail of the list to the new node
            tail = new_node;
        }
    }
};