#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS

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
    } // O(n)

    AVL() {
        root = nullptr;
    }
    AVLNode* searchid(string id, AVLNode* node) { //O(log n)
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
    void printALL(AVLNode* node) {
        if (node == nullptr) {
            return;
        }
        printALL(node->left);
        cout << "ID: " << node->data.id << endl;
        cout << "Status: " << node->data.status << endl;
        cout << "Customer ID: " << node->data.customer_id << endl;
        cout << "SKU: " << node->data.sku << endl;
        cout << "Price: " << node->data.price << endl;
        cout << "Quantity: " << node->data.quantity << endl;
        cout << "Grand total: " << node->data.grand_total << endl;
        cout << "Created at: " << node->data.created_at << endl;
        cout << "Category: " << node->data.category << endl;
        cout << "Sales comission code: " << node->data.sales_comission_code << endl;
        cout << "Discount amount: " << node->data.discount_amount << endl;
        cout << "Payment method: " << node->data.payment_method << endl;
        cout << "Fiscal year: " << node->data.fiscal_year << endl;
        cout << "BI status: " << node->data.bi_status << endl;
        cout << "MV: " << node->data.mv << endl;
        cout << "Customer since: " << node->data.customer_since << endl;
        printALL(node->right);
    } //inorder  O(n) coz inorder traversal
    void PricebyCategory(AVLNode* node, std::string category, int& total_price) {
        if (node == nullptr) {
            return;
        }
        PricebyCategory(node->left, category, total_price);
        if (node->data.category == category) {
            total_price += std::stoi(node->data.price) * std::stoi(node->data.quantity);
        }
        PricebyCategory(node->right, category, total_price);
    }
    int countOrdersInCategory(AVLNode* node, string category) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0;
        if (node->data.category == category) {
            count = std::stoi(node->data.quantity);
        }
        return count + countOrdersInCategory(node->left, category) + countOrdersInCategory(node->right, category);
    }
    int getCustomerSince(AVLNode* node, std::string customer_id) {
        if (node == nullptr) {
            return -1;
        }
        if (node->data.customer_id == customer_id) {
            time_t current_time;
            time(&current_time);
            tm time_info;
            localtime_s(&time_info, &current_time);
            int current_year = time_info.tm_year + 1900;
            std::string customer_since_str = node->data.customer_since;
            int customer_since_year;
            stringstream s(customer_since_str);
            s >> customer_since_year;
            return current_year - customer_since_year;
        }
        int result = getCustomerSince(node->left, customer_id);
        if (result != -1) {
            return result;
        }
        return getCustomerSince(node->right, customer_id);
    }
    void countPaymentMethods(AVLNode* node,int& countcod, int& countjazzvoucher, int& countcustomercredit, int& countpayaxis, int& other) {
        if (node == nullptr) {
            return;
        }
        countPaymentMethods(node->left,countcod, countjazzvoucher, countcustomercredit, countpayaxis, other);
        if (node->data.payment_method == "cod") {
            countcod++;
        }
        else if (node->data.payment_method == "jazzvoucher") {
            countjazzvoucher++;
        }
        else if (node->data.payment_method == "customercredit") {
            countcustomercredit++;
        }
        else if (node->data.payment_method == "payaxis") {
            countpayaxis++;
        }
        else {
            other++;
        }
        countPaymentMethods(node->right, countcod, countjazzvoucher, countcustomercredit, countpayaxis, other);

    }
    void REVPaymentMethods(AVLNode* node,  int& cod_revenue, int& jazzvoucher_revenue, int& other_rev) {
        if (node == nullptr) {
            return;
        }
        REVPaymentMethods(node->left, cod_revenue, jazzvoucher_revenue, other_rev);
        if (node->data.payment_method == "cod") {
            int test;
            stringstream ss(node->data.grand_total);
            if (ss >> test) {
                cod_revenue += stoi(node->data.grand_total);
            }
            else {
                cod_revenue += 100;
            }
        }
        else if (node->data.payment_method == "jazzvoucher") {
            int test;
            stringstream ss(node->data.grand_total);
            if (ss >> test) {
                jazzvoucher_revenue += stoi(node->data.grand_total);
            }
            else {
                jazzvoucher_revenue += 100;
            }
        }
        else {
            int test;
            stringstream ss(node->data.grand_total);
            if (ss >> test) {
                other_rev += stoi(node->data.grand_total);
            }
            else {
                other_rev += 100;
            }
        }
        REVPaymentMethods(node->right, cod_revenue, jazzvoucher_revenue, other_rev);
    }



    //int revenueForYear(AVLNode* node, std::string fiscal_year) {
    //    if (node == nullptr) {
    //        return 0;
    //    }
    //    int revenue = 0;
    //    if (node->data.fiscal_year == fiscal_year) {
    //        revenue += std::stoi(node->data.price) * std::stoi(node->data.quantity);
    //    }
    //    return revenue + revenueForYear(node->left, fiscal_year) + revenueForYear(node->right, fiscal_year);
    //}
};
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

