// ASU CSE310 Spring 2025 Assignment #1
// Name: Yash Bunga
// ASU ID: 1229442476
// Description: This is the linked list of the book

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Book {
public:
    string title;
    string edition;
    int pages;
    double price;

    Book(string t, string e, int p, double pr) : title(t), edition(e), pages(p), price(pr) {}
};

class LinkedList {
private:
    vector<Book> bookList;  // Using a vector to store books for easier management

public:
    // Add a book to the list
    void addBook(const Book &newBook) {
        bool isDuplicate = false;
        for (auto &book : bookList) {
            if (book.title == newBook.title && book.edition == newBook.edition) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {
            cout << "Duplicated Book. Not added." << endl;
        } else {
            bookList.push_back(newBook);
            cout << "Book: \"" << newBook.title << "\", " << newBook.edition << " edition is added" << endl;
        }
    }

    // Display all books
    void displayBooks() const {
        if (bookList.empty()) {
            cout << "No books to display." << endl;
            return;
        }

        cout << left << setw(30) << "Title" << setw(10) << "Edition" << setw(10) << "Pages" << setw(10) << "Price" << endl;
        for (const auto &book : bookList) {
            cout << left << setw(30) << book.title << setw(10) << book.edition << setw(10) << book.pages << setw(10) << fixed << setprecision(2) << book.price << endl;
        }
    }

    // Display books by title
    void displayBooksByTitle(const string &title) const {
        bool found = false;
        for (const auto &book : bookList) {
            if (book.title == title) {
                cout << left << setw(30) << book.title << setw(10) << book.edition << setw(10) << book.pages << setw(10) << fixed << setprecision(2) << book.price << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the title \"" << title << "\"." << endl;
        }
    }

    // Find a specific book
    void findBook(const string &title, const string &edition) const {
        bool found = false;
        for (const auto &book : bookList) {
            if (book.title == title && book.edition == edition) {
                cout << "Book: \"" << title << "\", " << edition << " edition is Found" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book: \"" << title << "\", " << edition << " edition is NOT Found" << endl;
        }
    }

    // Remove books by edition
    void removeBooksByEdition(const string &edition) {
        int removedCount = 0;
        for (auto it = bookList.begin(); it != bookList.end(); ) {
            if (it->edition == edition) {
                it = bookList.erase(it);
                removedCount++;
            } else {
                ++it;
            }
        }
        cout << "The number of deleted Book is: " << removedCount << endl;
    }

    // Remove books by title
    void removeBooksByTitle(const string &title) {
        int removedCount = 0;
        for (auto it = bookList.begin(); it != bookList.end(); ) {
            if (it->title == title) {
                it = bookList.erase(it);
                removedCount++;
            } else {
                ++it;
            }
        }
        cout << "The number of deleted Book is: " << removedCount << endl;
    }
};

#endif
