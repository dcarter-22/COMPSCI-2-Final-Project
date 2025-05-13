#ifndef LIBRARY_H
#define LIBRARY_H
#include <sstream>

#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include "BST.h"
#include "Queue.h"

#include <unordered_map>
#include <fstream>

using namespace std;

class Library
{
private:
    BST<Book> bookTree;
    unordered_map<int, Member> members;
    SimpleQueue<int> returnQueue;
    vector<Transaction> transactions;
    int nextTransactionId;

    static bool compareBooks(const Book *a, const Book *b)
    {
        return a->getTitle() < b->getTitle();
    }

public:
    Library()
    {
        nextTransactionId = 1;
    }

    void addBook(Book *book)
    {
        bookTree.insert(book, compareBooks);
    }

    void addMember(Member member)
    {
        members.insert({member.getId(), member});
    }

    bool borrowBook(int memberId, int bookId)
    {
        Member &m = members.at(memberId);
        /* Simple linear search because ids are unique and small */
        bool found = false;
        Book *target = nullptr;
        bookTree.inorder([&](Book *b)
        {
            if (b->getId() == bookId)
            {
                found = true;
                target = b;
            }
        });
        if (!found || !target->isAvailable())
        {
            return false;
        }
        if (!m.borrowBook(bookId))
        {
            return false;
        }
        target->setAvailable(false);

        Transaction t;
        t.id = nextTransactionId++;
        t.bookId = bookId;
        t.memberId = memberId;
        t.type = "BORROW";
        t.time = time(nullptr);
        transactions.push_back(t);
        return true;
    }

    bool requestReturn(int memberId, int bookId)
    {
        Member &m = members.at(memberId);
        if (!m.returnBook(bookId))
        {
            return false;
        }
        returnQueue.enqueue(bookId);
        return true;
    }

    void processReturns()
    {
        while (!returnQueue.isEmpty())
        {
            int bookId = returnQueue.dequeue();
            bookTree.inorder([&](Book *b)
            {
                if (b->getId() == bookId)
                {
                    b->setAvailable(true);
                }
            });

            Transaction t;
            t.id = nextTransactionId++;
            t.bookId = bookId;
            t.memberId = -1;
            t.type = "RETURN";
            t.time = time(nullptr);
            transactions.push_back(t);
        }
    }

    void listBooks()
    {
        bookTree.inorder([](Book *b)
        {
            b->display();
        });
    }

    /* File I/O for books only to keep it short */
    void saveBooks(string filename)
    {
        ofstream out(filename);
        bookTree.inorder([&](Book *b)
        {
            out << b->getId() << "," << b->getTitle()
                << "," << b->getAuthor() << "," << b->getGenre()
                << "," << b->isAvailable() << endl;
        });
        out.close();
    }

    void loadBooks(string filename)
    {
        ifstream in(filename);
        if (!in) return;
        string line;
        while (getline(in, line))
        {
            stringstream ss(line);
            string idS, title, author, genre, availS;
            getline(ss, idS, ',');
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, genre, ',');
            getline(ss, availS, ',');
            int id = stoi(idS);
            bool avail = (availS == "1");
            Book *b = new Book(id, title, author, genre);
            b->setAvailable(avail);
            addBook(b);
        }
        in.close();
    }
};

#endif
