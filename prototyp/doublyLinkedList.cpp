#include "doublyLinkedList.h"
#include <iostream>
#include <string>

doublyLinkedList::doublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void doublyLinkedList::append(doublyLinkedList* appendingList) {
    if(appendingList->head != nullptr && appendingList->tail != nullptr){
        this->tail->next = appendingList->head;
        appendingList->head->previous = this->tail;
        this->tail = appendingList->tail;
        appendingList->head = nullptr;
        appendingList->tail = nullptr;
    }
}


void doublyLinkedList::splice(doublyLinkedList* insertingList, int position) {
    if(insertingList->head != nullptr && insertingList->tail != nullptr){
        ExtendedListItem* prev = nullptr;
        ExtendedListItem* current = nullptr;
        current = this->head;
        // find the correct position to start spliceing
        for(int i = 0; i < position; i++) {
            prev = current;
            current = current->next;
        }
        // set the pointers correctly
        prev->next = insertingList->head;
        insertingList->head->previous = prev;
        insertingList->tail->next = current;
        current->previous = insertingList->tail;

        // clear the inserting list
        insertingList->head = nullptr;
        insertingList->tail = nullptr;
    }
}


void doublyLinkedList::insertAtStart(int key) {
    ExtendedListItem* temp = new ExtendedListItem(key);

    if(this->head == nullptr) {
        this->head = temp;
        this->head->next = nullptr;
        this->head->previous = nullptr;
        this->tail = temp;
        this->tail->previous = nullptr;
        this->tail->next = nullptr;
    } else {
        this->head->previous = temp;
        temp->next = this->head;
        temp->previous = nullptr;
        this->head = temp;
    }
}

void doublyLinkedList::insertAtEnd(int key) {
    ExtendedListItem* temp = new ExtendedListItem(key);

    if(this->head == nullptr) {
        this->head = temp;
        this->head->next = nullptr;
        this->head->previous = nullptr;
        this->tail = temp;
        this->tail->previous = nullptr;
        this->tail->next = nullptr;
    } else {
        temp->previous = this->tail;
        temp->next = nullptr;
        this->tail->next = temp;
        this->tail = temp;
    }
}

void doublyLinkedList::insertSorted(int key) {
    ExtendedListItem* prev = nullptr;
    ExtendedListItem* current = this->head;
    ExtendedListItem* newItem = new ExtendedListItem(key); //create the new ListItem

    if(this->head == nullptr || key < this->head->key){// list is empty OR new is samller than head->key => insert at front
        this->insertAtStart(key);
        return;
    }

    if(key > this->tail->key){ // new key is larger than tail->key=> insert at end
        this->insertAtEnd(key);
        return;
    }
    // search for correct position to insert
    bool inserted = false;
    while(inserted == false){
        prev = current;
        current = current->next;

        if(key < current->key){
            prev->next = newItem;
            newItem->next = current;
            inserted = true;
        } else {
            continue;
        }
    }
}

void doublyLinkedList::deleteItem(int key) {

    ExtendedListItem* current = nullptr;
    ExtendedListItem* del = nullptr;

    if(this->head != nullptr && this->tail != nullptr){
        current = this->head;

        while(current != nullptr){

            if (current->next == nullptr){
                break;
            }

            current = current->next;

            if(current->key == key){
                del = current;
                if(this->head == del){
                    this->head = del->next;
                }

                if (del->next != nullptr){
                    del->next->previous = del->previous;
                }

                if(del->previous != nullptr){
                    del->previous->next = del->next;
                }

                return;
            }
        }
        std::cout << "delete Item Key: " << key << " not found!" << std::endl;
    }

}

void doublyLinkedList::print() {
    ExtendedListItem* temp = this->head;

    if(temp == nullptr){
        std::cout << "<Empty List>" << std::endl;
        return;
    }

    while(temp != nullptr){
        std::cout << temp->toString();
        if(temp->next != nullptr){
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}