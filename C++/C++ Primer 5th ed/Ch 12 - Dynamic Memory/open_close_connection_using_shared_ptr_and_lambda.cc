/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          vineri 26 iunie 2015, 16:08:10 +0300
**  Last updated:           ---
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
**  Rewrite the first exercise (hookup_man_bombshell_w_shared_ptr_and_deleter)
**  to use a lambda (10.3.2, p.388) in place of the end_connection function.
**
**  Bugs:
**  --- None ---
**
**  TODO:
**  --- None --- 
**
**  Notes:
**  Remember: When we use a smart pointer, the smart pointer class ensures that
**  memory is freed when it is no longer needed even if the block is exited 
**  prematurely - as in the case of an exception.
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>


typedef struct connection {
    connection() = default;
    connection(std::string i, int p) : ip(i), port(p) {}
    std::string ip;
    int port;
} Connection;

typedef struct destination {
    destination() = default;
    destination(std::string i, int p) : ip(i), port(p) {} 
    std::string ip;
    int port;
} Destination;


Connection Connect(Destination*);
void Disconnect(Connection*);
void ConnectDisconnect(destination&);


int main()
{
    Destination dest("188.0.0.0", 80);

    ConnectDisconnect(dest);

    std::cout << "\n\nPretty cool, huh?\n" << std::endl;

    return 0;
}


Connection
Connect(Destination *dest) {
    std::shared_ptr<Connection> conn(new Connection(dest->ip, dest->port));
    std::cout << "\n\t....\nCreating connection(" << conn.use_count()
              << ")" << std::endl;
    return *conn;
}

void
Disconnect(Connection *open_conn) {
    std::cout << "\n\t....\nClosing connection(" << open_conn->ip 
              << ":" << open_conn->port << ")" << std::endl;
}

void
ConnectDisconnect(Destination &dest) {
    Connection conn = Connect(&dest);
    std::shared_ptr<Connection> n(&conn, [](Connection *p) { Disconnect(p); });
    std::cout << "\n\t....\nConnecting now(" << n.use_count() << ")"
              << std::endl;
    //throw std::runtime_error("***");
}