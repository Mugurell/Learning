/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 9 mai 2015, 20:35:38 +0300
**  Last updated:     		---
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
**  Exercise 5.20: Write a program to read a sequence of strings from the
**  standard input until either the same word occurs twice in succession or all
**  the words have been read. Use a while loop to read the text one word at a
**  time. Use the break statement to terminate the loop if a word occurs twice
**  in succession. Print the word if it occurs twice in succession, or else
**  print a message saying that no word was repeated.
**	Exercise 5.21: Revise the program from the exercise in § 5.5.1 (p. 191) so
**	that it looks only for duplicated words that start with an uppercase letter.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  Will send a .txt file saved in this same directory to be read by this prog
**	as to comply with the description - " .. or all the words have been read".
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>

int main()
{
	std::string first_word, second_word;
	bool flag = false;		// identical consecutive words?

	std::cout << std::endl;

	while (std::cin >> first_word && first_word != "EOF") {
		if (first_word == second_word) {
			flag = true;
			break;	// #3 break ca termine tot
		}
		while (std::cin >> second_word && second_word != "EOF") {
			if (first_word == second_word) 
				flag = true;
			break;	// #1 break ca sa reia loopul
		}	// #1 break will throw me here.
			// and the outer while will read again from std::cin
		if (flag == true)
			break;	// #2 break;
	}	// #2 break will throw me here.

	if (flag == true)
	std::cout << first_word << " was repeated 2 times " \
			  << "consecutively." << '\n' << std::endl;
	else
		std::cout << "Seems there were no consecutively repeated words." \
				  << '\n' << std::endl;
}
