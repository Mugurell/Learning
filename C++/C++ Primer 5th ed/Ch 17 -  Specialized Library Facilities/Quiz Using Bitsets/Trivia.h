/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08-Oct-15, 01:22 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  ---
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  --- 
 *
********************************************************************************
*******************************************************************************/


#ifndef QUIZ_USING_BITSETS_CONTESTANT_H
#define QUIZ_USING_BITSETS_CONTESTANT_H


#include <bitset>
#include <string>
#include <vector>
#include <iostream>


struct Trivia
{
    struct Contestant
    {
        explicit Contestant(const char* n);

        void startGame();

        void printResults();
        std::size_t getNoOfCorrectAnswers() { return countCorrectAnswers(); }
        std::size_t getNoOfQuestions() { return noOfQuestions; }
        std::string getGrade() { return calculateGrade(); }

    private:
        std::string calculateGrade();
        std::size_t countCorrectAnswers();

        std::string name;
        std::size_t noOfQuestions;
        std::bitset<64> responses;
        std::string grade;
    };

private:
    static std::vector<std::string> grades;
    static std::vector<std::pair<std::string, std::string>> questions;
};


#endif //QUIZ_USING_BITSETS_CONTESTANT_H
