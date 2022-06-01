//
// Created by msyu on 30.05.2022.
//

#ifndef PROTOTYP_DOUBLYLINKEDLIST_H
#define PROTOTYP_DOUBLYLINKEDLIST_H


#include "extendedListItem.h"
#include <iostream>

class ExtendedListItem;

struct doublyLinkedList {
public:
    doublyLinkedList();

    ExtendedListItem* head;
    ExtendedListItem* tail;
    void insertSorted(int key);

    void append(doublyLinkedList* appendingList);
    void splice(doublyLinkedList* insertingList, int position);
    void insertAtStart(int key);
    void insertAtEnd(int key);
    void deleteItem(int key);
    void print();

private:


};

#endif //PROTOTYP_DOUBLYLINKEDLIST_H
