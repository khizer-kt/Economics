#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
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
    const int MAX_ITEMS = 10000;
    Item23 items[MAX_ITEMS];
    int num_items = 0;

    // Read items from CSV file
    std::ifstream file("test.csv");
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
    std::ofstream file2("test2.csv");
    file2 << "Item Id,Status,Customer ID,SKU,Price,Quantity,Grand Total,Created at,Category,Sales Comission Code,Discount amount,Payment Method,Fiscal Year,BI Status,MV,Customer Since" << std::endl;
    for (int i = 0; i < num_items; i++) {
        const Item23& item = items[i];
        file2 << item.id << "," << item.status << "," << item.customer_id << "," << item.sku << "," << item.price << "," << item.quantity << "," << item.grand_total << "," << item.created_at << "," << item.category << "," << item.sales_comission_code << "," << item.discount_amount << "," << item.payment_method << "," << item.fiscal_year << "," << item.bi_status << "," << item.mv << "," << item.customer_since << std::endl;
    }
    file2.close();

    return 0;
}





//quicksort(items, 0, num_items - 1, compare_items);
