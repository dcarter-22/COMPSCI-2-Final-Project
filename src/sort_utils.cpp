#include "Book.h"
#include <vector>

using namespace std;

void quicksortBooks(vector<Book*> &arr, int low, int high)
{
    if (low >= high) return;
    int i = low;
    int j = high;
    Book *pivot = arr[(low + high) / 2];
    while (i <= j)
    {
        while (arr[i]->getTitle() < pivot->getTitle()) i++;
        while (arr[j]->getTitle() > pivot->getTitle()) j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (low < j) quicksortBooks(arr, low, j);
    if (i < high) quicksortBooks(arr, i, high);
}
