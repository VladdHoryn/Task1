#include "queue_sorted.h"

template <typename T>
void queue_sorted<T>::Print() {
    DoubleNode::Node<T> *obj = head.get();
    for (int i = 0; i <= size; ++i) {
        cout << obj->data << " ";
        obj = obj->next.get();
    }
    cout << endl;
}

template <typename T>
void queue_sorted<T>::AddToBegining(T obj) {
    shared_ptr<DoubleNode::Node<T>> temporary = make_shared<DoubleNode::Node<T>>(obj);
    if(!head)
        head = tail = temporary;
    else {
        temporary->next = head;
        head->previous = temporary;
        head = temporary;
    }
    size++;
}
template <typename T>
void queue_sorted<T>::AddToEnd(T obj) {
    shared_ptr<DoubleNode::Node<T>> temporary = make_shared<DoubleNode::Node<T>>(obj);
    if(!tail)
        head = tail = temporary;
    else {
        tail->next = temporary;
        temporary->previous = tail;
        tail = temporary;
    }
    ++size;
}


template <typename T>
void queue_sorted<T>::Enqueue(T obj) {
    shared_ptr<DoubleNode::Node<T>> temporary = make_shared<DoubleNode::Node<T>>(obj);
    shared_ptr<DoubleNode::Node<T>> temp = head;
    int step = 1;
    bool test = false;
    if(!head)
    {
        head = tail = temporary;
    }
    else
    if(temp->data >= temporary->data)
    {
        AddToBegining(obj);
    }
    else
    {
        while(temp->next->data <= temporary->data)
        {
            ++step;
            temp = temp->next;
            if(step == size)
            {
                test = true;
                break;
            }
        }
        if(test)
        {
            AddToEnd(obj);
        }
        else {
            temporary->next = temp->next;
            temporary->previous = temp;
            temp->next = temporary;
            temp->next->previous = temporary;
            ++size;
        }
    }
}
template <typename T>
void queue_sorted<T>::Dequeue() {
    if(!tail)
        throw no_element("No elements in list");
    if(head == tail)
        head = tail = nullptr;
    else
    {
        tail->previous = tail;
        tail->next.reset();
    }
    --size;
}
template <typename T>
T queue_sorted<T>::Peek() {
    return tail->data;
}
template <typename T>
bool queue_sorted<T>::IsEmpty() {
    if(size == 0)
        return true;
    return false;
}