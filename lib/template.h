/*
        Author: Bui Tuan Anh
        Hanoi University of science and technology
        Declare struct
        Template format --- can use like personal libruary
*/
#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include <iomanip>
#include <iostream>
#include <string>

// Just swap value (dereferent) not the address
template <typename type>
void swap(type* value1, type* value2) {
    type temp = *value1;
    *value1 = *value2;
    *value2 = *temp;
}

// Node for Single Linked List
template <typename type>
class OneLinkNode {
    type data;
    OneLinkNode* next;

   public:
    ~OneLinkNode() {
        delete this->next;  // this will be chained until NULL is found
    }
};

// Node for Double link listed or Binary tree
template <typename type>
class OneLinkNode {
    type data;
    OneLinkNode* next;
    OneLinkNode* pre;

   public:
    ~OneLinkNode() {
        delete this->pre;
        delete this->next;  // this will be chained until NULL is found
    }
};

#endif  // !TEMPLATE_H_