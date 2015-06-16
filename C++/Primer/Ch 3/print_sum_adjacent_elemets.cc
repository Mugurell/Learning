/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 1 mai 2015, 18:41:08 +0300
**  Last updated:     sâmbt 2 mai 2015, 12:07:19 +0300
**
**  Compilation:   g++ -std=gnu++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**					  -Woverloaded-virtual -Winvalid-pch -Wcast-align
**					  -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**					  -Wmissing-format-attribute -Wmissing-include-dirs  
**					  -Wredundant-decls -Wswitch-default -Wswitch-enum  
**
**  Execution:     ./...
**
**  Description:
**  Exercise 3.20: Read a set of integers into a vector. Print the sum of each
**  pair of adjacent elements. Change your program so that it prints the sum of
**  the first and last elements, followed by the sum of the second and 
**  second-to-last, and so on.
**
**  Bugs:
**  - Can't clear std::cin, so the program doesn't wait to enter an option
**	- ATM I'm entering a letter to stop cin saving numbers. This means though
**	that the last element of my vector<int> is a letter, which is accounted
**	for in my math operation.
** 	- Be sure that sum_extremes() will print the correct number of sums.
**	Currently the sum of the middle elements is not accounted for.
**
**  TODO:
**  -- Figure out how to remove an element from a vector.
**	-- Get rid of 'em bugs!
**			
**
**  Expected result:
**  - Work exactly how the exercise was described.
**
**  Notes:
**	- To delete a certain object from a vector you must use erase!!!
**	Look on line 121 : 	row.erase(row.cbegin() + (row.size()/2));
**
*******************************************************************************
******************************************************************************/





#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;
//using std::vector<int>::erase();  - asa e corect !!!!

void sum_adjacent(vector<int> row);
void sum_extremes(vector<int> row);

int main()
{
	cout << "\nEnter some numbers separated by spaces:" << endl;

	int nr;
	vector<int> row;
	while (cin >> nr && nr != '\n') {
		cout << "Nr este " << nr << endl;
		row.push_back(nr);
	}

	cout << "Aici e blocat!" <<endl;
	if (row.size() == 1) {
		cout << ".. What can I do with only one number???\n\tPfff" << endl;
		return -1; 
	}

	cout << "Ba nu, eu Horia zic ca e aici blocat!" << endl;
	cin.clear();
	while (cin.get() != '\n');
	cout << "Now what do you want to do with them my man?:" << endl;
	cout << "\tOption A: Get the sum of the adjacent numbers." << endl;
	cout << "\tOption E: Get the sum of the extremes.\n" << endl;

	char choice;
	cin >> choice;
	if (choice >= 'a' && choice <= 'z')
		choice -= 'a' - 'A';

	cout << "choice-ul e " << choice << endl;

	cin.clear();
	switch(choice) {
		case 'A' : sum_adjacent(row); break;
		case 'E' : sum_extremes(row); break;
		default  : cout << "Tough choice, I understand you man. :-|" << endl; break; 
	}

	return 0;
}

void sum_adjacent(vector<int> row)
{
	if (row.size() == 2)
		cout << "The sum of the two adjacent numbers is: ";
	else {
		row.erase(row.cend() - 1);
		cout << "The sums of the adjacent numbers is:" << endl;
	}

	for (decltype(row.size()) i {0}; i < row.size(); ++i) {
		if (row.size() == 2)
			cout << row[i] + row[i+1] << endl;
		else 
			cout << ' ' << row[i] + row[i+1];
	}

	cout << endl;
}

void sum_extremes(vector<int> row)
{
	if (row.size() <= 3) {
		row.erase(row.cbegin() + (row.size()/2));
		cout << "The sum of the 2 extremes is: ";
	} else 
		cout << "The sums of the extremes are:" << endl;


	for (decltype(row.size()) x {0}, y = row.size(); \
		x < (row.size() / 2); x += 1, y -= 1) {
		if (row.size() <= 3)
			cout << row[x] + row[y] << endl;
		else
			cout << ' ' << row[x] + row[y];
	}

	cout << endl;
}