//
// Created by Lingurar Petru-Mugurel on 30.06.2015.
//

#ifndef READ_PRINT_USING_STRBLOBS_FILEOPERATIONS_H
#define READ_PRINT_USING_STRBLOBS_FILEOPERATIONS_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>


std::ifstream getInputFile(void);
bool isValid(std::ifstream);
void printInputFile(std::ifstream);

#endif //READ_PRINT_USING_STRBLOBS_FILEOPERATIONS_H