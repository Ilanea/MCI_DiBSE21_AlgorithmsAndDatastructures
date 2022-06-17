//
// Created by msyu on 30.05.2022.
//

#ifndef PROTOTYP_DOUBLYLINKEDLIST_H
#define PROTOTYP_DOUBLYLINKEDLIST_H


#include "extendedListItem.h"
#include <iostream>

class ExtendedListItem;

struct DoublyLinkedList {
public:
    DoublyLinkedList();

    ExtendedListItem* head;
    ExtendedListItem* tail;
    void insertSorted(int key);

    void append(DoublyLinkedList* appendingList);
    void splice(DoublyLinkedList* insertingList, int position);
    void insertAtStart(int key);
    void insertAtEnd(int key);
    void deleteItem(int key);
    void print();

private:


};

#endif //PROTOTYP_DOUBLYLINKEDLIST_H
