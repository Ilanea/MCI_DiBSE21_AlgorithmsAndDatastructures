#include "extendedBinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(Ware *rootNodeKey) {
    BinaryTreeNode* root = new BinaryTreeNode(rootNodeKey);
    this->rootNode = root;
}

BinaryTreeNode* BinaryTree::insert(Ware *ware) {
    return this->rootNode->insert(ware);
}

BinaryTreeNode* BinaryTree::search(int verkaufspreis) {
    BinaryTreeNode* node = this->rootNode;
    while(verkaufspreis != node->key->getVerkaufspreis() && node != nullptr) {
        if(verkaufspreis > node->key->getVerkaufspreis()) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return node;
}

BinaryTreeNode* BinaryTree::deleteItem(Ware *ware) {
    return this->rootNode->deleteItem(ware);
}

BinaryTreeNode* BinaryTree::findMin(BinaryTreeNode* node) {
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinaryTreeNode* BinaryTree::findMax(BinaryTreeNode* node) {
    while(node->right != nullptr) {
        node = node->right;
    }
    return node;
}

/*
Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree)
*/
std::string BinaryTree::printPreorder(BinaryTreeNode* node) {
    std::stringstream output;
    output << node->key->getVerkaufspreis() << std::endl;

    if(node->left != nullptr) {
        output << this->printPreorder(node->left);
    }
    if(node->right != nullptr) {
        output << this->printPreorder(node->right);
    }
    return output.str();
}



std::string BinaryTree::printPreorder() {
    return this->printPreorder(this->rootNode);
}

/*
Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.
*/
std::string BinaryTree::printPostorder(BinaryTreeNode* node){
    std::stringstream output;

    if(node->left != nullptr) {
        output << this->printPostorder(node->left);
    }
    if(node->right != nullptr) {
        output << this->printPostorder(node->right);
    }

    output << node->key->getVerkaufspreis() << std::endl;

    return output.str();
}

std::string BinaryTree::printPostorder() {
    return this->printPostorder(this->rootNode);
}