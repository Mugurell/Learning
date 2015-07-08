/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 22:09
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
 *  Implementation file for Message.h
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
 *  --- Anything that stands out ---
 *  --- Or needs to be treated with special attention ---
 *
*******************************************************************************
******************************************************************************/



#include <iostream>

#include "Message.h"









// add this Message to Folders that point to message
void
Message::addToFolders(const Message &message) {
    for (Folder *each : message.folders)  // for each Folder that holds message
        each->addMessage(this);           // add a pointer to this Message in it
}


// remove this Message from the corresponding Folders
void
Message::removeFromFolders() {
    for (Folder *each : folders)        // for each pointer in folders
        each->removeMessage(this);      // remove this Message from that Folder
}


// will put the Message into the given Folder
void
Message::save(Folder &newFolder) {
    // add the given Folder to our list of Folders
    folders.insert(&newFolder);

    // add this Message to newFolder's set of Messages
    newFolder.addMessage(this);
}


// will take the Message out from the given Folder
void
Message::remove(Folder &deprecatedFolder) {
    // take the given Folder out of our list of Folders
    folders.erase(&deprecatedFolder);

    // remove this Message from deprecatedFolder's list of Messages
    deprecatedFolder.removeMessage(this);
}