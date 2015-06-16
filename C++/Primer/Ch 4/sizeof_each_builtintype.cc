/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          		---
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
**  Exercise 4.28: Write a program to print the size of each of the built-in
**	types.
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
**  --- Anything that stands out ---
**  --- Or needs to be treated with special attention ---
**
*******************************************************************************
******************************************************************************/

#include <iostream>			//high level IO operations

using std::cin;		using std::cout; 	using std::endl;

int main()
{
	cout << "\tVoid type:" << endl;
	cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes." \
		 << '\n' << endl;

	cout << "\tBoolean type:" << endl;
	cout << "bool:\t\t" << sizeof(bool) << " byte." << '\n' << endl;

	cout << "\tCharacter type:" << endl;
	cout << "char:\t\t" << sizeof(char) << " byte." << endl;
	cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes." << endl;
	cout << "char16_t:\t" << sizeof(char16_t) << " bytes." << endl;
	cout << "char32_t:\t" << sizeof(char32_t) << " bytes." << '\n' << endl;
	
	cout << "\tIntegral types:" << endl;
	cout << "short:\t\t" << sizeof(short) << " bytes." << endl;
	cout << "int:\t\t" << sizeof(int) << " bytes." << endl;
	cout << "long:\t\t" << sizeof(long) << " bytes." << endl;
	cout << "long long:\t" << sizeof(long long) << " bytes." << '\n' << endl;

	cout << "\tFloating point type:" << endl;
	cout << "float:\t\t" << sizeof(float) << " bytes." << endl;
	cout << "double:\t\t" << sizeof(double) << " bytes." << endl;
	cout << "long double:\t" << sizeof(long double) << " bytes." << '\n' <<endl;

	cout << "\tFixed wight integers:" << endl;
    cout << "int8_t:\t\t" << sizeof(int8_t) << " byte." << endl;
    cout << "uint8_t:\t" << sizeof(uint8_t) << " byte." << endl;
    cout << "int16_t:\t" << sizeof(int16_t) << " bytes." << endl;
    cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes." << endl;
    cout << "int32_t:\t" << sizeof(int32_t) << " bytes." << endl;
    cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes." << endl;
    cout << "int64_t:\t" << sizeof(int64_t) << " bytes." << endl;
    cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes." << '\n' << endl;
    	
    return 0;
}
