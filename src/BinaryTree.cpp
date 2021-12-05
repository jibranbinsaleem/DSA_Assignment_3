#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    //ctor
}

BinaryTree::~BinaryTree()
{
    //dtor
}
void traverse_inOrder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
void traverse_preOrder(Node* temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << ' ';
    preOrder(temp->left);
    preOrder(temp->right);
}
void traverse_postOrder(Node* temp)
{
    if (temp == NULL)
        return;
 
    postOrder(temp->left);
    postOrder(temp->right);
    cout << temp->data << ' ';
}
