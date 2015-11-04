/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          02 Oct 2015, 17:13:19:520
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *   I. Write code that builds the following little 1-2-3 binary search tree:
 *           2
 *          / \
 *         1   3
 *   Write the code in three different ways...
 *      a: by calling newNode() three times, and using three pointer variables
 *      b: by calling newNode() three times, and using only one pointer variable
 *      c: by calling insert() three times passing it the root pointer to
 *  build up the tree
 *
 *  II. Given a binary tree, count the number of nodes in the tree.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  Will be using a binary search tree <=> the nodes are arranged in order
 *
********************************************************************************
*******************************************************************************/



#include <array>
#include <iostream>
#include <memory>

#include "Util.h"


int main()
{
    using namespace Util;

    std::cout << "\nSo, let's build three simple binary trees..\n\n";
    Node* a = newTreeA();
    Node* b = newTreeB();
    Node* c = new Node;
    c = nullptr;
    c = insert(c, 2);
    c = insert(c, 1);
    c = insert(c, 3);
    c = insert(c, 321);
    c = insert(c, 0);

    std::cout << "\nAnd now that we've done that, let's see if we indeed have\n"
        << "a tree with 1 root and 2 branches..\n";
    std::array<Node*, 3> trees{a, b, c};
    for (auto i : {1,2,3})
    {
        std::cout << "\n\tTree " << i << " has " << size(trees[i-1])
            << " nodes";
        freeNodes(trees[i-1]);
    }

    std::cout << "\n\nPretty cool, huh?\n\n";

    return 0;
}