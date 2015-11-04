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
 *   Functions that will build the following little 1-2-3 binary search tree:
 *           2
 *          / \
 *         1   3
 *
 *   Write the code in three different ways...
 *      a: by calling newNode() three times, and using three pointer variables
 *      b: by calling newNode() three times, and using only one pointer variable
 *      c: by calling insert() three times passing it the root pointer to
 *  build up the tree
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


#ifndef BUILD123_BUILDER_H
#define BUILD123_BUILDER_H


namespace Util {

typedef struct Node {
    int      value;
    Node*    left;
    Node*    right;
} Node;


Node* newTreeA();
Node* newTreeB();
Node* insert  (Node* root, const int value);

int size(Node* root);
void freeNodes(Node* root);


} // namespace Util



#endif //BUILD123_BUILDER_H
