#include"Cart.h"
#include <iostream>
using namespace std;
#include"Store.h"
int main() {
	Store store;
	Cart cart;

	// Add books to the store
	store.addBook(new Book("1234", "Book 1", "john", 10, 5));
	store.addBook(new Book("0987", "Book 2", "emily", 9, 3));

	int choice;

	do {
		cout << "1. View all books" << endl;
		cout << "2. Add book to cart" << endl;
		cout << "3. Remove book from cart" << endl;
		cout << "4. Checkout" << endl;
		cout << "5. Add a new book to inventory" << endl;
		cout << "6. Exit" << endl;

		cout<< "Enter Your Choice " << endl;
		while (!(cin >> choice) || choice < 1 || choice > 6) {
			cout << "Invalid choice! Please re-enter: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		if (choice == 1) {
			store.displayAvailableBooks();
		} else if (choice == 2) {
			string ISBN;
			cout << "Enter ISBN: ";
			cin >> ISBN;
			Book* book = store.searchBookByISBN(ISBN);
			if (book && book->NumOfCopies > 0) {
				cart.addBook(book);
			} else {
				cout << "Book not available" << endl;
			}
		} else if (choice == 3) {
			string ISBN;
			cout << "Enter ISBN: ";
			cin >> ISBN;
			Book* book = store.searchBookByISBN(ISBN);
			cart.removeBook(book);
		} else if (choice == 4) {
			store.checkOut(cart);
			cart.NumOfBooks = 0;
			cart.TotalCost = 0;

		} else if (choice == 5) {
			// Add a new book to inventory
			string ISBN, title, author;
			double price;
			int NumOfCopies;

			cout << "Enter ISBN: ";
			cin >> ISBN;
			while (ISBN.empty()) {
				cout << "Error: ISBN cannot be empty. Please re-enter: ";
				cin >> ISBN;
			}

			if (store.searchBookByISBN(ISBN)) {                  // Check for duplicate ISBN
				cout << "Error: A book with this ISBN already exists in the inventory." << endl;
				continue; 
			}
			cout << "Enter Title: ";
			cin.ignore(); // Ignore the newline character 
			getline(cin, title);
			while (title.empty()) {
				cout << "Error: Title cannot be empty. Please re-enter: ";
				getline(cin, title);
			}
			cout << "Enter Author: ";
			getline(cin, author);
			while (author.empty()) {
				cout << "Error: Author cannot be empty. Please re-enter: ";
				getline(cin, author);
			}
			cout << "Enter Price: ";
			while (!(cin >> price) || price < 0) {
				cout << "Error: Price must be a non-negative number. Please re-enter: ";
				cin.clear(); // Clear the error flag on cin
				cin.ignore(1000, '\n'); // Ignore the rest of the invalid input
			}
			cout << "Enter Number of Copies: ";
			while (!(cin >> NumOfCopies) || NumOfCopies < 0) {
				cout << "Error: Number of copies must be a non-negative integer. Please re-enter: ";
				cin.clear(); // Clear the error flag on cin
				cin.ignore(1000, '\n'); // Ignore the rest of the invalid input
			}
                                                                      
			Book* newBook = new Book(ISBN, title, author, price, NumOfCopies);  // Add book to inventory 
			store.addBook(newBook);
			cout << "Book added to inventory successfully!" << endl;
		}
		else if (choice != 6) {
			cout << "Invalid choice, please try again." << endl;
		}

	} while (choice != 6);

	return 0;
}
