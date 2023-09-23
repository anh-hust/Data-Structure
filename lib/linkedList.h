/*
        Author: Bui Tuan Anh
        Hanoi University of science and technology
        Class of Singly Linked List and Doubly Linked List
        Tested and run fine---3/11/2022 (Month/Day/Year)
        Template format --- can use like personal libruary
*/
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "template.h"

template <typename type>
class SingleLinkedList {
   private:
    OneLinkNode<type>* head;

   public:
    SingleLinkedList() {
        this->head = nullptr;
    }
    ~SingleLinkedList() {
        delete head;
    }
    OneLinkNode<type>* getHead() {
        return this->head;
    }
    int getLength() {
        if (this->getHead() == nullptr) return 0;
        // travel through list to take length of itself
        uint32_t length = 0;
        OneLinkNode<type>* travel = this->getHead();
        while (travel != nullptr) {
            travel = travel->next;
            length += 1;
        }
        return length;
    }

    OneLinkNode<type>* newNode(type value) {
        OneLinkNode<type>* newNode = new OneLinkNode<type>;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }
    void insertHead(type value) {
        OneLinkNode<type>* elem = newSinglyNode(value);
        if (this->getHead() != nullptr)
            elem->next = this->getHead();
        this->getHead() = elem;
    }
    void insertPosition(type value, uint32_t position) {
        uint32_t length = getLength();

        if (position >= this->getLength()) {
            std::cout << "Position exceed the length of linked list (" length << ")" << std::endl;
            return;
        }
        // if head
        if (position == 0) {
            this->insertHead();
            return;
        }
        OneLinkNode<type>* elem = this->newNode(value);
        OneLinkNode<type>* travel = this->getHead();
        for (uint32_t i = 0; i <= position - 1; i++) {
            travel = travel->next;
        }
        elem->next = travel->next;
        travel->next = elem;
    }
    void insertTail(type value) {
        OneLinkNode<type>* elem = newNode(value);
        if (this->getHead() == nullptr)
            this->getHead() = elem;
        else {
            OneLinkNode<type>* travel = this->getHead();
            // travel to the end of linked list
            while (travel->next != nullptr) {
                travel = travel->next;
            }
            travel->next = elem;
        }
    }
    void deleteHead() {
        if (this->getHead() == nullptr)
            return;
        OneLinkNode<type>* travel = this->getHead();
        this->getHead() = travel->next;
    }

    // @NOTE Maintain here
    void deletePosition(uint32_t position) {
        if (head == nullptr) return;
        int length = getLength();
        if (position == 1) {
            deleteHead();
            return;
        }
        if (position > length || position <= 0) {
            cout << "Curent length of linked list: " << length << " ,start from 1" << endl;
            return;
        }
        OneLinkNode<type>* travel1 = head;
        for (int i = 0; i < position - 2; i++) {
            travel1 = travel1->next;  // point to (n-1)th element
        }
        OneLinkNode<type>* travel2 = travel1->next;  // travel2 point to nth element
        travel1->next = travel2->next;               // fix the link
        delete travel2;                              // delete nth element
    }
    void deleteTail() {
        if (head == nullptr) return;
        OneLinkNode<type>* travel = head;
        while (travel->next->next != nullptr) {
            travel = travel->next;
        }
        delete travel->next;
        travel->next = nullptr;
    }
    void reverse() {
        if (head == nullptr) return;
        OneLinkNode<type>*prev, *current, *n_next;
        current = head;
        prev = nullptr;
        while (current != nullptr) {
            n_next = current->next;
            current->next = prev;
            prev = current;
            current = n_next;
        }
        head = prev;
    }
    // How to use: reverse_useRecurtion("name of class SLL".getHead());
    void reverse_useRecurtion(OneLinkNode<type>* travel) {
        if (travel == nullptr) return;
        if (travel->next == nullptr) {
            head = travel;
            return;
        }
        reverse_useRecurtion(travel->next);
        travel->next->next = travel;
        travel->next = nullptr;
    }
    void print() {
        if (head == nullptr) {
            cout << "nullptr" << endl;
            return;
        }
        OneLinkNode<type>* travel = head;
        while (travel != nullptr) {
            cout << travel->data << " ";
            travel = travel->next;
        }
        cout << endl;
    }
    // How to use: "name of class SLL".print_useRecursion("name of class SLL".getHead());
    // just print, dont change the link
    void print_useRecurtion(OneLinkNode<type>* travel) {
        if (travel == nullptr) {
            cout << endl;
            return;
        }
        cout << travel->data << " ";
        print_useRecurtion(travel->next);
    }
    // How to use: "name of class SLL".reversePrint_useRecursion("name of class SLL".getHead());
    // just print, dont reverse the linked list
    void reversePrint_useRecurtion(OneLinkNode<type>* travel) {
        if (travel == nullptr) {
            cout << endl;
            return;
        }
        reversePrint_useRecurtion(travel->next);
        cout << travel->data << " ";
    }
};

