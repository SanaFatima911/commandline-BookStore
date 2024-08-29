#pragma once
#include <iostream>
#include <string>
using namespace std;
class Book {
public:
    string ISBN, title, author;
    double price;
    int NumOfCopies;

    Book(string isbn, string tit, string au, double pr, int nc) {
        ISBN = isbn;
        title = tit;
        author = au;
        price = pr;
        NumOfCopies = nc;
    }

    void updateInventory(int quantity) {
        NumOfCopies += quantity;
    }

    void displayBookInfo() {
        cout << "ISBN: " << ISBN << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Number of Copies: " << NumOfCopies << endl;
    }
};
