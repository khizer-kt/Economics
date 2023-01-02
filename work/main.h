#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
const int TableSize = 10000;
class Item {
public:
    string id;
    string status;
    string customer_id;
    string sku;
    string price;
    string quantity;
    string grand_total;
    string created_at;
    string category;
    string sales_comission_code;
    string discount_amount;
    string payment_method;
    string fiscal_year;
    string bi_status;
    string mv;
    string customer_since;
};

class AVLNode {
public:
    Item data;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(Item data) {
        this->data = data;
        this->height = 1;
        this->left = this->right = nullptr;
    }
};

class AVL {
public:
    AVLNode* root;
    AVLNode* getRoot() {
        return root;
    }
    int height(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }
    AVLNode* insert(AVLNode* node, Item data) {
        
        if (node == nullptr) {
            //cout << "root set to " << data.id;
            return new AVLNode(data);
        }
        if (data.id.compare(node->data.id) < 0) {
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = height(node->left) - height(node->right);
        if (balance > 1) {
            if (data.id.compare(node->left->data.id) < 0) {
                return rightRotate(node);
            }
            else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balance < -1) {
            if (data.id.compare(node->right->data.id) > 0) {
                return leftRotate(node);
            }
            else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    AVLNode* rightRotate(AVLNode* node) {
        AVLNode* x = node->left;
        AVLNode* y = x->right;
        x->right = node;
        node->left = y;
        node->height = max(height(node->left), height(node->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    AVLNode* leftRotate(AVLNode* node) {
        AVLNode* x = node->right;
        AVLNode* y = x->left;
        x->left = node;
        node->right = y;
        node->height = max(height(node->left), height(node->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    void getTotalPriceForCustomer(AVLNode* node, string customer_id, int& total_price) {
        if (node == nullptr) {
            return;
        }
        getTotalPriceForCustomer(node->left, customer_id, total_price);
        if (node->data.customer_id == customer_id) {
            total_price += stoi(node->data.price);
        }
        getTotalPriceForCustomer(node->right, customer_id, total_price);
    }

    AVL() {
        root = nullptr;
    }
    AVLNode* searchid(string id, AVLNode* node) {
        //cout << "search called" << endl;
        if (node == nullptr || node->data.id == id) {
            return node;
        }
        //cout << "Searching with" << node->data.id << endl;
        if (id < node->data.id) {
            return searchid(id, node->left);
        }
        return searchid(id, node->right);
    }
    void insert(Item data) {
        root = insert(root, data);
    }
};

//int main() {
//    AVL avl;
//
//    // Read items from CSV file
//    ifstream file("items.csv");
//    string line;
//    getline(file, line); // skip first line
//    while (getline(file, line)) {
//        stringstream ss(line);
//        Item item;
//        getline(ss, item.id, ',');
//        getline(ss, item.status, ',');
//        getline(ss, item.customer_id, ',');
//        getline(ss, item.sku, ',');
//        getline(ss, item.price, ',');
//        getline(ss, item.quantity, ',');
//        getline(ss, item.grand_total, ',');
//        getline(ss, item.created_at, ',');
//        getline(ss, item.category, ',');
//        getline(ss, item.sales_comission_code, ',');
//        getline(ss, item.discount_amount, ',');
//        getline(ss, item.payment_method, ',');
//        getline(ss, item.fiscal_year, ',');
//        getline(ss, item.bi_status, ',');
//        getline(ss, item.mv, ',');
//        getline(ss, item.customer_since, ',');
//        avl.insert(item);
//    }
//    file.close();
//
//    // Search for item with given ID
//    string id = "211131";
//    AVLNode* result = avl.search(id, avl.getRoot());
//    if (result != nullptr) {
//        cout << "Item found:" << endl;
//        cout << "ID: " << result->data.id << endl;
//        cout << "Status: " << result->data.status << endl;
//        cout << "Customer ID: " << result->data.customer_id << endl;
//        cout << "SKU: " << result->data.sku << endl;
//        cout << "Price: " << result->data.price << endl;
//        cout << "Quantity: " << result->data.quantity << endl;
//        cout << "Grand Total: " << result->data.grand_total << endl;
//        cout << "Created at: " << result->data.created_at << endl;
//        cout << "Category: " << result->data.category << endl;
//        cout << "Sales Commission Code: " << result->data.sales_comission_code << endl;
//        cout << "Discount Amount: " << result->data.discount_amount << endl;
//        cout << "Payment Method: " << result->data.payment_method << endl;
//        cout << "Fiscal Year: " << result->data.fiscal_year << endl;
//        cout << "BI Status: " << result->data.bi_status << endl;
//        cout << "MV: " << result->data.mv << endl;
//        cout << "Customer Since: " << result->data.customer_since << endl;
//    }
//    else {
//        cout << "Item not found" << endl;
//    }
//    return 0;
//}


class ListNode {
public:
    AVLNode* data;
    ListNode* next;
    ListNode(AVLNode* data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    ListNode* head;
    void insert(AVLNode* data) {
        if (head == nullptr) {
            head = new ListNode(data);
            return;
        }
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new ListNode(data);
    }
    LinkedList() {
        head = nullptr;
    }
};

LinkedList searchByCustomerId(string customerId, AVLNode* node) {
    if (node == nullptr) {
        return {};
    }
    LinkedList leftResult = searchByCustomerId(customerId, node->left);
    LinkedList rightResult = searchByCustomerId(customerId, node->right);
    if (node->data.customer_id == customerId) {
        leftResult.insert(node);
    }
    ListNode* curr = rightResult.head;
    while (curr != nullptr) {
        leftResult.insert(curr->data);
        curr = curr->next;
    }
    return leftResult;
}


