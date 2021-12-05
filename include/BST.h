#ifndef BST_H
#define BST_H

#include "BinaryTree.h"

template <class Comparable>
class BST : public BinaryTree<Comparable>
{
    public:
        BST();
        BST(BinaryNode<Comparable> *root);
        BST(const BST& t);
        ~BST();
        //bool search(const Comparable data);
        BinaryNode<Comparable>* findMin() ;
        BinaryNode<Comparable>* findMax() ;
        virtual void insert(const Comparable data);
        void remove(const Comparable data);
    private:
        void insert(const Comparable data, BinaryNode<Comparable>*& root) ;
        void remove(const Comparable data, BinaryNode<Comparable>*& root) ;
        BinaryNode<Comparable>* findMin(BinaryNode<Comparable> *root) ;
        BinaryNode<Comparable>* findMax(BinaryNode<Comparable> *root) ;
};

#endif // BST_H
