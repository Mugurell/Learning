/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          29.05.2015 16:20
 *  Last updated:     29.05.2015 18:06
 *
 *  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic 
 *	 (g++ 5.1)		    
 *
 *  Execution:    ./...
 *
 *  Description:
 *  Exercise 8.4: Write a function to open a file for input and read its
 *  contents into a vector of strings, storing each line as a separate
 *  element in the vector.
 *  Exercise 8.5: Rewrite the previous program to store each word in a
 *  separate element.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Expected result:
 *  --- You can write here the execution command & the expected result --- 
 *
 *  Notes:
 *  --- Anything that stands out ---
 *  --- Or needs to be treated with special attention ---
 *
*******************************************************************************
******************************************************************************/


#include "Func.cpp"

int main(int argc, char **argv)
{
    std::cout << std::unitbuf;   // flush the buffer after every output

    std::cout << "\nSo this little program will save all the content of a file"
              << " on disk\nin a local vector of strings.\n" << std::endl;

    std::cout << "Apparently I will work with the file named \"" << argv[argc-1]
              << "\".\n" << std::endl;

    std::cout << "What would you prefere?\n"
              << "1) Read the file line by line?\n"
              << "2) Read the file one word at a time?\n\t"
              << "Your answer [1] / [2] : ";

    unsigned short choice;
    std::cin >> choice;
    switch(choice) {
        case 1: {
            std::vector<std::string> filesContent;
            if (ReadLinesToVec(*(argv + 1), filesContent)) {
                std::cout << "So I've read the following:\n";
                for (auto word : filesContent)
                    std::cout << word;
            }
            break;
        }
        case 2: {
            std::vector<std::string> fileContent;
            if (ReadWordsToVec(argv[1], fileContent)) {
                std::cout << "So I've read the following:\n";
                for (auto word : fileContent)
                    std::cout << word;
            }
            break;
        }
        default:
            std::cout << "\nError: Invalid choice\nExiting..";
            break;
    }

    std::cout << '\n' << std::endl;
    return 0;

}