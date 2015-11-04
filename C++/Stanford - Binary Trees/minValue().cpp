// Given a non-empty binary search tree (an ordered binary tree), return the
// minimum data value found in that tree. Note that it is not necessary to
// search the entire tree. A maxValue() function is structurally very similar
// to this function. 


#include <iostream>


struct Node{
	int value;
	Node* left;
	Node* right ;

	// simple constructor to make creating nodes easier
	Node(const int val = 0, Node* L = nullptr, Node* r = nullptr) 
		: value{val}, left{L}, right{r} { }
};


int minValue(Node* root);
int maxValue(Node* root);


int main()
{
	// will create some new brances with a few different values
	Node d{32};
	Node c{3543};
	Node b{10, &c, &d};
	Node a{342, &b};
	Node root{3, &a};
	
	std::cout << "\nIn our simple binary tree,"
		<< "\n\tminValue is " << minValue(&root);
		//<< "\n\tmaxValue is " << maxValue(root);

	return 0;
}


int minValue(Node* root)
{
	if (nullptr != root)
	{
		int min_left = minValue(root->left);
		int min_right = minValue(root->right);

		if (min_left < min_right)
			return (min_left < root->value ? min_left : root->value);
		else
			return (min_right < root->value ? min_right : root->value);
	}
}