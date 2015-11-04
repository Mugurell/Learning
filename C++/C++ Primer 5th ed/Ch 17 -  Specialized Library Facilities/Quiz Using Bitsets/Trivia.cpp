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
 *  Implementation file for the Trivia class from Trivia.h
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


#include <ctime>

#include "Trivia.h"


Trivia::Contestant::Contestant(const char* n) : name(n)
{
    srand((unsigned)time(NULL));
    // (-1) + 1 necessary to have at least 1 question to answer to
    noOfQuestions = (rand() % (questions.size() - 1)) + 1;
}



std::vector<std::string> Trivia::grades{"F", "D", "C", "B", "A", "A++"};

// Every value in a pair corresponds to a response bit in our responses bitset
std::vector<std::pair<std::string, std::string>> Trivia::questions{
    {"What is the tallest mountain in Kyrgyzstan?", "Jengish Chokusu"},
    {"Who was the governour of California? - Arnold..?", "Schwarzenegger"},
    {"Who invented the first true automobile?", "Karl Benz"},
    {"Which country is known as the Pearl of Africa?", "Uganda"},
    {"Which vitamin is also known as pantothenic acid?", "B5"},
    {"What is the name of the second man on the Moon?", "Buzz Aldrin"},
};


void Trivia::Contestant::startGame()
{

    std::cout << name << ", you'll have to answer to " << noOfQuestions
        << " questions.";

    unsigned i = 0;
    while (i < noOfQuestions)
    {
        another_question:
        unsigned randomQuestionNo = rand() % noOfQuestions;
        std::string userAnswer;

        // Verify if the user allready gave the correct answer for this question
        if (responses.test(randomQuestionNo))
            goto another_question;
        std::cout << '\n' << i + 1 << ' '
            << questions.at(randomQuestionNo).first << "\n\t-> ";

        std::getline(std::cin, userAnswer);
        if (questions.at(randomQuestionNo).second == userAnswer)
        {
            responses.set(randomQuestionNo);
        }
        i++;
    }
    std::cout << "\n\nThat's it for this round\n";
}


void Trivia::Contestant::printResults()
{
    std::cout << "\n\n" << name << ", you answered correctly on "
        << getNoOfCorrectAnswers() << " from " << getNoOfQuestions()
        << " questions.";
    std::cout << "\nSo, you're grade would be " << getGrade();
}


std::string Trivia::Contestant::calculateGrade()
{
    // get the number of correct answers
    std::size_t correctAnswers = countCorrectAnswers();

    // reports the number of correct answers to the number of questions
    correctAnswers = correctAnswers * 100 / noOfQuestions;

    // get the appropriate grade in the US system
    if (correctAnswers < 60)
        grade = grades.at(0);   // "F"
    else
    {
        grade = grades.at((correctAnswers - 50) / 10);
        if (correctAnswers % 10 > 7)
            grade + "++";
        else if (correctAnswers % 10 < 3)
            grade + "--";
    }

    return grade;
}


std::size_t Trivia::Contestant::countCorrectAnswers()
{
    std::size_t noOfAnswers = responses.size();
    std::size_t correctAnswers = 0;
    while (noOfAnswers-- > 0)
    {
        if (responses.test(noOfAnswers))
            correctAnswers++;
    }

    return correctAnswers;
}
