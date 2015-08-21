#include <iostream>
#include "TreeNode.h"

#ifndef BST_H
#define BST_H

typedef TreeNode* TreeNodePointer;

class BST
{
    public:
    BST();//Constructor
    virtual ~BST();//Destructor

    /*** Functions ***/
    bool empty() const; //Checks to see whether or not BST is empty
    void nodeInsert(const int & numberItem); //Insert number into BST
    void nodeDelete(const int & numberItem); //Delete number from BST
    bool nodeSearch(const int & numberItem) const; //Search BST for a number
    void preorder(std::ostream & out) const; //Displays BST in preorder traversal
    void inorder(std::ostream & out) const; //Displays BST in inorder traversal
    void postorder(std::ostream & out) const; //Displays BST in postorder traversal

    private:
    /*** Private Functions ***/
    void preorderAux(std::ostream & out, TreeNodePointer subtreeRoot) const; //Used for preorder traversal
    void inorderAux(std::ostream & out, TreeNodePointer subtreeRoot) const; //Used for inorder traversal
    void postorderAux(std::ostream & out, TreeNodePointer subtreeRoot) const; //Used for postorder traversal

    /*** Private Data Member ***/
    TreeNodePointer myRoot;
};

#endif // BST_H
