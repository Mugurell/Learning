#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>


int main() {
    std::vector<int> v1{1,3,5   ,6,6,6,   8,   33, 67};
    std::vector<int> v2{   2,      6,    8,8,  33, 88};
    // Must have enough space to hold all elements of the two vectors
    // ELSE will get a segfault in merge.
    std::vector<int> results(v1.size() + v2.size());

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), results.begin());

    std::set<int> allElem(results.begin(), results.end());

    for (auto each : allElem) {
        std::cout << "Next dupe: " << each << "\n";
    }

    return 0;

}
