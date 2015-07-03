//
// Created by Lingurar Petru-Mugurel on 30.06.2015.
//

#ifndef READ_PRINT_USING_STRBLOBS_FILEOPERATIONS_H
#define READ_PRINT_USING_STRBLOBS_FILEOPERATIONS_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "StringBlob.h"


std::string getInputFileName(void);
bool isValid(std::string inputFileName);
StringBlob read(std::string inputFileName);
std::ostream& printInputFile(StringBlob&, std::ostream&);


#endif //READ_PRINT_USING_STRBLOBS_FILEOPERATIONS_H