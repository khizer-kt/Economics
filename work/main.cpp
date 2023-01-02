//#include "main.h"
//#include <cctype>
//#include "hashmap.h"
//int main() {
//    AVL avl;
//    HashTable h__;
//    // Read items from CSV file
//    ifstream file("test.csv");
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
//        string a = item.price;
//        int sales;
//        stringstream s3(a);
//        if (s3 >> sales) {
//            sales = stoi(item.price);
//        }
//        else {
//            a = "100";
//            sales = stoi(a);
//        }
//        
//        getline(ss, item.quantity, ',');
//        getline(ss, item.grand_total, ',');
//        getline(ss, item.created_at, ',');
//        getline(ss, item.category, ',');
//        getline(ss, item.sales_comission_code, ',');
//        getline(ss, item.discount_amount, ',');
//        getline(ss, item.payment_method, ',');
//        getline(ss, item.fiscal_year, ',');
//        string fiscal_year = item.fiscal_year;
//        getline(ss, item.bi_status, ',');
//        getline(ss, item.mv, ',');
//        getline(ss, item.customer_since, ',');
//        avl.insert(item);
//        h__.insert(fiscal_year, sales);
//
//    }
//    file.close();
//    string choice;
//    cout << "Choose From the Functions: \n(i) Search Using Order Id (AVL) \n(c) Search Using Customer Id (LinkedList) \n(p) Get the total Price for a single Customer" << endl;
//    cout << "(h) See Sales in a Fiscal Year using HashTable: " << endl;
//    cin >> choice;
//    if (choice == "i") {
//        // Search for item with given ID
//        string id;
//        cout << "Which Id would You Like to search on: " << endl;
//        cin >> id;
//        AVLNode* result = avl.searchid(id, avl.getRoot());
//        if (result != nullptr) {
//            cout << "Item found:" << endl;
//            cout << "ID: " << result->data.id << endl;
//            cout << "Status: " << result->data.status << endl;
//            cout << "Customer ID: " << result->data.customer_id << endl;
//            cout << "SKU: " << result->data.sku << endl;
//            cout << "Price: " << result->data.price << endl;
//            cout << "Quantity: " << result->data.quantity << endl;
//            cout << "Grand Total: " << result->data.grand_total << endl;
//            cout << "Created at: " << result->data.created_at << endl;
//            cout << "Category: " << result->data.category << endl;
//            cout << "Sales Commission Code: " << result->data.sales_comission_code << endl;
//            cout << "Discount Amount: " << result->data.discount_amount << endl;
//            cout << "Payment Method: " << result->data.payment_method << endl;
//            cout << "Fiscal Year: " << result->data.fiscal_year << endl;
//            cout << "BI Status: " << result->data.bi_status << endl;
//            cout << "MV: " << result->data.mv << endl;
//            cout << "Customer Since: " << result->data.customer_since << endl;
//        }
//        else {
//            cout << "Item not found" << endl;
//        }
//    }
//    else if (choice == "c") {
//        string customerId;
//        cout << "Enter the customer ID to search for: ";
//        cin >> customerId;
//        LinkedList results = searchByCustomerId(customerId, avl.getRoot());
//        ListNode* curr = results.head;
//        cout << "Following orders were placed by Customer#" << customerId << endl;
//        while (curr != nullptr) {
//            cout << "\t--------" << endl;
//            cout << "\tItem found: " << endl;
//            cout << "\tID: " << curr->data->data.id << endl;
//            cout << "\tStatus: " << curr->data->data.status << endl;
//            cout << "\tCustomer ID: " << curr->data->data.customer_id << endl;
//            cout << "\tSKU: " << curr->data->data.sku << endl;
//            cout << "\tPrice: " << curr->data->data.price << endl;
//            cout << "\tQuantity: " << curr->data->data.quantity << endl;
//            cout << "\tGrand Total: " << curr->data->data.grand_total << endl;
//            cout << "\tCreated at: " << curr->data->data.created_at << endl;
//            cout << "\tCategory: " << curr->data->data.category << endl;
//            cout << "\tSales Commission Code: " << curr->data->data.sales_comission_code << endl;
//            cout << "\tDiscount Amount: " << curr->data->data.discount_amount << endl;
//            cout << "\tPayment Method: " << curr->data->data.payment_method << endl;
//            cout << "\tFiscal Year: " << curr->data->data.fiscal_year << endl;
//            cout << "\tBI Status: " << curr->data->data.bi_status << endl;
//            cout << "\tMV: " << curr->data->data.mv << endl;
//            cout << "\tCustomer Since: " << curr->data->data.customer_since << endl;
//            curr = curr->next;
//            //cout << curr->data->data.id << " " << curr->data->data.customer_id << endl;
//            //curr = curr->next;
//        }
//        cout << "\t--------" << endl;
//    }
//    else if (choice == "p") {
//        string id;
//        int total_price = 0;
//        cout << "Enter Customer Id: " << endl;
//        cin >> id;
//        avl.getTotalPriceForCustomer(avl.getRoot(), id, total_price);
//        cout << "Total Price for the customer is: " << total_price << endl;
//    }
//    else if (choice == "h") {
//        string FY;
//        cout << "Enter Which Year's Sales You Want to Find (FY17) " << endl;
//        cin >> FY;
//        int saless = h__.findTotalSalesForFiscalYear(FY);
//        cout << "Total Sales for Fiscal Year " << FY << " were: " << saless;
//    }
//}
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
struct Item23 {
    string id;
    string status;
    string customer_id;
    string sku;
    double price;
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

// Compare function for quicksort
bool compare_items(const Item23& a, const Item23& b) {
    return a.price < b.price;
}

// Quicksort function
void quicksort(Item23* items, int left, int right, bool (*compare)(const Item23&, const Item23&)) {
    if (left >= right) {
        return;
    }
    int pivot = (left + right) / 2;
    int i = left;
    int j = right;
    while (i <= j) {
        while (compare(items[i], items[pivot])) {
            i++;
        }
        while (compare(items[pivot], items[j])) {
            j--;
        }
        if (i <= j) {
            std::swap(items[i], items[j]);
            i++;
            j--;
        }
    }
    quicksort(items, left, j, compare);
    quicksort(items, i, right, compare);
}

int main() {
    const int MAX_ITEMS = 20;
    Item23 items[MAX_ITEMS];
    int num_items = 0;

    // Read items from CSV file
    std::ifstream file("test3.csv");
    std::string line;
    getline(file, line); // skip first line
    while (num_items < MAX_ITEMS && getline(file, line)) {
        std::stringstream ss(line);
        Item23 item;
        getline(ss, item.id, ',');
        getline(ss, item.status, ',');
        getline(ss, item.customer_id, ',');
        getline(ss, item.sku, ',');
        std::string price_str;
        getline(ss, price_str, ',');
        int test;
        stringstream ab(price_str);
        if (ab >> test) {
            item.price = stod(price_str);
        }
        else {
            price_str = "100";
            item.price = stod(price_str);
        }
        getline(ss, item.quantity, ',');
        getline(ss, item.grand_total, ',');
        getline(ss, item.created_at, ',');
        getline(ss, item.category, ',');
        getline(ss, item.sales_comission_code, ',');
        getline(ss, item.discount_amount, ',');
        getline(ss, item.payment_method, ',');
        getline(ss, item.fiscal_year, ',');
        getline(ss, item.bi_status, ',');
        getline(ss, item.mv, ',');
        getline(ss, item.customer_since, ',');
        items[num_items] = item;
        num_items++;
    }
    file.close();

    // Sort items by price
    quicksort(items, 0, num_items - 1, compare_items);

    // Write sorted items to CSV file
    std::ofstream file2("test4.csv");
    if (!file2.is_open()) {
        std::cerr << "Error: Unable to open output file" << std::endl;
        return 1;
    }
    file2 << "Item Id,Status,Customer ID,SKU,Price,Quantity,Grand Total,Created at,Category,Sales Comission Code,Discount amount,Payment Method,Fiscal Year,BI Status,MV,Customer Since" << std::endl;
    for (int i = 0; i < num_items; i++) {
        const Item23& item = items[i];
        file2 << item.id << "," << item.status << "," << item.customer_id << "," << item.sku << "," << item.price << "," << item.quantity << "," << item.grand_total << "," << item.created_at << "," << item.category << "," << item.sales_comission_code << "," << item.discount_amount << "," << item.payment_method << "," << item.fiscal_year << "," << item.bi_status << "," << item.mv << "," << item.customer_since << std::endl;
    }
    file2.close();

    return 0;
    quicksort(items, 0, num_items - 1, compare_items);
}






