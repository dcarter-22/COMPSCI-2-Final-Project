#include "Library.h"
#include <cassert>

int main()
{
    Library lib;
    lib.addBook(new Book(1, "A", "Author", "Fiction"));
    lib.addBook(new Book(2, "B", "Author", "Fiction"));
    lib.addMember(Member(1, "Test"));        

    assert(lib.borrowBook(1, 1) == true);
    assert(lib.borrowBook(1, 1) == false); /* already borrowed */
    assert(lib.requestReturn(1, 1) == true);

    lib.processReturns();

    /* Borrow again should succeed */
    assert(lib.borrowBook(1, 1) == true);

    cout << "All tests passed!" << endl;
    return 0;
}
