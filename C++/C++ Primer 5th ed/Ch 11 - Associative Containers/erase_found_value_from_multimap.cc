/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          duminic 21 iunie 2015, 19:11:28 +0300
**  Last updated:     duminic 21 iunie 2015, 20:21:28 +0300
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
**  Exercise 11.31: Write a program that defines a multimap of authors and
**  their works. Use find to find an element in the multimap and erase that
**  element. Be sure your program works correctly if the element you look for
**  is not in the map.
**  Exercise 11.32: Using the multimap from the previous exercise, write a
**  program to print the list of authors and their works alphabetically.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None ---  
**
**  Notes:
**  Interesting thing.. sorting the values in a container that by default
**  has it's keys sorted...  
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <map>
#include <set>


void print_mmap(std::multimap<std::string, std::string>&);
bool find_erase(std::multimap<std::string, std::string>&, std::string&);
void sort_mmap(std::multimap<std::string, std::string>&);
void clear_cin(void);

int main()
{
    std::cout << "\nLet's say we have a multimap with some"
              << "\nauthors and their great operas:" << std::endl;

    std::multimap<std::string, std::string>
        authors {{"Eminescu", "Scrisoarea I"},
                 {"Creanga", "La cirese"},
                 {"Eminescu", "Luceafarul"},
                 {"Bacovia", "Plumb"},
                 {"Eminescu", "Fat-Frumos"}};
    print_mmap(authors);

// Offer to sort the values in the multimap first.
    std::cout << "\n\nDo you want to sort the operas for each author"
              << "\nbefore proceeding? [Y] / [N]: ";
    unsigned char response;
    std::cin >> response;
    if (response >= 'a' && response <= 'z') response -= 'a' - 'A';
    switch (response) {
        case 'Y':
            sort_mmap(authors);
            //sort_mmap2(authors);
            std::cout << "\nCool, so now we have:" << std::endl;
            print_mmap(authors);
            break;
        default:
            break;
    }
    clear_cin();

// Ask which key to erase
    std::cout << "\n\nYou must now remove an author along with he's opera(s)."
              << "\nWhich one will it be? (type an author's name): ";
    std::string to_erase;
    std::cin >> to_erase;

// Try to erase the key.
// Behave differently depending on if the key exists in the mmap or not.
    if (find_erase(authors, to_erase)) 
        std::cout << "\n\nConsider it done!"
                  << "The multimap now contains..:" << std::endl;
    else
        std::cout << "\n\n** Seems like \"" << to_erase
                  << "\" was not a member of our multimap..."
                  << "\nSo it still contains..:" << std::endl;

    print_mmap(authors);

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}


void
print_mmap(std::multimap<std::string, std::string> &authors)
{
    unsigned short count = 1;
    for (const std::pair<std::string, std::string> &each_pair : authors) {
        std::cout << '\t' << count++ << " : " << each_pair.first
                  << " - " << each_pair.second << std::endl;
    }
}


bool
find_erase(std::multimap<std::string, std::string> &authors,
           std::string &to_erase)
{
/*
**lower_bound will return an iterator to:
**      - the first instance of the key given as argument
**      - the position to the first point where this key can be inserted
**upper_bound will return an iterator to:
**      - one past the last instance of the key
**  OR
**      - if the key is not in the multimap, to the first point where the
**        key can be inserted. <=> SAME AS IN THE CASE OF LOWER_BOUND !!!!
*/   
    std::multimap<std::string, std::string>::iterator
        first (authors.lower_bound(to_erase)),
        after_last (authors.upper_bound(to_erase));

    if (first == after_last)
        return false;
    
    while (first != after_last)
        authors.erase(first++);

    return true;
}


/*
** First way to sort the values in a multimap:
** Copy the pairs of a multimap in a multiset of that pairs
** http://stackoverflow.com/questions/21215214
*/
void
sort_mmap(std::multimap<std::string, std::string> &authors)
{
    std::multiset<std::pair<std::string, std::string>> mset;
// Let the multiset do all the lifting
// iterators returns a value_type - for maps: a pair <key, value>
    for (std::multimap<std::string, std::string>::iterator
         it = authors.begin(); it != authors.end(); ++it) {
        mset.emplace(*it);
    }

    authors.clear();        // now it will have size() == 0
    for (const std::pair<std::string, std::string> &each_pair : mset)
        authors.emplace(each_pair);
}



void
clear_cin(void)
{
    std::cin.clear();
    while(std::cin.get() != '\n');
}