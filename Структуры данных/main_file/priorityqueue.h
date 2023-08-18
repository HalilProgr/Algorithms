
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>


// даже не знаю как подойти к вопросу.
// Сделаю по спецификации std-шной

// ! Так блять, пока оставлю, чуть позже сяду и найду реализацию толковую!

template <class T,
          class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
class PriorityQueue
{
public:
    PriorityQueue();


};

#endif // PRIORITYQUEUE_H
