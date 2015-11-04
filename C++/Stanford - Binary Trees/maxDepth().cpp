// Exemplification of a basic function to count the levels of a binary tree.
// MAx Depth - the number of nodes along the longest path from the root node
// down to the farthest leaf node. The maxDepth of the empty tree is 0.


#include <iostream>


struct Node
{
    int value;
    Node* left;
    Node* right;

    // use a simple ctor just to make creating nodes easier
    Node(int val = 0) : value{val}, left{nullptr}, right{nullptr} { }
};


int maxDepth(Node* root);


int main()
{
    Node  root, a, b, a2, a3, a4;

    // this can be commented to test the correctness of  maxDepth()
    a3.left = &a4;      // 5th level - left branch
    a2.left = &a3;      // 4th level - left branch
    a.left = &a2;       // 3rd level - left branch

    root.left = &a;     // 2nd level - left branch
    root.right = &b;    // 2nd level - right branch

    // And of course the root,  will be the 1st branch/leaf

    std::cout << "\nThis binary tree has " << maxDepth(&root) << " levels\n";
    return 0;
}


int maxDepth(Node* root)
{
    if (nullptr == root)
    {
        return 0;
    }
    else
    {
        // get the depth of each subtree
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);

        // return the biggest debth + 1 for the root
        return (l_depth > r_depth ? l_depth : r_depth) + 1;
    }
}
