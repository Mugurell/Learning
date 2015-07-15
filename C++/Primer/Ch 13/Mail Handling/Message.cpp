/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 22:09
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
 *  Implementation file for Message.h
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



#include <iostream>

#include "Message.h"
#include "Folder.h"

Message::Message(const Message &constructFromMe)
    : contents(constructFromMe.contents), folders(constructFromMe.folders) {

    addToFolders(constructFromMe);
}


Message::Message(Message &&constructFromMe)
{
    // moves folders and updates the Folder pointers
    moveFolders(&constructFromMe);
}


Message&
Message::operator=(Message &&moveFromMe)
{
    if (this != &moveFromMe) {   // direct check for self-assignment
        removeFromFolders();     // destroy the state of the left operand
        contents = std::move(moveFromMe.contents);  // move assignment

        // reset the Folders to point to this Message
        moveFolders(&moveFromMe);
    }
    return *this;
}


Message&
Message::operator=(const Message &copyFromMe) {
    // handle self-assignment by removing pointers before inserting them
    removeFromFolders();              // update existing Folders
    contents = copyFromMe.contents;   // copy message contents from copyFromMe
    folders = copyFromMe.folders;     // copy Folder pointers from copyFromMe
    addToFolders(copyFromMe);         // add this Message to those Folders

    return *this;
}


Message::~Message() {
    // The call to removeFromFolders ensures that no Folder has a pointer to
    // the Message we are destroying. The compiler automatically invokes the
    // string destructor to free contents and the set destructor to clean up
    // the memory used by those members.
    removeFromFolders();
}


// When we copy a Message, the copy should appear in the same Folders
// as the original Message. As a result, we must traverse the set of
// Folder pointers adding a pointer to the new Message to each Folder that
// points to the original Message.
void
Message::addToFolders(const Message &message) {
    for (Folder *each : message.folders)  // for each Folder that holds message
        each->addMessage(this);           // add a pointer to this Message in it
}


// When a Message is destroyed, we must remove this Message from the Folders
// that point to it. This work is shared with the copy-assignment operator.
void
Message::removeFromFolders() {
    for (Folder *each : folders)        // for each pointer in folders
        each->removeMessage(this);      // remove this Message from that Folder

    // also clear it's own folders member as well
    folders.clear();
}


void
Message::moveFolders(Message *message)
{
    folders = std::move(message->folders);  // uses set move assignment
    for (Folder *each : folders) {      // for each Folder
        each->removeMessage(message);   // remove the old Message from Folder
        each->addMessage(this);         // add this Message to that Folder
    }
    message->folders.clear();     // ensure that destroying message is harmless
}


// will put the Message into the given Folder
void
Message::save(Folder &folder) {
    // add the given Folder to our list of Folders
    folders.insert(&folder);

    // add this Message to folder's set of Messages
    folder.addMessage(this);
}


// will take the Message out from the given Folder
void
Message::remove(Folder &folder) {
    // take the given Folder out of our list of Folders
    folders.erase(&folder);

    // remove this Message from folder's list of Messages
    folder.removeMessage(this);
}



void
swap(Message &leftMessage, Message &rightMessage) {
    using std::swap;        // not strictly needed in this case, but good habit

    // remove pointers to each Message from their (original) respective Folders
    for (auto folder : leftMessage.folders)
        folder->removeMessage(&leftMessage);
    for (auto folder : rightMessage.folders)
        folder->removeMessage(&rightMessage);

    // swap the contents and Folder pointer sets
    swap(leftMessage.folders, rightMessage.folders);     // uses swap(set&, set&)
    swap(leftMessage.contents, rightMessage.contents);   // uses swap(string&, string&)

    // add pointers to each Message to their (new) respective Folders
    for (auto folder : leftMessage.folders)
        folder->addMessage(&leftMessage);
    for (auto folder : rightMessage.folders)
        folder->addMessage(&rightMessage);
}

// Functions used in the to swap Folders
void
Message::addFolder(Folder *received) {
    folders.insert(received);   // insert pointer to received Folder in the
                                // folders member of this Message
}


void
Message::removeFolder(Folder *received) {
    folders.erase(received);    // remove pointer to the received Folder from
                                // the folders member of this Message
}



const std::string &Message::getContents() const {
    return contents;
}
