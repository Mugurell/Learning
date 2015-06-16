#include <iostream>
#include <vector>
#include <vector>

int main()
{
	std::vector<std::string> const grades {"F", "D", "C", "B", "A", "A++"};
	unsigned nr (0);
	std::string lettergrade;


	std::cout << "\nEnter your numeric note to be converted into a letter " \
			  << "grade: ";

	std::cin >> nr;

	if (nr > 100) {
		std::cout << "\nYou're too smart for this century!\n" << std::endl;
		return 0;
	}

	std::cout << "\nSo in the American system you would have got an ";

	if (nr < 60)
		lettergrade = grades[0];
	else {
		lettergrade = grades[(nr - 50)/10];
		if (nr %10 > 7)
			lettergrade += '+';
		else if (nr != 100 && nr %10 < 3)
			lettergrade += '-';
	}				


	std::cout << lettergrade << ".\n" << std::endl;

	return 0;
}