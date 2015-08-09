/******************************************************************************
*******************************************************************************
**
**  Author:           Lingurar Petru-Mugurel
**  Written:          joi 25 iunie 2015, 22:36:07 +0300
**  Last updated:           ---
**
**  Compilation:  g++ -std=c++11 -Wall -Wextra -pedantic -Wshadow  
**   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
**                    -Wformat=2 -Wformat-nonliteral 
**                    -Wmissing-format-attribute -Wmissing-include-dirs  
**                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
**
**  Execution:    ./...
**
**  Description:
**  Exercise 12.14: Write your own version of a function that uses a
**  shared_ptr to manage a connection.
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
**  Doesn't really work for me... see throw std::runtime_error() in Separate().
**
*******************************************************************************
******************************************************************************/


#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>


typedef struct man{
    int age;
    int money;
    std::string car;
    man(int a_, int m_, std::string c_) : age(a_), money(m_), car(c_) {};
} Man;

typedef struct bombshell{
    int age;
    std::string boob_cup_size;
    int kg;
    int iq;
    bombshell(int a_, std::string b_, int kg_, int iq_)
            : age(a_), boob_cup_size(b_), kg(kg_), iq(iq_) {};
} BombShell;


void ErasePhoneNumber(BombShell*&);
void HookUp(Man &m, BombShell &b) { std::cout << "\n\t...\n\t\tHooked up\n"; }
void Separate(Man&, BombShell&);
void PrintMan(const Man&);
void PrintWoman(const BombShell&);
void PrintMemory(BombShell&);

int main()
{

    Man gicu(30, 9999, "Mertz");
    BombShell ciciolina(27, "D", 60, 180);

    std::cout << "\n\t\tHooky Program\n\n"
              << "In the right corner we have a successful man:\n";
    PrintMan(gicu);

    std::cout << "\nAnd in the left corner we have a stunning woman:\n";
    PrintWoman(ciciolina);

    std::cout << "Let's see if they get along..";
    HookUp(gicu, ciciolina);

    std::cout << "\n\nUnfortunately? after some time they've decided to"
              << " separate..."
              << "\nAnd the man decided to forget that she ever existed.."
              << "\nWhen he tries to remember her all he gets is.."
              << std::endl;
    Separate(gicu, ciciolina);
    PrintMemory(ciciolina);

    std::cout << "\n\nPretty cool, huh?" << std::endl;
}

// When bimbo is destroyed it wont execute delete() on it's stored pointer.
// Instead, bimbo will call ErasePhoneNumber() on that pointer.
void
Separate(Man &m, BombShell &cici) {
    std::shared_ptr<BombShell> bimbo(&cici, ErasePhoneNumber);
    //throw std::runtime_error("");
}

void
ErasePhoneNumber(BombShell *&cici) {
    std::cout << "\n\tShe was forgotten.\n" << std::endl;
}

void
PrintMan(const Man &m) {
    std::shared_ptr<Man> man(new Man(m));
    std::cout << "Contender " << man.use_count() << '\n'
              << "Age " << m.age << " , " << m.money << " in bank, "
              << "and with a " << m.car << '.' << std::endl;
}

void
PrintWoman(const BombShell &w) {
    std::shared_ptr<BombShell> woman (new BombShell(w));
    std::cout << "Contender " << woman.use_count() << '\n'
              << "Age " << w.age << ", with nice size "
              << w.boob_cup_size << " breasts, " 
              << w.kg << " kg and a " << w.iq << " IQ." << std::endl;
}

void
PrintMemory(BombShell &w) {
    std::cout << w.boob_cup_size << " .. Nice memories.." << std::endl;
}