#ifndef GLOBAL_H
#define GLOBAL_H

#include <QList>

namespace hooman
{
static int y = -225;
static int block = 450;
static int x = -30;

template <class T>
class myQueue
{
private:
    QList<T> *a;

public:
    myQueue(){a = new QList<T>();}
    void enqueue(T& in){a->append(in);}
    T dequeue()
    {

        if (a->count() == 0)
        {
            T *temp = 0;
            return *temp;
        }
        return a->takeLast();
    }
    bool isEmpty(){return a->count() == 0;}
    void clear()
    {
        delete a;
        a = new QList<T>();
    }
    ~myQueue(){delete a;}
};



}
#endif // GLOBAL_H
