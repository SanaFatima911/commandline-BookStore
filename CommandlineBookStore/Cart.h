#include"Book.h"
class Cart {
public:
    Book* b[100]; // assuming max 100 books in cart
    int NumOfBooks;
    double TotalCost;

    Cart() {
        NumOfBooks = 0;
        TotalCost = 0;
    }

    void addBook(Book* book) {
        b[NumOfBooks] = book; 
        NumOfBooks++;
        TotalCost += book->price;
    }

    void removeBook(Book* book) {
        for (int i = 0; i < NumOfBooks; i++) {
            if (b[i] == book) {      
                for (int j = i; j < NumOfBooks - 1; j++) {
                    b[j] = b[j + 1];
                }
                NumOfBooks--;
                TotalCost -= book->price;
                
            }
        }
    }

    void CalculateTotal() {
        TotalCost = 0;
        for (int i = 0; i < NumOfBooks; i++) {
            TotalCost += b[i]->price;
        }
    }
    ~Cart() {
    for (int i = 0; i < NumOfBooks; i++) {
        delete b[i];  // Delete each dynamically allocated book
    }
}
};
