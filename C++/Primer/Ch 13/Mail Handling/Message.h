/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 21:48
 *  Last updated:     09 Jul 2015, 07:20 PM
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
 *  Exercise 13.34: Write the Message class as described in this section.
 *  Exercise 13.37: Add members to the Message class to insert or remove a
 *  given Folder* into folders. These members are analogous to Folder’s addMsg
 *  and remMsg operations.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  !! A constructor that supplies default arguments for all its parameters
 *  also defines the default constructor.
 *  !! A friend declaration only specifies access. It is not a general
 *  declaration of the function. If we want users of the class to be able to
 *  call a friend function, then we must also declare the function separately
 *  from the friend declaration.
 *
*******************************************************************************
******************************************************************************/



#ifndef MAIL_HANDLING_MESSAGE_H
#define MAIL_HANDLING_MESSAGE_H


#include <string>
#include <set>


class Folder;

class Message {
    friend class Folder;

    // Since the library defines swap for both string and set, our Message class
    // can benefit from defining its own version of swap - avoid extraneous
    // copies of contents and folders members.
    friend void swap(Message &leftMessage, Message &rightMessage);

    // Needed to befriend the swap function declared in Folder because it need
    // access to private functions (addFolder(), removeFolder)
    friend void swap(Folder &leftFolder, Folder &rightFolder);

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &message = "")
        : contents(message) { }

    // copy control to manage pointers to this Message
    Message(const Message &constructFromMe);        // copy constructor
    Message& operator=(const Message &copyFromMe);  // copy assignment operator
    ~Message();                                     // destructor

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &folder);
    void remove(Folder &folder);

    const std::string & getContents() const;

private:
    std::string contents;           // actual message text
    std::set<Folder*> folders;      // Folders that have this Message

    // utility functions used by the copy constructor, assignment and destructor
    // add this Message to the Folders that point to the parameter
    void addToFolders(const Message &message);
    // remove this Message from every Folder in folders
    void removeFromFolders();

    // utility functions used by the swap method of Folder class
    // add/remove Folders which should have this message
    void addFolder(Folder *received);
    void removeFolder(Folder *received);
};


void swap(Message &leftMessage, Message &rightMessage);


#endif //MAIL_HANDLING_MESSAGE_H
