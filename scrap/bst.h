#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
struct Item {
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

struct BSTNode {
    Item data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* root, Item data) {
    if (root == nullptr) {
        root = new BSTNode;
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (data.id < root->data.id) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

BSTNode* search(BSTNode* root, string id) {
    if (root == nullptr || root->data.id == id) {
        return root;
    }
    if (id < root->data.id) {
        return search(root->left, id);
    }
    return search(root->right, id);
}

//#include "bst.h"
//#include <iostream>
//using namespace std;
//int main() {
//    ifstream file("ecom.csv");
//    string line;
//    BSTNode* root = nullptr;
//    while (std::getline(file, line)) {
//        std::stringstream line_stream(line);
//        std::string cell;
//        Item data;
//        getline(line_stream, data.id, ',');
//        getline(line_stream, data.status, ',');
//        getline(line_stream, data.customer_id, ',');
//        getline(line_stream, data.sku, ',');
//        getline(line_stream, data.price, ',');
//        getline(line_stream, data.quantity, ',');
//        getline(line_stream, data.grand_total, ',');
//        getline(line_stream, data.created_at, ',');
//        getline(line_stream, data.category, ',');
//        getline(line_stream, data.sales_comission_code, ',');
//        getline(line_stream, data.discount_amount, ',');
//        getline(line_stream, data.payment_method, ',');
//        getline(line_stream, data.fiscal_year, ',');
//        getline(line_stream, data.bi_status, ',');
//        getline(line_stream, data.mv, ',');
//        getline(line_stream, data.customer_since, ',');
//        root = insert(root, data);
//    }
//    file.close();
//
//    // Search for an item with id = 123
//    BSTNode* result = search(root, "211131");
//    if (result != nullptr) {
//        cout << "Item found: " << result->data.sku << std::endl;
//    }
//    else {
//        cout << "Item not found" << std::endl;
//    }
//
//    return 0;
//}
//

