#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H

#include <queue>
using namespace std;

template <typename T>
class SimpleQueue
{
private:
    queue<T> q;

public:
    void enqueue(T value)
    {
        q.push(value);
    }

    bool isEmpty()
    {
        return q.empty();
    }

    T dequeue()
    {
        if (q.empty())
        {
            throw runtime_error("Queue empty");
        }
        T val = q.front();
        q.pop();
        return val;
    }

    size_t size()
    {
        return q.size();
    }
};

#endif
