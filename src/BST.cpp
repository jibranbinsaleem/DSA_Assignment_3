#include "BST.h"
#include "BinaryTree.h"
template <class Comparable>
BST<Comparable>:: BST() : BinaryTree<Comparable>()
{
    //constructor
}

template <class Comparable>
BST<Comparable>:: BST(const BST& t) : BinaryTree<Comparable>()
{
    //constructor
}

template <class Comparable>
BST<Comparable>:: BST(BinaryNode<Comparable> *root) : BinaryTree<Comparable>(this->tree_root)
{
    //constructor
}

template <class Comparable>
BST<Comparable>::~BST()
{
    BinaryTree<Comparable>::make_empty();
}

template <class Comparable>
void BST<Comparable>:: insert(const Comparable data, BinaryNode<Comparable>*& t)
{
    if (t==NULL)
        t= (this->create_node(data));
    else if (data<t->element)
        insert(data,t->left);
    else if (t->element<data)
        insert(data,t->right);
    else;
}

template <class Comparable>
void BST<Comparable>:: insert(const Comparable data)
{
    insert(data,this->tree_root);
}

template <class Comparable>
void BST<Comparable>::remove(const Comparable data, BinaryNode<Comparable>*& t)
{
    if (t==NULL)
        return;
    if (data<t->element)
        remove(data,t->left);
    else if (t->element < data)
        remove (data, t->right);
    else if (t->left != NULL && t->right != NULL)
    {
        t->element = findMin(t->right) ->element;
        remove(t->element,t->right);
    }
    else
    {
        BinaryNode<Comparable>* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}

template <class Comparable>
void BST<Comparable>:: remove(const Comparable data)
{
    remove(data,this->tree_root);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>:: findMin(BinaryNode<Comparable> *t)
{
    if(t==NULL)
        return NULL;
    if(t->element==NULL)
        return t;
    return findMin(t->left);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>:: findMin()
{
    findMin(this->tree_root);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>:: findMax(BinaryNode<Comparable> *t)
{
    if(t==NULL)
        return NULL;
    if(t->element==NULL)
        return t;
    return findMax(t->right);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>:: findMax()
{
    findMax(this->tree_root);
}

template <class Comparable>
bool BST<Comparable>:: search(const Comparable data)  // Function for Checking wheather the Element is present or not
{
        contains(data, this->tree_root);
}

template <class Comparable>
bool BST<Comparable>:: contains(const Comparable x, BinaryNode<Comparable>* tr) 
    if( tr == nullptr )
        return false;
    else if( x < tr->element )
        return contains( x, tr->left );
    else if( t->element < x )
        return contains( x, tr->right );
    else
        return true;
}
