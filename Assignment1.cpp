// ASU CSE310 Spring 2025 Assignment #1
// Name: Yash Bunga
// ASU ID: 1229442476
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//---- is where you should add your own code

//add your own code
//----
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList bookList;
    char choice;

    do {
        // Display the menu
        cout << "Choice\t\tAction" << endl;
        cout << "------\t\t------" << endl;
        cout << "A\t\tAdd a Book" << endl;
        cout << "C\t\tChange a Book Title" << endl;
        cout << "D\t\tDisplay All Books" << endl;
        cout << "E\t\tDisplay Books by Title" << endl;
        cout << "F\t\tFind a Book" << endl;
        cout << "U\t\tUpdate a Book Price" << endl;
        cout << "R\t\tRemove a Book" << endl;
        cout << "N\t\tRemove Books by Edition" << endl;
        cout << "T\t\tRemove Books by Title" << endl;
        cout << "Q\t\tQuit" << endl;
        cout << "? \t\tDisplay Help" << endl;
        cout << "What action would you like to perform? ";
        cin >> choice;
        cin.ignore();  // to ignore the newline character left in the buffer

        switch (choice) {
            case 'A': {
                string title, edition;
                int pages;
                double price;
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book edition: ";
                getline(cin, edition);
                cout << "Enter book pages: ";
                cin >> pages;
                cout << "Enter book price: ";
                cin >> price;
                cin.ignore();  // Ignore the newline character

                Book newBook(title, edition, pages, price);
                bookList.addBook(newBook);
                break;
            }

            case 'D': {
                bookList.displayBooks();
                break;
            }

            case 'E': {
                string title;
                cout << "Enter the book title you want to display: ";
                getline(cin, title);
                bookList.displayBooksByTitle(title);
                break;
            }

            case 'F': {
                string title, edition;
                cout << "Please enter the book title you want to find: ";
                getline(cin, title);
                cout << "Please enter the book edition: ";
                getline(cin, edition);
                bookList.findBook(title, edition);
                break;
            }

            case 'N': {
                string edition;
                cout << "Enter edition to remove: ";
                getline(cin, edition);
                bookList.removeBooksByEdition(edition);
                break;
            }

            case 'T': {
                string title;
                cout << "Enter book title to remove: ";
                getline(cin, title);
                bookList.removeBooksByTitle(title);
                break;
            }

            case 'Q':
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'Q');

    return 0;
}
