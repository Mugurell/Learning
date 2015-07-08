/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 21:48
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral -Wmissing-declarations
 *                    -Wmissing-format-attribute -Wmissing-include-dirs
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum
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
 *  !! A constructor that supplies default arguments for all its parameters
 *  also defines the default constructor.
 *
*******************************************************************************
******************************************************************************/



#ifndef MAIL_HANDLING_MESSAGE_H
#define MAIL_HANDLING_MESSAGE_H


#include <string>
#include <set>


class Message {
friend class Folder;

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &message = "")
        : contents(message) { }

    // copy control to manage pointers to this Message
    Message(const Message &createFromMe);           // copy constructor
    Message& operator=(const Message &copyFromMe);  // copy assignment operator
    ~Message();                                     // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &newFolder);
    void remove(Folder &deprecatedFolder);

private:
    std::string contents;           // actual message text
    std::set<Folder*> folders;      // Folders that have this Message

    // utility functions used by the copy constructor, assignment and destructor
    // add this Message to the Folders that point to the parameter
    void addToFolders(const Message &message);
    // remove this Message from every Folder in folders
    void removeFromFolders();

};


#endif //MAIL_HANDLING_MESSAGE_H
