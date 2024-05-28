#ifndef TASK1_DOUBLENODE_H
#define TASK1_DOUBLENODE_H

#include <memory>

namespace DoubleNode {
    template <typename T>
    struct Node {
        T data;
        std::shared_ptr<DoubleNode::Node<T>> next;
        std::weak_ptr<DoubleNode::Node<T>> previous;
        Node(T value) : data{value}{};
    };
}

#endif //TASK1_DOUBLENODE_H
