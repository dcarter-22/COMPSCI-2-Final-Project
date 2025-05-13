#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>

using namespace std;

class Member
{
private:
    int id;
    string name;
    vector<int> borrowed;

public:
    Member(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    bool borrowBook(int bookId)
    {
        if (borrowed.size() >= 5)
        {
            return false;
        }
        borrowed.push_back(bookId);
        return true;
    }

    bool returnBook(int bookId)
    {
        for (auto it = borrowed.begin(); it != borrowed.end(); ++it)
        {
            if (*it == bookId)
            {
                borrowed.erase(it);
                return true;
            }
        }
        return false;
    }

    void listBorrowed()
    {
        cout << name << " has borrowed: ";
        for (int id : borrowed)
        {
            cout << id << " ";
        }
        cout << endl;
    }
};

#endif
