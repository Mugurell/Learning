//
// Created by Lingurar Petru-Mugurel on 29.05.2015.
//

#include "Func.h"


// a fstream does not have iterators! You cant use a range-for loop to
// iterate through such a stream !!!
// but a fstream is a stream which inherits the iostream operators ;-)
bool
ReadWordsToVec(const std::string &filename, std::vector<std::string> &vec) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string buf;
        while (inputFile >> buf)
            vec.push_back(buf);
        return true;
    } else {
        std::cerr << "\nError: Couldn't open " << filename << ".\n"
        << std::endl;
        return false;
    }
}



bool
ReadLinesToVec(const std::string &fileName, std::vector<std::string> &vec) {
    std::ifstream input_file(fileName);
    if (input_file) {
        std::string buf;
        while (std::getline(input_file, buf))
            vec.push_back(buf + '\n');
        return true;
    } else {
        std::cerr << "\nError: Couldn't open " << fileName << ".\n"
                  << std::endl;
        return false;
    }
}
