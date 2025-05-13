#include <iostream>
#include "Library.h"

using namespace std;

void menu()
{
    cout << "\n1. Add book" << endl;
    cout << "2. Add member" << endl;
    cout << "3. Borrow book" << endl;
    cout << "4. Request return" << endl;
    cout << "5. Process returns" << endl;
    cout << "6. List books" << endl;
    cout << "0. Quit" << endl;
    cout << "-> ";
}

int main()
{
    Library lib;

    Book *b1 = new Book(1, "1984", "George Orwell", "Dystopian");
    Book *b2 = new Book(2, "Dune", "Frank Herbert", "SciFi");
    lib.addBook(b1);
    lib.addBook(b2);

    lib.addMember(Member(1, "Alice"));

    int choice;
    while (true)
    {
        menu();
        cin >> choice;
        if (choice == 0) break;

        if (choice == 1)
        {
            int id;
            string title, author, genre;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Title: ";
            getline(cin, title);
            cout << "Author: ";
            getline(cin, author);
            cout << "Genre: ";
            getline(cin, genre);
            lib.addBook(new Book(id, title, author, genre));
        }
        else if (choice == 2)
        {
            int id;
            string name;
            cout << "Member ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            lib.addMember(Member(id, name));
        }
        else if (choice == 3)
        {
            int mId, bId;
            cout << "Member ID: ";
            cin >> mId;
            cout << "Book ID: ";
            cin >> bId;
            if (lib.borrowBook(mId, bId))
            {
                cout << "Success!" << endl;
            }
            else
            {
                cout << "Borrow failed." << endl;
            }
        }
        else if (choice == 4)
        {
            int mId, bId;
            cout << "Member ID: ";
            cin >> mId;
            cout << "Book ID: ";
            cin >> bId;
            if (lib.requestReturn(mId, bId))
            {
                cout << "Return requested." << endl;
            }
            else
            {
                cout << "Return failed." << endl;
            }
        }
        else if (choice == 5)
        {
            lib.processReturns();
            cout << "Processed all returns." << endl;
        }
        else if (choice == 6)
        {
            lib.listBooks();
        }
    }

    lib.saveBooks("books.txt");
    return 0;
}
