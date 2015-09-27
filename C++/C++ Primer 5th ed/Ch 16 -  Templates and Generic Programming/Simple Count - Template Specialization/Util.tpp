/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          27-Sep-15, 04:41 PM
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations 
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *  Implementation file for the template functions declared in Util.h
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



template<typename T>
size_t count(const std::vector<T> &v, const T &value)
{
    unsigned match_count = 0;

    for (auto const& each : v)
    {
        if (each == value) {
            std::cout << "\nTemplated count found a match!";
            match_count++;
        }
    }

    if (match_count == 0)
        std::cout << "\nTemplated count found no matches!";

    return match_count;
}


template<>
size_t count(const std::vector<int> &v, const int &value)
{
    unsigned match_count = 0;

    for (auto const& each : v)
    {
        if (each == value) {
            std::cout << "\nSpecialized template<int> found a match!";
            match_count++;
        }
    }

    if (match_count == 0)
        std::cout << "\nTemplated template<int>count found no matches!";

    return match_count;
}


template<>
size_t count(const std::vector<double> &v, const double &value)
{
    unsigned match_count = 0;

    for (auto const& each : v)
    {
        if (each == value) {
            std::cout << "\nSpecialized template<double> found a match!";
            match_count++;
        }
    }

    if (match_count == 0)
        std::cout << "\nTemplated template<double>count found no matches!";

    return match_count;
}


template<>
size_t count(const std::vector<std::string> &v, const std::string &value)
{
    unsigned match_count = 0;

    for (auto const& each : v)
    {
        if (each == value) {
            std::cout << "\nSpecialized template<std::string> found a match!";
            match_count++;
        }
    }

    if (match_count == 0)
        std::cout << "\nTemplated template<std::string>count found no matches!";

    return match_count;
}


template<>
size_t count(const std::vector<const char*> &v, const char* const &value)
{
    unsigned match_count = 0;

    for (auto const& each : v)
    {
        if (each == value) {
            std::cout << "\nSpecialized template<const char*> found a match!";
            match_count++;
        }
    }

    if (match_count == 0)
        std::cout << "\nTemplated template<const char*>count found no matches!";

    return match_count;
}
