//
// Created by Lingurar Petru-Mugurel on 29.05.2015.
//

#ifndef READ_FILE_INTO_STRING_FUNC_H
#define READ_FILE_INTO_STRING_FUNC_H


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool ReadWordsToVec(const std::string &fileName,
                    std::vector<std::string> &vec);

bool ReadLinesToVec(const std::string &filename,
                    std::vector<std::string> &vec);



#endif //READ_FILE_INTO_STRING_FUNC_H