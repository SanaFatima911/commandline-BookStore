#include"Book.h"
class Store {
public:
    Book* inventory[100]; // assuming max 100 books in inventory
    int NumBooks;

    Store() {
        NumBooks = 0;
    }

    void addBook(Book* book) {
        inventory[NumBooks] = book;
        NumBooks++;
    }

    Book* searchBookByISBN(string ISBN) {
        for (int i = 0; i < NumBooks; i++) {
            if (inventory[i]->ISBN == ISBN) {
                return inventory[i];
            }
        }
        return 0;
    }

    void displayAvailableBooks() {
        for (int i = 0; i < NumBooks; i++) {
            inventory[i]->displayBookInfo();
            cout << endl;
        }
    }

    void checkOut(Cart cart) {
        if (cart.NumOfBooks == 0) {
        cout << "Error: Your cart is empty. Cannot proceed with checkout." << endl;
        return;
    }
    for (int i = 0; i < cart.NumOfBooks; i++) {
        Book* book = searchBookByISBN(cart.b[i]->ISBN);
        if (book!=0) {
            if (book->NumOfCopies > 0) {
                book->updateInventory(-1); // Reduce the number of copies
            } else {
                cout << "Book out of stock: " << cart.b[i]->title << endl;
            }
        } else {
            cout << "Book not found: " << cart.b[i]->ISBN << endl;
        }
    }
}
~Store() {
    for (int i = 0; i < NumBooks; i++) {
        delete inventory[i];  // Delete each dynamically allocated book
    }
}

};
