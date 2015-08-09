/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 13 iunie 2015, 21:46:32 +0300
**  Last updated:     sâmbt 13 iunie 2015, 22:20:08 +0300
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**	 (g++ 5.1)		  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:    ./...
**
**  Description:
**  Exercise 10.33: Write a program that takes the names of an input file and
**	two output files. The input file should hold integers. Using an
**	istream_iterator read the input file. Using ostream_iterators, write the
**	odd numbers into the first output file. Each value should be followed by a
**	space. Write the even numbers into the second file. Each of these values
**	should be placed on a separate line.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  std::copy_if() accepts a unary predicate, std::copy() NO!
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>


int main()
{
	std::cout << "\nEnter the name of the input file(full of ints):\n\t";
	std::string buff;
	std::cin >> buff;
	std::ifstream inFile(buff);
	if (inFile.is_open()) {
		std::cout << "\nNow the name for the output file which will hold the"
			  	  << " odd numbers:\n\t";
		std::cin >> buff;
		std::ofstream oddFile(buff);		// out and trunc are implicit ;-)
		if (oddFile) {
			std::cout << "\nNow the name for the output file which will hold"
					  << " the even numbers:\n\t";
			std::cin >> buff;
			std::ofstream evenFile(buff);
			if (evenFile) {
			// store the input numbers
				std::istream_iterator<int> input_nr(inFile), eof;
				std::vector<int> vint(input_nr, eof);

			//  print the odds/evens in separate files
				std::ostream_iterator<int> odds(oddFile, " ");
				std::ostream_iterator<int> evens(evenFile, "\n");

				std::copy_if(vint.cbegin(), vint.cend(), odds,
					[](const int &nr) { return nr % 2; });
				std::copy_if(vint.cbegin(), vint.cend(), evens,
					[](const int &nr) { return !(nr % 2); });

			/*	// pezy's solution
				std::for_each(input_nr, eof, 
							[&odds, &evens](const int &nr)
							{ *(nr & 0x1 ? odds : evens)++ = nr; });*/

			// close the files
				evenFile.close();
				oddFile.close();
				inFile.close();

			// Bbye
				std::cout << "\n\n\tDone!\n\tIf there's nothing else...\n"
						  << std::endl;
			} else {
				std::cerr << "\n\nInvalid name.\n\tAborting...\n" << std::endl;
				oddFile.close();
				inFile.close();
			}
		} else {
			std::cerr << "\n\nInvalid name.\n\tAborting...\n" << std::endl;
			inFile.close();
		}
	} else
		std::cerr << "\n\nInvalid name.\n\tAborting...\n" << std::endl;

	return 0;
}