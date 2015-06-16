/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          29.05.2015 13:12
 *  Last updated:     29.05.2015 13:26
 *
 *  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic 
 *	 (g++ 5.1)		    
 *
 *  Execution:    ./...
 *
 *  Description:
 *  --- This is a description of what the program does ---
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


#include "sales.cc"
#include <fstream>


int main(int argc, char **argv)
{
    std::cout << std::unitbuf;      // will flush the buffer after every output

    std::ifstream input(argv[1]);	// will open a source text file
    std::ofstream output(*(argv+2));	// will print the output in this file

    if (input.good() && output) {      // check if the files were opened
                                        // correctly
        Sales_data total;
        if (read(input, total)) {
            Sales_data trans;
            while (read(input, trans)) {
                if (total.isbn() == trans.isbn())
                    total.combine(trans);
                else {
                    print(output, total) << std::endl;
                    print(std::cout, total) << std::endl;
                    total = trans;
                }
            }
            print(output, total) << std::endl;
            print(std::cout, total) << std::endl;
        } else {
            std::cerr << "\nError: No valid data in input file!\n" << std::endl;
            return -1;
        }
    } else {
        std::cerr << "\nError opening files\n" << std::endl;
    }

    if (input.is_open() && output.is_open()) {
        input.close();  output.close();
        if (!input.is_open() && !output.is_open())
            std::cout << "\nThe sales report was successfully saved in "
                      << argv[argc - 1] << ".\n" << std::endl;
    }

    //note:
    return 0;

}
