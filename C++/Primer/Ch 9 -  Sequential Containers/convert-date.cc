/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 8 iunie 2015, 18:44:42 +0300
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
**  Exercise 9.51: Write a class that has three unsigned members
**	representing year, month, and day. Write a constructor that takes a string
**	representing a date. Your constructor should handle a variety of date
**	formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Ok.. the program is good just for 2 versions of date,
**	but it's a proof of concept! :-P
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>


struct Date {
	unsigned day;
	unsigned month;
	unsigned year;
};

Date convert_date(std::string);


int main()
{
	std::cout << "\nThis program will recognize days/month/year from a string"
			  << "\nconvert the string into ints, and print them accordingly."
			  << "\nThe accepted formats are:\n\t"
			  << "1) dd/mm/yyyy\n\t"
			  << "2) dd, month, yyyy"
			  << "\n\nPlease enter the date:";
	std::string date_string;
	std::getline(std::cin, date_string);

	Date converted = convert_date(date_string);

	std::cout << "\nSo, the date, viewed as int is:\n\t"
			  << converted.day << " "
			  << converted.month << " "
			  << converted.year << std::endl;

	std::cout << "\n\nCool, rite?\n" << std::endl;
	return 0;
}


Date
convert_date(std::string s)
{
	Date d;
	unsigned format = 0;

	// 1/1/1900
	if (s.find_first_of("/") != std::string::npos)
		format = 0x10;

	// 1, Jan, 1900
	if (s.find_first_of(",") != std::string::npos)
		format = 0x01;


	switch (format) {
		// format 1/1/1900
		case 0x10:
			d.day 	= std::stoi(s.substr(0, s.find_first_of("/")));
			d.month = std::stoi(s.substr(s.find_first_of("/")+1, 
										s.find_last_of("/")));
			d.year	= std::stoi(s.substr(s.find_last_of("/")+1));
			break;

		// format 1, month, 1900
		case 0x01:
			d.day 	= std::stoi(s.substr(0, s.find_first_of(",")));

			if 		( s.find("Jan") < s.size() ) d.month = 1;
			else if ( s.find("Feb") < s.size() ) d.month = 2;
			else if ( s.find("Mar") < s.size() ) d.month = 3;
			else if ( s.find("Apr") < s.size() ) d.month = 4;
			else if ( s.find("May") < s.size() ) d.month = 5;
			else if ( s.find("Jun") < s.size() ) d.month = 6;
			else if ( s.find("Jul") < s.size() ) d.month = 7;
			else if ( s.find("Aug") < s.size() ) d.month = 8;
			else if ( s.find("Sep") < s.size() ) d.month = 9;
			else if ( s.find("Oct") < s.size() ) d.month = 10;
			else if ( s.find("Nov") < s.size() ) d.month = 11;
			else if ( s.find("Dec") < s.size() ) d.month = 12;

			d.year = std::stoi(s.substr(s.find_last_of(",")+1));
			break;
		default:
			break;
	}

	return d;
}