#include <iostream>
#include <string>
using namespace std;
const int size_ = 10001;
class item__ {
public:
	string fiscal_year;
	int sales;
	item__* next;
};
class HashTable {
public:
	item__* table[size_];
    HashTable() {
        for (int i = 0; i < size_; i++) {
            table[i] = nullptr;
        }
    }
    int hash(string fiscal_year) {
        int sum = 0;
        for (int i = 0; i < fiscal_year.length(); i++) {
            sum += fiscal_year[i];
        }
        return sum % size_;
    }
    void insert(string fiscal_year, int sales) {
        int index = hash(fiscal_year);
        item__* item = new item__();
        item->fiscal_year = fiscal_year;
        item->sales = sales;
        item->next = table[index];
        table[index] = item;
    }
    int findTotalSalesForFiscalYear(string fiscal_year) {
        int index = hash(fiscal_year);
        int total_sales = 0;
        item__* item = table[index];
        while (item != nullptr) {
            if (item->fiscal_year == fiscal_year) {
                total_sales += item->sales;
            }
            item = item->next;
        }
        return total_sales;
    }

};