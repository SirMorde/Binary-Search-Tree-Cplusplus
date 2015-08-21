#include <iostream>
#include "BST.h"
#include "TreeNode.h"

using namespace std;

int main()
{
    BST tree;
    cout << "A BST has been created! Checking to see if the BST is empty..." << endl;
    if(tree.empty() == true)
    {
        cout << "The BST is empty!" << endl << endl;
    }
    else
    {
        cout << "The BST is not empty!" << endl << endl;
    }

    //***Testing Insertion***
    int n;
    cout << "Enter a number to be inserted into to the BST!" << endl;
    cin >> n;

    cout << "n = " << n << "" << endl;

    cout << "Inserting " << n << " into the BST! :D" << endl;
    tree.nodeInsert(n);

    cout << "Searching to see if " << n << " was inserted..." << endl;
    if(tree.nodeSearch(n) == true)
    {
        cout << n << " was in the BST!" << endl;
    }
    else
    {
        cout << n << " was not in the BST :(" << endl;
    }

    cout << "Attempting to insert " << n << " again..." << endl;
    tree.nodeInsert(n);
    cout << endl;


    //***Testing Deletion***
    cout << "Attempting to Delete " << n << "..." << endl;
    tree.nodeDelete(n);

    cout << "Searching the BST to see if " << n << " was deleted..." << endl;
      if(tree.nodeSearch(n) == true)
    {
        cout << n << " was in the BST!" << endl;
    }
    else
    {
        cout << n << " was not in the BST :(" << endl;
    }

    cout << "Attempting to Delete " << n << " again..." << endl;
    tree.nodeDelete(n);
    cout << endl << endl;

    cout << "Let's add a bunch of numbers into the BST!" << endl;
    //***Testing preorder, inorder, and postorder output***
    BST testTree;
    int number;

    while(number != -420)
    {
        cout << "(Enter -420 to stop inserting) Insert a number: ";
        cin >> number;
        if(number != -420)
        {
          testTree.nodeInsert(number);
        }
    }

    cout << endl << "Preorder Traversal of BST: ";
    testTree.preorder(cout);
    cout << "Inorder Traversal of BST: ";
    testTree.inorder(cout);
    cout << "Postorder Traversal of BST: ";
    testTree.postorder(cout);

    cout << endl << "I hope you had fun using the BST program!" << endl;
    cout << "~Created by Brandon Ma" << endl;

    return 0;
}
