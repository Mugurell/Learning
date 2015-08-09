//
// Created by mugurel on 24.05.2015.
//

#include "Person.h"


// define member functions
inline void
Person::fill() {
    std::cin >> name >> address;
}

inline std::ostream&
Person::read(std::ostream &os) {
    os << name << " who lives in " << address;
    return os;
}

// define non-member function
inline std::ostream&
read(Person a) {
    std::cout << a.name << " who lives in " << a.address;
    return std::cout;
}

inline void
fill(Person &a) {
    std::cin >> a.name >> a.address;
}


