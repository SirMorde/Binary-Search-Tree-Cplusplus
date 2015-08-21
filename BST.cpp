#include <iostream>
#include "BST.h"
#include "TreeNode.h"

typedef TreeNode* TreeNodePointer;

/***Constructor***/
BST::BST()
 :myRoot(0)
{}
//BST is simply a pointer to the root node

/***Destructor***/
BST::~BST()
{
}

//Returns true (1) if myRoot is equal to 0
bool BST::empty() const
{
    return myRoot == 0;
}

void BST::nodeInsert(const int & numberItem)
{
    TreeNodePointer locptr = myRoot;
    TreeNodePointer parent = 0; // pointer to parent of current node
    bool found = false; // Represents whether of not an item already in BST

   //While the item is not found or locptr isn't pointing to an empty BST or an empty left or right branch
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (numberItem < locptr->item)//descend left
         {
             locptr = locptr->Lchild;
         }
      else if (locptr->item < numberItem)//descend right
         {
             locptr = locptr->Rchild;
         }
      else//item found
         {
             found = true;
         }
   }

    //If the item wasn't found in the BST
   if (!found)
   {
      locptr = new TreeNode(numberItem); //Construct a node containing item
      if (parent == 0) // If tree is empty
      {
        myRoot = locptr;
      }

      else if (numberItem < parent->item)
      {
        parent->Lchild = locptr; //Insert to Lchild of parent
      }

      else
      {
        parent->Rchild = locptr;//Insert to Rchild of parent
      }

   }
   else
      std::cout <<"***ERROR*** ~ " << numberItem << " was already in the BST\n";
}

void BST::nodeDelete(const int & numberItem)
{
    TreeNodePointer x = myRoot;//Number to be deleted
    TreeNodePointer parent = 0; //Pointer to parent node of number to be deleted
    bool found = false;

    //Descending down the BST to find number to be deleted
    while (!found && x != 0)
   {
      if (numberItem < x->item)
      {
         parent = x;
         x = x->Lchild;
      }

      else if (x->item < numberItem)
      {
         parent = x;
         x = x->Rchild;
      }

      else
         found = true;//Item was found in the BST
   }

//If the number was not found in the BST, there's nothing to delete
    if (!found)
   {
      std::cout << "***ERROR*** ~ " << numberItem << " was not in the BST\n";
      return;
   }

//If the number was found, delete it
// Scenario where node has 2 children
if (x->Lchild != 0 && x->Rchild != 0)
   {
      // Find x's inorder successor and its parent
      TreeNodePointer xSucc = x->Rchild;
      parent = x;
      while (xSucc->Lchild != 0)       // descend left
      {
         parent = xSucc;
         xSucc = xSucc->Lchild;
      }

// Move contents of xSucc to x and change x to point to successor, which will be removed.
     x->item = xSucc->item;
     x = xSucc;
   } //End if node has 2 children

//Now proceed with scenario where node has 0 or 1 child
      TreeNodePointer subtree = x->Lchild;//Pointer to a subtree of x
   if (subtree == 0)
      {
          subtree = x->Rchild;
      }

   if (parent == 0)//Root being removed
      {
          myRoot = subtree;
      }

   else if (parent->Lchild == x)//Left child of parent
      {
          parent->Lchild = subtree;
      }

   else//Right child of parent
      {
          parent->Rchild = subtree;
      }

   delete x;
}

bool BST::nodeSearch(const int & numberItem) const
{
    TreeNodePointer locptr = myRoot;
    bool found = false;

    //While the itemNumber is not found and locptr isn't pointing at an empty BST or an empty left or right branch
   while (!found && locptr != 0)
   {
      if (numberItem < locptr->item)
        locptr = locptr->Lchild;
        // Go down left branch if the number we're searching for is less than the current node's data
      else if (locptr->item < numberItem)
        locptr = locptr->Rchild;
        // Go down right branch if the number we're searching for is greater than the current node's data
      else                           // numberItem found
        found = true;
   }
   return found;
}


void BST::preorder(std::ostream & out) const
{
    preorderAux(out, myRoot);
    std::cout << std::endl;
}

void BST::preorderAux(std::ostream & out, TreeNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
      out << subtreeRoot->item << "  ";      // V operation
      inorderAux(out, subtreeRoot->Lchild); // L operation
      inorderAux(out, subtreeRoot->Rchild);// R operation
    }
}


void BST::inorder(std::ostream & out) const
{
    inorderAux(out, myRoot);
    std::cout << std::endl;
}

void BST::inorderAux(std::ostream & out, TreeNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
      inorderAux(out, subtreeRoot->Lchild);   // L operation
      out << subtreeRoot->item << "  ";      // V operation
      inorderAux(out, subtreeRoot->Rchild); // R operation
    }
}


void BST::postorder(std::ostream & out) const
{
    postorderAux(out, myRoot);
    std::cout << std::endl;
}

void BST::postorderAux(std::ostream & out, TreeNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
      inorderAux(out, subtreeRoot->Lchild); // L operation
      inorderAux(out, subtreeRoot->Rchild);// R operation
      out << subtreeRoot->item << "  ";   // V operation
    }
}
