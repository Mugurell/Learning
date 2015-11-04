/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          02-Oct-15, 05:18 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementations for the functions in Builder.h
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  --- 
 *
********************************************************************************
*******************************************************************************/


#include <memory>

#include "Util.h"

using namespace Util;


// Will create 3 individual nodes and them link them together
Node*Util::newTreeA()
{
    Node* b = new Node;
    b->value = 1;   b->left = b->right = nullptr;
    Node* c = new Node;
    c->value = 3;   c->left = c->right = nullptr;

    Node* a = new Node;
    a->value = 2;   a->left = b;    a->right = c;

    return a;
}


// Will create 3 nodes, initialize them all through the root
Node*Util::newTreeB()
{
    Node* b = new Node;
    Node* c = new Node;

    Node* a = new Node;
    a->value = 2;   a->left = b;    a->right = c;
    a->left->value = 1;
    a->left->left = a->left->right = nullptr;
    a->right->value = 3;
    a->right->left = a->right->right = nullptr;

    return a;
}


// To be called 3 with the appropriate values
Node*Util::insert(Node* root, const int value)
{
    if (root == nullptr)
    {
        Node *a = new Node;
        a->value = value;
        a->left = nullptr;
        a->right = nullptr;
        root = a;
    }

    else if (root->value == value)
    {
        // Nothing to do for now..
    }

    else if (root->value < value)
    {
        root->right = insert(root->right, value);
    }

    else
    {
        root->left = insert(root->left, value);
    }

    return root;
}


// Will use recursion to fall through all the branches
int Util::size(Node* root)
{
    if (root == nullptr)
        return 0;
    else
        // count while falling through all the branches
        // add 1 for the root
        return size(root->left) + 1 + size(root->right);
}


void Util::freeNodes(Node *root)
{
    while (root != nullptr)
    {
        freeNodes(root->left);
        freeNodes(root->right);
        root = nullptr;
        delete root;
    }
}
