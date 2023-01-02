#pragma once
#include "main.h"
#include <cctype>
#include "hashmap.h"
int main() {
    AVL avl;
    HashTable h__;
    // Read items from CSV file
    ifstream file("test.csv");
    string line;
    getline(file, line); // skip first line
    while (getline(file, line)) {
        stringstream ss(line);
        Item item;
        getline(ss, item.id, ',');
        getline(ss, item.status, ',');
        getline(ss, item.customer_id, ',');
        getline(ss, item.sku, ',');
        getline(ss, item.price, ',');
        string a = item.price;
        int sales;
        stringstream s3(a);
        if (s3 >> sales) {
            sales = stoi(item.price);
        }
        else {
            a = "100";
            sales = stoi(a);
        }

        getline(ss, item.quantity, ',');
        getline(ss, item.grand_total, ',');
        getline(ss, item.created_at, ',');
        getline(ss, item.category, ',');
        getline(ss, item.sales_comission_code, ',');
        getline(ss, item.discount_amount, ',');
        getline(ss, item.payment_method, ',');
        getline(ss, item.fiscal_year, ',');
        string fiscal_year = item.fiscal_year;
        getline(ss, item.bi_status, ',');
        getline(ss, item.mv, ',');
        getline(ss, item.customer_since, ',');
        avl.insert(item);
        h__.insert(fiscal_year, sales);

    }
    file.close();
    string choice;
    cout << "Choose From the Functions: \n(i) Search Using Order Id (AVL) \n(c) Search Using Customer Id (LinkedList) \n(p) Get the total Price for a single Customer" << endl;
    cout << "(h) See Sales in a Fiscal Year using HashTable: " << endl;
    cin >> choice;
    if (choice == "i") {
        // Search for item with given ID
        string id;
        cout << "Which Id would You Like to search on: " << endl;
        cin >> id;
        AVLNode* result = avl.searchid(id, avl.getRoot());
        if (result != nullptr) {
            cout << "Item found:" << endl;
            cout << "ID: " << result->data.id << endl;
            cout << "Status: " << result->data.status << endl;
            cout << "Customer ID: " << result->data.customer_id << endl;
            cout << "SKU: " << result->data.sku << endl;
            cout << "Price: " << result->data.price << endl;
            cout << "Quantity: " << result->data.quantity << endl;
            cout << "Grand Total: " << result->data.grand_total << endl;
            cout << "Created at: " << result->data.created_at << endl;
            cout << "Category: " << result->data.category << endl;
            cout << "Sales Commission Code: " << result->data.sales_comission_code << endl;
            cout << "Discount Amount: " << result->data.discount_amount << endl;
            cout << "Payment Method: " << result->data.payment_method << endl;
            cout << "Fiscal Year: " << result->data.fiscal_year << endl;
            cout << "BI Status: " << result->data.bi_status << endl;
            cout << "MV: " << result->data.mv << endl;
            cout << "Customer Since: " << result->data.customer_since << endl;
        }
        else {
            cout << "Item not found" << endl;
        }
    }
    else if (choice == "c") {
        string customerId;
        cout << "Enter the customer ID to search for: ";
        cin >> customerId;
        LinkedList results = searchByCustomerId(customerId, avl.getRoot());
        ListNode* curr = results.head;
        cout << "Following orders were placed by Customer#" << customerId << endl;
        while (curr != nullptr) {
            cout << "\t--------" << endl;
            cout << "\tItem found: " << endl;
            cout << "\tID: " << curr->data->data.id << endl;
            cout << "\tStatus: " << curr->data->data.status << endl;
            cout << "\tCustomer ID: " << curr->data->data.customer_id << endl;
            cout << "\tSKU: " << curr->data->data.sku << endl;
            cout << "\tPrice: " << curr->data->data.price << endl;
            cout << "\tQuantity: " << curr->data->data.quantity << endl;
            cout << "\tGrand Total: " << curr->data->data.grand_total << endl;
            cout << "\tCreated at: " << curr->data->data.created_at << endl;
            cout << "\tCategory: " << curr->data->data.category << endl;
            cout << "\tSales Commission Code: " << curr->data->data.sales_comission_code << endl;
            cout << "\tDiscount Amount: " << curr->data->data.discount_amount << endl;
            cout << "\tPayment Method: " << curr->data->data.payment_method << endl;
            cout << "\tFiscal Year: " << curr->data->data.fiscal_year << endl;
            cout << "\tBI Status: " << curr->data->data.bi_status << endl;
            cout << "\tMV: " << curr->data->data.mv << endl;
            cout << "\tCustomer Since: " << curr->data->data.customer_since << endl;
            curr = curr->next;
            //cout << curr->data->data.id << " " << curr->data->data.customer_id << endl;
            //curr = curr->next;
        }
        cout << "\t--------" << endl;
    }
    else if (choice == "p") {
        string id;
        int total_price = 0;
        cout << "Enter Customer Id: " << endl;
        cin >> id;
        avl.getTotalPriceForCustomer(avl.getRoot(), id, total_price);
        cout << "Total Price for the customer is: " << total_price << endl;
    }
    else if (choice == "h") {
        string FY;
        cout << "Enter Which Year's Sales You Want to Find (FY17) " << endl;
        cin >> FY;
        int saless = h__.findTotalSalesForFiscalYear(FY);
        cout << "Total Sales for Fiscal Year " << FY << " were: " << saless;
    }
}