#include "Ware.h"
#include "Sortiment.h"

class BinaryTreeNode {
    public:
        Ware *key;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        
        BinaryTreeNode(Ware *ware);
       
        BinaryTreeNode* insert(Ware *ware);
        BinaryTreeNode* deleteItem(Ware *ware);
};