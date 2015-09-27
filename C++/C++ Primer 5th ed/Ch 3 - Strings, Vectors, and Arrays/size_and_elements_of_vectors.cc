#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::vector; using std::string;

int main()
{
	cout << '\n' << endl;

	vector<int> v1;
	if (v1.empty())
		cout << "vector<int> v1; is empty so it has no elements." << endl;
	else {
		cout << "vector<int> v1 has " << v1.size() << " elements:" << endl;
		for (auto a : v1)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	vector<int> v2(10);
	if (v2.empty())
		cout << "vector<int> v2(10) is empty so it has no elements." << endl;
	else {
		cout << "vector<int> v2(10) has " << v2.size() << " elements:" << endl;
		for (auto a : v2)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	vector<int> v3(10, 42);
	if (v3.empty())
		cout << "vector<int> v3(10, 42) is empty so it has no elements." << endl;
	else {
		cout << "vector<int> v3(10, 42) has " << v3.size() << " elements:" << endl;
		for (auto a : v3)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	vector<int> v4{10};
	if (v4.empty())
		cout << "vector<int> v4{10} is empty so it has no elements." << endl;
	else {
		cout << "vector<int> v4{10} has " << v4.size() << " elements:" << endl;
		for (auto a : v4)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	vector<int> v5{10, 42};
	if (v5.empty())
		cout << "vector<int> v5{10, 42} is empty so it has no elements." << endl;
	else {
		cout << "vector<int> v5{10, 42} has " << v5.size() << " elements:" << endl;
		for (auto a : v5)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	vector<string> v6{10};
	if (v6.empty())
		cout << "vector<string> v6{10} is empty so it has no elements." << endl;
	else {
		cout << "vector<string> v6{10} has " << v6.size() << " elements:" << endl;
		for (auto a : v6)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	vector<string> v7{10, "hi"};
	if (v7.empty())
		cout << "vector<string> v7{10, ""hi""} is empty so it has no elements." << endl;
	else {
		cout << "vector<string> v7{10, ""hi""} has " << v7.size() << " elements:" << endl;
		for (auto a : v7)
			cout << ' ' << a; 
	}
	cout << '\n' << endl;


	return 0;
}