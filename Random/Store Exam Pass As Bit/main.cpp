#include <iostream>
#include <initializer_list>


unsigned long pass_exam(std::initializer_list<int>);
void check_pass(unsigned long);


int main()
{

    // un unsigned long are 4 bytes aici -> maxim 32 grades
    // notele vor fi cuprinse intre [1 - 32]
    // (x >= 0 folosit in for-ul din check_pass() ar fi fost invins de overflow)
    unsigned long grades = pass_exam({2,5,7,9,4,3,2,23,23,5,64,2,45,6,5,12,25});
    check_pass(grades);
    
    return 0;    
}


unsigned long
pass_exam(std::initializer_list<int> list)
{
    unsigned long grades = 0;
    for (auto each : list) 
        grades |= 1UL << each;    
        
    return grades;
}

void 
check_pass(unsigned long list)
{
    for (short unsigned x = sizeof list * 8; x > 0; x--)
    {
        std::cout << "\nStudent #" << x;
        unsigned long check = 1;
        if ( list & check << x )
            std::cout << " has passed the exam!";
        else
            std::cout << " hasn't passed the exam!";
    }
}