//
// Created by Lingurar Petru-Mugurel on 28.05.2015.
//

#ifndef DEBUG_EX_DEBUG_H
#define DEBUG_EX_DEBUG_H


class Debug {
public:
    // A constexpr constructor must initialize every data mamber!
    // The init may either use a constexpr expression or be a const expresstion
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }

    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_others(bool b) { hw = b; }

private:
    bool hw;        // hardware errors other than IO errors
    bool io;        // IO errors
    bool other;    // other errors
};


#endif //DEBUG_EX_DEBUG_H
