#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

class TreeNode
{

friend class BST;

public:
    TreeNode(); //Default Constructor
    TreeNode(int i,  TreeNode *L,  TreeNode *R); // Explicit Value Constructor
    int getItem() const; //Accessor function

private:
    int item;
    TreeNode *Lchild;
    TreeNode *Rchild;
};

/***Default value constructor definition***/
inline TreeNode::TreeNode()
{
    Lchild = Rchild = NULL;
    //By default, the left and right child branches are empty
}

/***Explicit value constructor definition***/
//First parameter is the item. If Lchild and Rchild are not passed, they are initialized to 0
inline TreeNode::TreeNode(int i,  TreeNode *L = 0,  TreeNode *R = 0)
:item(i), Lchild(L), Rchild(R)
{}

inline int TreeNode::getItem() const
{return item;}

#endif // TREENODE_H_INCLUDED
