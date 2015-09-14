/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          miercuri 8 iulie 2015, 14:27:53 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 13.28: Given the following classes, implement a default 
**  constructor and the necessary copy-control members.
**          (a)
**      class TreeNode {
**      private:
**          std::string value;
**          int count;
**          TreeNode *left;
**          TreeNode *right;
**      };
** 
**          (b)
**      class BinStrTree {
**      private:
**          TreeNode *root;
**      };
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  The fact that the count member in TreeNode is a regular int, and not a
**  pointer indicates that this class should have valuelike behaviour and not
**  pointerlike behaviour.
**  The BinStrTree will have pointerlike behaviour.
**
*******************************************************************************
******************************************************************************/


#include <string>
#include <new>
#include <cstddef>      // needed for the count in BinStrTree


class TreeNode {
public:
    // default constructor
    TreeNode(const std::string &s = "", const int &i = 0);

    // copy constructor
    TreeNode(const TreeNode& toBeCopied);

    // copy-assignment operator
    TreeNode& operator=(const TreeNode &toBeCopied);
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};


inline TreeNode::TreeNode(const std::string &s, const int &i;)
        : value(s),     // initialize value with a default empty string
        count(i),       // initialize count with a default number = 0
        left(nullptr),       // assign nullptr to our pointer members
        right(nullptr) { }   // they are to get pointees later in the program

inline TreeNode::TreeNode(const TreeNode &toBeCopied)
        : value(toBeCopied.value),  // copy the value from the received object
        count(toBeCopied.count),    // copy the count from the received object
        // create new freestore objects initialized with the copy of the
        // pointees of the pointer objects of the received object
        // and assign them to our pointers.
        left(new TreeNode(*toBeCopied.left)),   
        right(new TreeNode(*toBeCopied.right)) {}

TreeNode&
inline TreeNode::operator=(const TreeNode &toBeCopied) {
    value = toBeCopied.value;
    count = toBeCopied.count;
    // check if the pointer members were allready having a valid pointee
    // (not pointing too 0) and if so make sure to call delete
    if (left) delete left;
    if (right) delete right;
    left(new TreeNode(*toBeCopied.left));
    right(new TreeNode(*toBeCopied.right));

    return *this;
}

inline TreeNode::~TreeNode() {
    delete left;
    delete right;
}







// BinStrTree will have pointerlike behaviour.
class BinStrTree {
    // default constructor will initialize the root member with a newly
    // constructed TreeNode object allocated on the heap
    BinStrTree(const std::string &a = "", const int &c = 0);

    // copy constructor
    BinStrTree(const BinStrTree &toBeCopied);

    // copy-assignment operator
    BinStrTree& operator=(const BinStrTree &toBeCopied);

    // destructor needed because root will point to heap memory
    ~BinStrTree();
private:
    TreeNode *root;
    std::size_t *count;
};


inline BinStrTree::BinStrTree(const std::string &s, const int &i)
        : root(new TreeNode(s, i)), count(new std::size_t(1)) {}

// remember to increment the reference count for out pointer
inline BinStrTree::BinStrTree(const BinStrTree &toBeCopied)
        : root(toBeCopied.root), count(toBeCopied.count) { ++*count; }

inline BinStrTree&
BinStrTree::operator=(const BinStrTree &toBeCopied) {
    // first increment the use count for the received object
    // as to handle properly the case of self-assignment
    ++*toBeCopied.count;

    // remember to deallocate the memory if there are no other BinStrTree
    // objects using it
    if (--*count == 0) {
        delete root;
        delete count;
    }

    root = toBeCopied.root;
    count = toBeCopied.count;   // it was incremented above

    return *this;
}

// free the memory if there aren't anymore BinStrTree objects using it
inline BinStrTree::~BinStrTree() {
    if (--*count == 0) {
        delete root;
        delete count;
    }
}