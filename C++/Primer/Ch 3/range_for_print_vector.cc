#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main()
{
	vector<int> vi {1,2,3,4,5,6,7,8,9};

	for(auto &i : vi)
		i *= i;

	/*
	** v1.size() will return the number of elements that the vector
	** v1 contains. 
	** The result will be of type ** vector<int>::size_type **.
	*/
	cout << "\nNow I'm gonna print a vector with " << vi.size() \
		 << " elements." << endl;

	for(auto i : vi)
		cout << "\n\t" << i;

	cout << '\n' << endl; 
}