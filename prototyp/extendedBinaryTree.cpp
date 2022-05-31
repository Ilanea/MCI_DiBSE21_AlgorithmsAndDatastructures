#include "extendedBinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(Ware *rootNodeKey) {
    BinaryTreeNode* root = new BinaryTreeNode(rootNodeKey);
    this->rootNode = root;
}

BinaryTreeNode* BinaryTree::insert(Ware *ware) {
    return this->rootNode->insert(ware);
}

BinaryTreeNode* BinaryTree::search(Ware *ware) {
    BinaryTreeNode* node = this->rootNode;
    while(ware != node->key && node != nullptr) {
        if(ware > node->key) {
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

// function to print a tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
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