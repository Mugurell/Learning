/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          luni 22 iunie 2015, 10:18:59 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++11 -Wall -Werror -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 11.33: Implement your own version of the word-transformation
**  program.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  --- 
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>    // for std::runtime_error


void decript(const std::string&, const std::string&);
std::map<std::string, std::string> build_map (std::ifstream&);
std::string transform (const std::map<std::string, std::string>&,
                        const std::string&);
void print_file(const std::string&);


int main()
{
    std::cout << "\nThis is a beta program designed to decript the"
              << "\ncryptic conversations on facebook and Yahoo Messenger."
              << "\nThe intercepted communication, saved as"
              << "\"data/facebook_encripted_convo.txt\" apparently "
              << "says..:" << std::endl;
    print_file("data/facebook_encripted_convo.txt");

    std::cout << "\n\nI'll now try to decript it.\n\t....\n" << std::endl;
    decript("data/facebook_encripted_convo.txt", "data/dictionary.txt");

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}


void 
print_file(const std::string &FileName)
{
    std::ifstream InputFile (FileName);
    std::string buffer;
    while (std::getline(InputFile, buffer))
        std::cout << '\t' << buffer << std::endl;
}


std::map<std::string, std::string>
build_map(std::ifstream &DictF)
{
    std::map<std::string, std::string> dictionary;
    std::string key, value;
    while (DictF >> key && std::getline(DictF, value)) {
        if (value.size() > 1)
            dictionary[key] = value;
        else
            throw std::runtime_error("no rule for " + key);
    }

    return dictionary;
}


std::string
transform(const std::map<std::string, std::string> &dictionary, 
          const std::string &word)
{
    std::map<std::string, std::string>::const_iterator it;
    
    it = dictionary.find(word);
    if (it == dictionary.end())
        return word;
    
    return it->second;
}


void 
decript(const std::string &InputFname, const std::string &DictName)
{
    std::ifstream EncrF (InputFname), DictF (DictName);
    if (EncrF) {
        if (DictF) {
            std::map<std::string, std::string> dictionary = build_map(DictF);
            std::string line, cryptic_w, decripted_w;
            while (std::getline(EncrF, line)) {
                std::istringstream buff(line);
                bool first_word = true;
                while (buff >> cryptic_w) {
                    // std::cout << "\n**cryptic_w is \"" << cryptic_w 
                    //           << "\"**" << std::endl;
                    decripted_w = transform(dictionary, cryptic_w);
                    // std::cout << "\n**decripted_w is \"" << decripted_w 
                    //           << "\"**\n";
                    if (first_word && decripted_w[0] == ' ') {
                        std::cout << '\t' << decripted_w.substr(1);
                        first_word = false;
                    } else {
                        std::cout << decripted_w;
                    }
                }
                std::cout << std::endl;
            }
        } else
            std::cerr << "\n**DictF is NOT open**\n";
    } else
        std::cerr << "\n**EncrF is NOT open**\n";

}