//
// Class needed for understanding_the_copy_constructor.cc
//

    
#include <iostream>
#include <new>


class Test{
    public:
        Test(int i = 14) : nr(new int(i)) 
        { std::cout << "\n**Simple constructor called**\n";}
        Test& operator=(const Test &toBeCopied);
        Test(const Test &toBeCopied);
        ~Test() { delete nr; std::cout << "\n**Destructor called**\n"; }
        int getNr() const {return *nr;}
    private:
        int *nr;
};


Test::Test(const Test &toBeCopied)
    : nr(new int (*toBeCopied.nr)) {
     std::cout << "\n**Copy constructor called**\n"; 
}


Test& 
Test::operator=(const Test &toBeCopied) {
    delete nr;
    nr = (new int(*toBeCopied.nr));
    std::cout << "\n**Operator = called**\n";
    return *this;
}


