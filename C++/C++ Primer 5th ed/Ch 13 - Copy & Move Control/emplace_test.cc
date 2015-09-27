#include <iostream>
#include <vector>
#include <algorithm>


// Remember that emplace always constructs elements !!!
// by contrast to 
// "the library containers copy initialize their elements when we initialize 
// the container, or when we call an insert or push member" - CPP Primer 5th.

int main()
{
    std::vector<int> vec = {1,2,3,4,5};

    std::cout << "\nSo we have a nice vector:\n\t";
    std::for_each(vec.cbegin(), vec.cend(),
                  [](int nr) { std::cout << nr << ' '; });

    std::cout << "\n\nIf we emplace emplace_back 77 we'd have:\n\t";
    vec.emplace_back(77);
    std::for_each(vec.begin(), vec.end(),
                  [] (const int &nr) { std::cout << nr << ' '; });

    std::cout << "\n\nAnd if we emplace(vec.end, 99) we'd get:\n\t";
    std::vector< int >::iterator it = vec.emplace(vec.end(), 99);
    for (const int & nr : vec)
        std::cout << nr << ' ';

    std::cout << "\nWith an iterator to " << *it << "\n\n";
    return 0;
}
