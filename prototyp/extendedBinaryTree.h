#include "extendedBinaryTreeNode.h"
#include "Ware.h"
#include <string>
#include <sstream>

#pragma once


class BinaryTree {
    public:
        BinaryTreeNode *rootNode;

        BinaryTree(Ware *rootNodeKey);

        BinaryTreeNode* search(int verkaufspreis);
        BinaryTreeNode* insert(Ware *ware);
        BinaryTreeNode* deleteItem(Ware *ware);
        BinaryTreeNode* findMin(BinaryTreeNode* node);
        BinaryTreeNode* findMax(BinaryTreeNode* node);
        std::string printPreorder(BinaryTreeNode* node);
        std::string printPreorder();
        std::string printPostorder(BinaryTreeNode* node);
        std::string printPostorder();

};




// std::string printPreorder(BinaryTreeNode* node);
// /*  --  Your TODO   --  */
// std::string printPostorder(BinaryTreeNode* node);
// std::string printInorder(BinaryTreeNode* node);