template <typename type>
class DoublyLinkedList {
   private:
    DoublyNode<type>* head;

   public:
    DoublyLinkedList() {
        head = nullptr;
    }
    DoublyNode<type>* getHead() {
        return head;
    }
    int getLength() {
        if (head == nullptr) return 0;
        DoublyNode<type>* travel = head;
        int count = 0;
        while (travel != nullptr) {
            travel = travel->next;
            count += 1;
        }
        return count;
    }
    DoublyNode<type>* newDoublyNode(type value) {
        DoublyNode<type>* newNode = new DoublyNode<type>;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }
    void insertHead(type value) {
        DoublyNode<type>* insert = newDoublyNode(value);
        if (head != nullptr) {
            head->prev = insert;
            insert->next = head;
        }
        head = insert;
    }
    void insertPosition(type value, int position) {
        int length = getLength();
        if (position == 1) {
            insertHead(value);
            return;
        }
        if (position > length + 1 || position < 0) {
            cout << "Current length of Doubly linked list: " << length << endl;
            return;
        }
        DoublyNode<type>* insert = newDoublyNode(value);
        DoublyNode<type>* travel = head;
        for (int i = 0; i < position - 2; i++) {
            travel = travel->next;
        }
        insert->next = travel->next;
        if (travel->next != nullptr) travel->next->prev = insert;
        travel->next = insert;
        insert->prev = travel;
    }
    void insertTail(type value) {
        DoublyNode<type>* insert = newDoublyNode(value);
        if (head == nullptr)
            head = insert;
        else {
            DoublyNode<type>* travel = head;
            while (travel->next != nullptr) {
                travel = travel->next;
            }
            travel->next = insert;
            insert->prev = travel;
        }
    }
    void deleteHead() {
        if (head == nullptr) return;
        DoublyNode<type>* travel = head;
        head = travel->next;
        travel->next->prev = nullptr;
        delete travel;
    }
    void deletePosition(int position) {
        int length = getLength();
        if (position == 1) {
            deleteHead();
            return;
        }
        if (position > length || position < 0) {
            cout << "Current length of Doubly linked list: " << length << endl;
            return;
        }
        DoublyNode<type>* travel = head;
        for (int i = 0; i < position - 2; i++) {
            travel = travel->next;
        }
        DoublyNode<type>* temp = travel->next;
        travel->next = temp->next;
        temp->next->prev = travel;
        delete temp;
    }
    void deleteTail() {
        if (head == nullptr) return;
        DoublyNode<type>* travel = head;
        while (travel->next->next != nullptr) {
            travel = travel->next;
        }
        travel->next->prev = nullptr;
        delete travel->next;
        travel->next = nullptr;
    }
    // dont need to fix the link, just reverse the data
    void reverse() {
        if (head == nullptr) return;
        DoublyNode<type>* travelH = head;  // travelHead, run from head to tail
        DoublyNode<type>* travelT = head;  // travelTail, run from tail to head
        type temp;                         // temporary variable to swap data
        int length = getLength();
        while (travelT->next != nullptr) {
            travelT = travelT->next;
        }
        for (int i = 0; i < (length / 2); i++) {
            temp = travelH->data;
            travelH->data = travelT->data;
            travelT->data = temp;
            travelH = travelH->next;
            travelT = travelT->prev;
        }
    }
    void print() {
        if (head == nullptr) {
            cout << "nullptr" << endl;
            return;
        }
        DoublyNode<type>* travel = head;
        while (travel != nullptr) {
            cout << travel->data << " ";
            travel = travel->next;
        }
        cout << endl;
    }
    // How to use: "name of DLL class".print_useRecurtion("name of DLL class".getHead());
    //  DLL: Doubly Linked List
    void print_useRecurtion(DoublyNode<type>* travel) {
        if (travel == nullptr) {
            cout << endl;
            return;
        }
        cout << travel->data << " ";
        print_useRecurtion(travel->next);
    }
    // just print, dont fix link
    // How to use: "name of DLL class".reversePrint_useRecurtion("name of DLL class".getHead());
    // DLL: Doubly Linked List
    void reverseprint_useRecurtion(DoublyNode<type>* travel) {
        if (travel == nullptr) {
            cout << endl;
            return;
        }
        reverseprint_useRecurtion(travel->next);
        cout << travel->data << " ";
    }
};

#endif  // !LINKEDLIST_H_
