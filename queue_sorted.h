#ifndef TASK1_QUEUE_SORTED_H
#define TASK1_QUEUE_SORTED_H


#include "DoubleNode.h"
#include <memory>
#include <iostream>
#include "out_of_list.h"
#include "no_element.h"


using namespace std;
using namespace DoubleNode;

template <typename T>
class queue_sorted {
private:
    int size;
    shared_ptr<DoubleNode::Node<T>> head;
    shared_ptr<DoubleNode::Node<T>> tail;
    void AddToBegining(T obj);
    void AddToEnd(T obj);
public:
    queue_sorted(): head{nullptr}, tail{nullptr}, size{0}{}
    queue_sorted(T &&value): head{make_shared<DoubleNode::Node<T>>(value)}, tail{head}, size{1}{}
    ~queue_sorted(){
        //cout << "queue destructor was called" << endl;
    }
    void Print();
    void Enqueue(T obj);
    void Dequeue();
    T Peek();
    bool IsEmpty();

};

#endif //TASK1_QUEUE_SORTED_H
