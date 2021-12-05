#include "BinaryTree.h"
template <class Comparable>

//constructors

BinaryTree<Comparable>::BinaryTree()
{
    tree_root= NULL;
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree( BinaryNode<Comparable>* root)
{
    if (root == NULL)
        tree_root= NULL;
    else
        tree_root=copyTree(root);
}

template <class Comparable>
BinaryTree<Comparable>::BinaryTree(const BinaryTree& t )
{
    tree_root=copyTree(t.tree_root);
}

template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::copyTree( BinaryNode<Comparable>* root){
    if (root == NULL){
        return root;
    }
    BinaryNode<Comparable> *NewTree;
    NewTree = new BinaryNode<Comparable>;
    NewTree->element = root->element;
    NewTree->left = copyTree(root->left);
    NewTree->right = copyTree(root->right);
    return NewTree;
}
//____________________________________________
//Destructor

template <class Comparable>
BinaryTree<Comparable>::~BinaryTree()
{
     make_empty();
}

template <class Comparable>
void BinaryTree<Comparable>:: make_empty()
{
    deleteTree(tree_root);
}
template <class Comparable>
void BinaryTree<Comparable>::deleteTree(BinaryNode<Comparable>* root)
{
    if (root==NULL)
        return;
    
    //deleting the subtrees
    deleteTree(root->left);
    deleteTree(root->right);
    //deleting the root
    cout << "\nDeleting node : " << root->element;
    delete root;
}
//____________________________________________
//insert

template <class Comparable>
void BinaryTree<Comparable>:: insert(const Comparable x)
{
    // If tree is empty we creat a new node at root and insert in that node
    if (tree_root == NULL) {
        tree_root = create_node(x);
        return ;
    }

    //else we traverse the tree till we find an empty place to creata new node
    queue<BinaryNode<Comparable>*> q;
    q.push(tree_root);

    while (!q.empty()) {
        BinaryNode<Comparable>* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = create_node(x);
            return ;
        }
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = create_node(x);
            return ;
        }
    }
}

template <class Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::create_node(Comparable x)
{
    BinaryNode<Comparable> *NewNode;
    NewNode = new BinaryNode<Comparable>;
    NewNode->element=x;
    NewNode->left=node->right=NULL;
    return NewNode;
}
//____________________________________________
//traversing functions

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder()
{
    traverse_inOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder()
{
    traverse_preOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder()
{
    traverse_postOrder(tree_root);
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_inOrder(BinaryNode<Comparable>* root)
{
        if(root!=NULL)
        {
            //left sub-tree
            traverse_inOrder(root->left);
            //print the node
            cout<<root->element<<" ";
            //right sub-tree next
            traverse_inOrder(root->right);
        }

}

template <class Comparable>
void BinaryTree<Comparable>::traverse_preOrder(BinaryNode<Comparable>* root)
{
        if (root!=NULL)
        {
            //print the node
            cout<<root->element<<" ";
            //left sub-tree
            traverse_preOrder(root->left);
            //right sub-tree next
            traverse_preOrder(root->right);
        }
}

template <class Comparable>
void BinaryTree<Comparable>::traverse_postOrder(BinaryNode<Comparable>* root)
{
          if (root!=NULL)
          {
                //left sub-tree
                traverse_postOrder(root->left);
                //right sub-tree
                traverse_postOrder(root->right);
                //print the node
                cout<<root->element<<" ";
          }
}

//____________________________________________
//Access functions
template <class Comparable>
Comparable BinaryTree<Comparable>::root()
{
    return tree_root->element;
}
template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>:: left()
{
    BinaryTree<Comparable> subtree(tree_root->left);
    return subtree;
}

template <class Comparable>
BinaryTree<Comparable> BinaryTree<Comparable>:: right()
{
    BinaryTree<Comparable> subtree(tree_root->right);
    return subtree;
}
//____________________________________________
template <class Comparable>
bool BinaryTree<Comparable>:: empty() const
{
    if(tree_root==NULL)
        return true;
    else
        return false;
}
