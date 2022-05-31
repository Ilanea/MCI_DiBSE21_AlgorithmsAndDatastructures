//
// Created by msyu on 30.05.2022.
//

#ifndef PROTOTYP_DOUBLYLINKEDLIST_H
#define PROTOTYP_DOUBLYLINKEDLIST_H


class doublyLinkedList {
protected:

public:
    void append(doublyLinkedList* appendingList);
    void splice(doublyLinkedList* insertingList, int position);
    void insertAtStart(int key);
    void insertAtEnd(int key);
    void deleteItem(int key);
    void print();

};


#endif //PROTOTYP_DOUBLYLINKEDLIST_H
