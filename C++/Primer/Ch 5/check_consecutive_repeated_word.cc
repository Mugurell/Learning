/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          sâmbt 9 mai 2015, 15:45:06 +0300
**  Last updated:     mari 12 mai 2015, 18:35:06 +0300

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
**  Exercise 5.14: Write a program to read strings from standard input
**	looking for duplicated words. The program should find places in the input
**	where one word is followed immediately by itself. Keep track of the largest
**	number of times a single repetition occurs and which word is repeated. Print
**	the maximum number of duplicates, or else print a message saying that no
**	word was repeated. For example, if the input is
**							how now now now brown cow cow 
**	the output should indicate that the word now occurred three times.
**
**  Bugs:
**  Nu pot sa fac a.i. steluta/spatiul (care arata nrul de cuvinte repetate)
**	sa ocupe acelasi spatiu in tabel cat ocupa si cuvantul la care se refera.
**
**  TODO:
**  --- None --- 
**
**  Expected result:
**  --- You can write here the execution command & the expected result --- 
**
**  Notes:
**  ... Mai am de lucrat la asta...
**	Trebuie sa gasesc cum setez wide-ul la ce vreau sa scriu...
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <cstdio>	// will use printf for a little bit of formatting

int main()
{
	std::cout << "\nSay whatever you like, I'll look for identical " \
			  << "consecutive words : " << std::endl;
	std::cout << "(I'm gonna stop when you say \"quit\".)" << std::endl;

	std::vector<std::string> prop;		// the big string with all words
	std::vector<int> cuv_count;			// # of each different words
	std::string cuvant;					// buffer for each word read
	int nr_max (0);						// biggest # of identical words
	unsigned counter {0};				// use a subscript
	bool first_word = true;				// to separate first word/others

	while (std::cin >> cuvant && cuvant != "quit") {
		if (first_word) {
			prop.push_back(cuvant);
			cuv_count.push_back(1);
			first_word = false;
			continue;
		}
		for (auto beg = prop.begin(), end = prop.end(); beg != end; \
			++beg, ++counter) {
			if (cuvant == *beg) {
				cuv_count[counter] += 1;
				counter = 0;
				break;
			} else if (beg == end -1) {
				prop.push_back(cuvant);
				cuv_count.push_back(1);
				counter = 0;
				break;
			 }  else {
			 	// Nothing to do here.
			}
		}
	}

	std::cout << "Counterul este acum..:" << std::endl;
	std::cout << " Counterul are " << cuv_count.size() << " elements\n";
	for (auto x : cuv_count)
		std::cout << ' ' << x;
	std::cout << std::endl;
	for (auto word : prop)
		std::cout << ' ' << word;

	std::cout << "\nAm terminat counterul" << std::endl;

	nr_max = 0;				// will now keep max # of same word
	counter = 0;			// will now be used as a subscript for the
							// corresponding word in prop
	for (auto beg = cuv_count.begin(); beg != cuv_count.end(); ++counter, ++beg) {
		std::cout << "*beg e " << *beg << " iar nr max e " << nr_max \
				  << std::endl;
		if (*beg > static_cast<int>(nr_max)) {
			nr_max = *beg;
			cuvant = prop[counter];
		}
	}

	std::cout << "\n\nThe word " << cuvant << " was repeated " \
			  << nr_max << " times.\n" << std::endl;

	// for (std::string cuv : prop)
	// 	std::cout << cuv << " are " << cuv.size() << std::endl;
	while (nr_max > 0) {
		printf("times x %d |", nr_max--);
		for (unsigned x = 0; x < static_cast<unsigned>(cuv_count.size()); x++) {
			//unsigned cuv_lenght = prop[x].size() / 2;
			if (cuv_count[x] > nr_max)
				printf("%c   ", '*');
			else {
				printf("%c   ", ' ');
			//	printf("%*c", ' ', static_cast<int>(prop[x].size()));
			}
		}
		putchar('\n');
	}
	std::cout << "   Word   ";
	for (auto cuv : prop)
		std::cout << '|' << cuv;

	std::cout << '\n' << std::endl; 

	return 0;
}
