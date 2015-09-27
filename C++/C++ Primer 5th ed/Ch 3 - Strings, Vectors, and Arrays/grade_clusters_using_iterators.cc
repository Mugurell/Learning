#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::vector;

int main()
{
	std::cout << "Enter the grades" << std::endl;

	std::vector<int> grades (11, 0);
	unsigned grade;

	auto beg = grades.begin();
	while(std::cin >> grade) {
		++*(beg + grade/10);
	}

	std::cout << "They were repartized as follows:\n\t";
	while (beg != grades.end())
		std::cout << ' ' << *beg++;

	std::cout << '\n' << std::endl;

	return 0;
}