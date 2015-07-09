/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 21:43
 *  Last updated:     09 Jul 2015, 07:18 PM 
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
 *  Although copy control is most often needed for classes that allocate
 *  resources, resource management is not the only reason why a class might need
 *  to define these members. Some classes have bookkeeping or other actions that
 *  the copy-control members must perform.
 *  As an example of a class that needs copy control in order to do some
 *  bookkeeping, we’ll sketch out two classes that might be used in a
 *  mail-handling application.
 *  These classes, Message and Folder, represent, respectively, email
 *  (or other kinds of) messages, and directories in which a message might
 *  appear. Each Message can appear in multiple Folders. However, there will be
 *  only one copy of the contents of any given Message. That way, if the
 *  contents of a Message are changed, those changes will appear when we view
 *  that Message from any of its Folders.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None ---
 *
 *  Notes:
 *  This program clearly isn't fully utilized.
 *  Was just an exercise to try and implement various concepts..
 *
*******************************************************************************
******************************************************************************/



#include <iostream>

#include "Message.h"
#include "Folder.h"


int main()
{
    std::cout << "\n\n\t\tEMail Program\n\n";
    std::cout << "\nJust for the fun let's quicly create 2 emails,"
              << "\none blank, and one with some characters in it..\n";

    Message email1;
    Message email2("Tommorow is another day");
    std::cout << "\"" << email1.getContents() << "\"\n"
              << "\"" << email2.getContents() << "\"";

    std::cout << "\n\nNow let's copy the second mail into 2 folders,"
              << "\nLet's say draft and saved." << std::endl;
    Folder draft(&email2);
    Folder saved(&email2);

    std::cout << "\nEdit it a little.. \nand print 'em again." << std::endl;
    email2 = (Message(std::string("Suffer the pain of discipline")
                                 + " or suffer the pain of regret!"));

    std::cout << "\"" << email1.getContents() << "\"\n"
              << "\"" << email2.getContents() << "\"";


    std::cout << "\n\nPretty cool, huh?\n" << std::endl;
    return 0;
}