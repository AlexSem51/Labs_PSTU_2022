#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <QQueue>
#include <QDebug>

template<class T>
class PriorityQueue
{
public:
    PriorityQueue()
    {}
    void enqueue(int priority,T value)
    {
        Item<T> item(priority,value);
        for(int i = 0 ; i < _queue.count() ; ++i ) {
            const Item<T>& otherItem = _queue[i];
            if( priority > otherItem._priority )  {
                _queue.insert(i,item);
                return;
            }
        }
        _queue.append(item);
    }

    T dequeue()
    {
        const Item<T>& item = _queue.dequeue();
        return item._value;
    }

    int count()
    {
        return _queue.count();
    }

    void update(int old_priority, T value,int new_priority){
        PriorityQueue new_queue;
        for(int i=0;i<count();++i){
            const Item<T>& otherItem = _queue[i];
            if(otherItem._priority!=old_priority || otherItem._value!=value){
                new_queue.enqueue(otherItem._priority,otherItem._value);
            }
        }
        new_queue.enqueue(new_priority,value);
        new_queue._queue.swap(_queue);
    }

private:

    template<class C>
    struct Item
    {
        int _priority;
        C _value;

        Item(int priority, C value)
        {
            _priority = priority;
            _value = value;
        }
    };

    QQueue< Item<T > > _queue;

};

#endif // PRIORITY_QUEUE_H
