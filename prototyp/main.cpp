#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include "Sortiment.h"
#include "extendedBinaryTree.h"
#include "doublyLinkedList.h"
#include "extendedAvlTree.h"
#include "hashTableChaining.h"

std::string random_string(int Dist, std::size_t length){
    const std::string CHARACTERS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(0, Dist);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i){
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int main() {

    srand((unsigned) time(NULL));

    Sortiment *sortiment = new Sortiment();

    Ware *rootWare = new Ware("ROOT", 1, 1, 1, 100);
    BinaryTree *binaryTree = new BinaryTree(rootWare);
    HashTable *hashtable = new HashTable();

    for(int i = 0; i < 10; i++){
        int Dist = rand() % 62;
        int seriennummer = rand() % 1000 + 1;
        int gewicht = rand() % 1000 + 1;
        int einkaufspreis = rand() % 1000 + 1;
        int verkaufspreis = rand() % 1000 + 1;
        Ware *ware = new Ware(random_string(Dist,5), seriennummer, gewicht, einkaufspreis, verkaufspreis);
        sortiment->addWare(ware);
        binaryTree->insert(ware);
        hashtable->insert(ware);
    }

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo vor sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Sortieren: ";

    sortiment->sort(1);

    /*
    int modus == 1: Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus
    int modus == 2: Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus
    int modus == 3: Sortierung alphabetisch nach Bezeichnung mihilfe des mergesort-Algorithmus
    int modus == 4: Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
    int modus == 5: Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
     */

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Wareninfo nach sortieren: " << std::endl;

    sortiment->printSortiment();

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << "Preorder nach Verkaufspreis" << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << binaryTree->printPreorder() << "\n";

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << "Postorder nach Verkaufspreis" << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << binaryTree->printPostorder() << "\n";

    //delete sortiment;

    delete binaryTree;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << "Doubly Linked List Test" << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;

    DoublyLinkedList *list = new DoublyLinkedList();

    DoublyLinkedList *list5 = new DoublyLinkedList();

    std::cout << "Liste 5:" << std::endl;
    list5->print();


    list->insertSorted(5);
    list->insertSorted(7);
    list->insertSorted(19);
    list->insertSorted(54);
    list->insertSorted(1);
    list->insertSorted(9);
    list->insertSorted(17);
    list->insertSorted(17);
    list->insertSorted(108);
    list->insertSorted(8);

    std::cout << "Liste 1:" << std::endl;
    list->print();

    DoublyLinkedList *list2 = new DoublyLinkedList();
    list2->insertSorted(2);
    list2->insertSorted(3);
    list2->insertSorted(4);

    std::cout << "Liste 2:" << std::endl;
    list2->print();

    list->splice(list2, 4);

    std::cout << "Liste 1:" << std::endl;
    list->print();

    list2->insertSorted(78);

    std::cout << "Liste 2:" << std::endl;
    list2->print();

    list->append(list2);
    std::cout << "Liste 1:" << std::endl;
    list->print();

    list->deleteItem(2);
    std::cout << "Liste 1:" << std::endl;
    list->print();

    delete list;
    delete list2;
    delete list5;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << "AVL Tree Test" << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;

    AvlNode* root = new AvlNode(10);
    root = root->insert(7);
    root = root->insert(23);
    root = root->insert(9);
    root = root->insert(2);

    /* -- Scenarion 1 - rightRotation -- */
    //root = root->insert(2);

    /* -- Scenarion 2 - leftRotation -- */
    // root = root->insert(17);
    // root = root->insert(19);

    /* -- Scenarion 3 - rightRotation, then leftRotation -- */
    // root = root->insert(17);
    // root = root->insert(16);

    /* -- Scenarion 4 - leftRotation, then rightRotattion -- */
    // root = root->insert(17);
    // root = root->insert(6);
    // root = root->insert(7);

    std::cout << root->printPreorder();
    std::cout << "Perfectly balanced! As all things should be!\n";

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;


    std::cout << "HashTable Test" << std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;

    hashtable->print();

    Ware *ware1 = new Ware("Testware", 0, 0, 0, 0);
    Ware *ware2 = new Ware("Testware1", 0, 0, 0, 0);

    hashtable->insert(ware1);
    hashtable->insert(ware2);

    hashtable->print();

    std::cout << "HashTable Search:" << std::endl;

    hashtable->search("Testware");
    hashtable->search("Testware3");

    std::cout << "HashTable Delete:" << std::endl;

    hashtable->deleteItem("Testware1");
    hashtable->deleteItem("Testware3");

    hashtable->print();


    return 0;

}
