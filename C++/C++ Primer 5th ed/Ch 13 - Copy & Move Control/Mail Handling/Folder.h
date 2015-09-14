/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 21:48
 *  Last updated:     09 Jul 2015, 16:54
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
 *  Exercise 13.36: Design and implement the corresponding Folder class.
 *  That class should hold a set that points to the Messages in that Folder.
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
*******************************************************************************
******************************************************************************/



#ifndef MAIL_HANDLING_FOLDER_H
#define MAIL_HANDLING_FOLDER_H


#include <set>


class Message;

class Folder {
    friend class Message;

    // Define our own swap function to avoid unneeded copies of the messages.
    // Will be using the std::set's swap function to help with that.
    friend void swap(Folder &leftFolder, Folder &rightFolder);


    // Friend declaration needed because the swap function declared in Message
    // needs access to private functions of Folder (addMessage() and
    // removeMessage() ).
    friend void swap(Message &leftMessage, Message &rightMessage);

public:
    Folder(Message *newMessage);

    Folder(const Folder &constructFromMe);          // copy constructor
    Folder& operator=(const Folder &copyFromMe);    // copy assignment operator
    ~Folder();                                      // destructor

private:
    std::set<Message*> messages;        // Messages contained in this Folder

    // utility functions used by the copy constructor and assignment operator
    // add folder to folders set that have this message
    void addToMessage(const Folder &folder);
    // remove the pointer to this folder from every Message
    void removeToMessage();

    // utility functions used by the swap method of the Message class
    // add/remove pointers to Messages for the respective Folder
    void addMessage(Message *received);
    void removeMessage(Message *received);
};


// To make a friend visible to the users of the class, we usually declare
// each friend outside the class, but in the same header as the class itself.
// Most compilers will apparently make it visible even without this declaration.
void swap(Folder &leftFolder, Folder &rightFolder);


#endif //MAIL_HANDLING_FOLDER_H
