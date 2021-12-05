#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <BinaryTree.h>
#include<string>
#include<stack>

using namespace std;

typedef BinaryNode<char>* ExpTreeNodePtr;

class ExpressionTree : public BinaryTree<char>
{
    public:
    	//constructor
        ExpressionTree();
		//copy constructor
        ExpressionTree(ExpTreeNodePtr data);
        //Destructor
		virtual ~ExpressionTree();
        //create expression tree
		void create_expression_tree(string expression);
		//left sub tree
		ExpressionTree left();
		//right sub tree
		ExpressionTree right();

    private:
    	bool is_operator(char ch)
};

#endif // EXPRESSIONTREE_H
