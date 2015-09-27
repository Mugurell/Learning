#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main()
{

	vector<int> cluster (11, 0);
	unsigned grade;
	while (cin >> grade)
		++cluster[grade/10];

	cout << "Which they were repartisez as follows:" << endl;
	for (auto x : cluster)
		cout << ' ' << x;

	cout << '\n' << endl;

	return 0;

}