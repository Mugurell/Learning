#include <iostream>
#include <string>

int main()
{
	// const std::string s = "Keep Out!";
	// for (auto &c : s)
	// 	{/*...*/}
	// std::cout << c << std::endl;

	std::string prop {"Hello" "World" "!"}; 	
	std::cout << prop << std::endl;

	auto first = prop.cbegin();
	std::cout << first[0] << *(first+1) << std::endl;

	auto mid = (prop.cend() - prop.cbegin()) / 2;
	std::cout << "The middle is the " << mid << "th letter: " \
			  << first[mid] << std::endl;
 


	return 0;
}