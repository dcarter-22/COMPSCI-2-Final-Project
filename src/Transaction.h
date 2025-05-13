#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <iostream>

using namespace std;

struct Transaction
{
    int id;
    int bookId;
    int memberId;
    string type; /* BORROW or RETURN */
    time_t time;

    void display()
    {
        cout << id << ": member " << memberId << " " << type
             << " book " << bookId << " on " << ctime(&time);
    }
};

#endif
