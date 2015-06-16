#include <iostream>
#include <string>

std::string get_plural(std::size_t, const std::string &, const char = 's');

int main()
{
	std::cout << "\nEnter a word to get it's plural form: ";
	std::string word;
	if (std::cin >> word)
		std::cout << "And the plural for " << word << " should be..\t" \
				  << get_plural(word.size(), word ) // 3rd argument is default
				  << "\n(I'm just adding a 's' as a sufix)\n" << std::endl;

	return 0;
}

std::string get_plural(std::size_t counter, const std::string &word, \
					   const char s)
{
	return (counter > 1) ? word + s : word;
}
