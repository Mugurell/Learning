/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 22:09
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
 *  Implementation file for Folders.h
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


#include "Folder.h"
#include "Message.h"


Folder::Folder(Message *newMessage) {
    messages.insert(newMessage);
}


Folder::Folder(const Folder &constructFromMe)
    : messages(constructFromMe.messages) {

    addToMessage(constructFromMe);
}


Folder&
Folder::operator=(const Folder &copyFromMe) {
    // handles self-assignment by removing pointers before assigning them
    removeToMessage();      // remove pointer to this Folder from every Message
    messages = copyFromMe.messages;     // copy messages from copyFromMe
    addToMessage(copyFromMe);           // add this folder to every Message

    return *this;
}


Folder::~Folder() {
    // the compiler will automatically call the set destructor
    // this will remove the pointer to this folder from every message
    removeToMessage();
}


void
Folder::addToMessage(const Folder &folder) {
    for (auto each : folder.messages)       // for each Message in Folder
        each->addFolder(this);              // add pointer to this Folder in it
}


void Folder::removeToMessage() {
    for (auto each : messages)          // for each Message in this Folder
        each->removeFolder(this);       // erase the pointer to this Folder
    messages.clear();                   // empty the messages set
}


void
swap(Folder &leftFolder, Folder &rightFolder) {
    using std::swap;        // not strictly needed in this case, but good habit

    // remove pointers to this Folder from each respective Message
    for (auto message : leftFolder.messages)
        message->removeFolder(&leftFolder);
    for (auto message : rightFolder.messages)
        message->removeFolder(&rightFolder);

    // swap the messages between the two operands
    swap(leftFolder.messages, rightFolder.messages);

    // add pointers to this new Folders to each respective Message
    for (auto message : leftFolder.messages)
        message->addFolder(&leftFolder);
    for (auto message : rightFolder.messages)
        message->addFolder(&rightFolder);
}



// Functions used to swap Messages
void
Folder::addMessage(Message *received) {
    messages.insert(received);      // insert pointer to the received Message
                                    // to the messages set of this Folder
}

void
Folder::removeMessage(Message *received) {
    messages.erase(received);       // remove pointer to the received Message
                                    // from the messages set of this Folder
}