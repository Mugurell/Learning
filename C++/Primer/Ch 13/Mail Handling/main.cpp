/******************************************************************************
*******************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          08 Jul 2015, 21:43
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
