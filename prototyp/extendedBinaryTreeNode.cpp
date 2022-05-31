#include <iostream>
#include "extendedBinaryTreeNode.h"


BinaryTreeNode::BinaryTreeNode(Ware *ware) {
    this->key = ware;
    this->left = nullptr;
    this->right = nullptr;
}

BinaryTreeNode* BinaryTreeNode::insert(Ware *ware) {

    //std::cout << "Key: " << ware->getVerkaufspreis() << " This Key: " << this->key->getVerkaufspreis() << std::endl;

    if(ware->getVerkaufspreis() > this->key->getVerkaufspreis()) {
        if(this->right == nullptr) {
            BinaryTreeNode* temp = new BinaryTreeNode(ware);
            this->right = temp;
            return this->right;
        }
        this->right->insert(ware);
    } else {
        if(this->left == nullptr) {
            BinaryTreeNode* temp = new BinaryTreeNode(ware);
            this->left = temp;
            return this->left;
        }
        this->left->insert(ware);
    }
    return this;
}

BinaryTreeNode* BinaryTreeNode::deleteItem(Ware *ware) {
    BinaryTreeNode* node = this;

    if(node == nullptr) {
        return this;
    } else if(key->getVerkaufspreis() < node->key->getVerkaufspreis()) {
        node->left = node->left->deleteItem(ware);
    } else if(key->getVerkaufspreis() > node->key->getVerkaufspreis()) {
        node->right = node->right->deleteItem(ware);
    } else {
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if(node->left == nullptr) { // only children in right subtree
            BinaryTreeNode* temp = node;
            node = node->right;
            delete temp;
        } else if(this->right == nullptr) { // only children in left subtree
            BinaryTreeNode* temp = node;
            node = node->left;
            delete temp;
        } else { // we have to keep the BST structure, here, we look for the minimum in the right subtree (see lecture)
            BinaryTreeNode* temp = node->right;
            while(temp->left != nullptr) {
                temp = temp->left;
            } 
            node->key = temp->key;
            node->right = node->right->deleteItem(temp->key);
        }
    }
    return node;
}