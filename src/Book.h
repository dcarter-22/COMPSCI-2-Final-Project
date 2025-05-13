#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    string genre;
    bool available;

public:
    Book(int id, string title, string author, string genre)
    {
        this->id = id;
        this->title = title;
        this->author = author;
        this->genre = genre;
        available = true;
    }

    int getId()
    {
        return id;
    }

    string getTitle() const
    {
        return title;
    }


    string getAuthor()
    {
        return author;
    }

    string getGenre()
    {
        return genre;
    }

    bool isAvailable()
    {
        return available;
    }

    void setAvailable(bool status)
    {
        available = status;
    }

    void display()
    {
        cout << "[" << id << "] " << title << " by " << author
             << " (" << genre << ") - "
             << (available ? "Available" : "Checked Out") << endl;
    }
};

#endif
