//
// Created by msyu on 06.06.2022.
//

#ifndef PROTOTYP_EXTENDEDAVLTREE_H
#define PROTOTYP_EXTENDEDAVLTREE_H

#include <string>

class AvlNode {

public:
    int key;
    AvlNode* left;
    AvlNode* right;
    int height;

    AvlNode(int key);

    int max(int n1, int n2);
    int min(int n1, int n2);
    int getHeightDifference();
    int getHeight();

    AvlNode* insert(int key);
    AvlNode* leftRotation();
    AvlNode* rightRotation();

    std::string printPreorder();

    AvlNode* deleteItem(int key);

};


#endif //PROTOTYP_EXTENDEDAVLTREE_H
