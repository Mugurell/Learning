#include <iostream>
#include <string>
#include <vector>	

void clean_cin(void);

int main()
{
	std::cout << "\nPlease enter some numbers separated by spaces:" << std::endl;

	std::vector<int> number;
	int nr;
	while (std::cin >> nr)
		number.push_back(nr);
	
	std::cin.clear();	

	std::cout << "\nNow say some words if you may.." << std::endl;

	std::vector<std::string> prop;
	std::string word;
	while (std::cin >> word) {
		if (word == "stop")
			break;
		else
			prop.push_back(word);
	}

	/* The size member returns in this case a vector<int> size_type number*/
	std::cout << "\nCool!\nSo you said " << number.size() << " numbers:" \
			  << std::endl;
	for (auto x : number)
		std::cout << '\t' << x << std::endl;
	/* The size member returns in this case a vector<string> size_type number */
	std::cout << "\nAnd "<< prop.size() << " words. \n\t";
	for (auto s : prop)
		std::cout << s << ' ';
	std::cout << std::endl;

	return 0;
}

// void clean_cin(void)
// {
// 	std::string STRLEN;
// 	std::cin.getline(temp, STRLEN); 

// 	if (std::cin.fail()) { 
// 		std::cin.clear(); 
// 		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
// 	}
// }