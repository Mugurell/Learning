/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          duminic 7 iunie 2015, 22:27:17 +0300
**  Last updated:     luni 8 iunie 2015, 11:06:41 +0300
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
**  A quick example of the implementation of the standard string-number
**	conversions.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  	- All the other "string to number" conversions works on the same model.
**		- Used "string.c_str()" to convert the std::string into a const char*.
**		- 'buffed_string' was use to test if stoi would skip all other characters
**	until it would get to the numbers. Apparently not. It would give me
**	'std::invalid_argument' and abord the program.
**	So it seems only ws can be skipped to get to number characters...
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>

int main()
{
	std::cout << "\nEnter a number to do some conversions with it\n\t";
	int orig_nr;
	std::cin >> orig_nr;

	std::cout << "\n\nSo, you chose \n\t|| " << orig_nr << " || as orig_nr.\n"
			  << "Let's get to it then:" << std::endl;

	std::string orig_string = std::to_string(orig_nr);
	std::cout << "\nFirst we'll convert that number into a string."
			  << "\n(a string which has ANSII characters [48 - 57].";
	std::cout << "\n\torig_string = std::to_string(orig_nr) \n\t=> "
			  << "orig_string = \"" << orig_string << '\"' << std::endl;

	orig_string += " meat 999.";
	std::string buffed_string;
	buffed_string += "bones ";// 
	buffed_string.append(orig_string.begin(), orig_string.end());
	std::cout << "\nNow let's put some meat on 'em bones.."
			  << "\nobuffed_string now is \n\t|| " << buffed_string << " ||.\n";


	/*
	** the general syntax is based on this model:
	**
	** stoi(s, p, b) - Will return the initial substring of 's' that has 
	**		  numeric content as an int.
	**				 - b indicates the numeric base. Defaults to 10.
	**				 - p is a pointer to a size_t in which to put the index of
	**		  the first nonnumeric value.
	*/
	size_t index = 0, *index_location = &index;
	std::cout << "\nNow let's convert that string into other numbers..:"
			  << "\nstd::stoi(buffed_string.c_str(), &index 10) =>"
			  << "\n\t" << std::stoi(orig_string.c_str(), &index, 10)
			  << "\nwith the first nonnumeric character at index "
			  << *index_location << " - " << '\"' << orig_string[*index_location]
			  << '\"' << '\n' << std::endl;

	return 0;
}