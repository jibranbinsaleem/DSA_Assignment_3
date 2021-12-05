#include "BinaryTree.h"
#include<string>
#include<stack>
#include "ExpressionTree.h"

using namespace std;

ExpressionTree::ExpressionTree()
{

    tree_root = NULL;
}

ExpressionTree::ExpressionTree(ExpTreeNodePtr data)
{
    if (data == NULL)
        tree_root= NULL;
    else
        tree_root=copyTree(data);
}
ExpressionTree::~ExpressionTree()
{
    BinaryTree::make_empty();
}
void ExpressionTree::create_expression_tree(string expression)
{

    char s;
    ExpTreeNodePtr new1, p1, p2;
    stack<ExpTreeNodePtr> top;

    s = expression[0];

    for(int i = 1; s != 0; i++){
        if (!is_operator(s))
        {

            new1 = new BinaryNode<char>;
            new1->element = s;
            new1->left = NULL;
            new1->right = NULL;
//            cout<<new1->element;
            top.push(new1);
        }
        else
        {

            p1 = top.top();
            top.pop();
            p2 = top.top();
            top.pop();
            new1 = new BinaryNode<char>;
            new1->element = s;
            new1->left = p2;
            new1->right = p1;
//            cout<<new1->left;
            top.push(new1);

        }
        s = expression[i];
    }
    tree_root = new1;

}

bool ExpressionTree::is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch== '/')
        return true;
    else
        return false;
}

ExpressionTree ExpressionTree::left()
{
    ExpressionTree subtree(tree_root->left);
    return subtree;
}

ExpressionTree ExpressionTree::right()
{
    ExpressionTree subtree(tree_root->right);
    return subtree;
}
