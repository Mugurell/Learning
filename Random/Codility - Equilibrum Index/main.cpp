/*******************************************************************************
********************************************************************************
 *
 *  Author:           Lingurar Petru-Mugurel
 *  Written:          26 Sep 2015, 16:22:34:592
 *  Last updated:           ---
 *
 *  Compilation:  g++ -std=c++14 -Wall -Werror -Wextra -pedantic -Wshadow  
 *   (g++ 5.1)        -Woverloaded-virtual -Winvalid-pch -Wcast-align
 *                    -Wformat=2 -Wformat-nonliteral
 *                    -Wmissing-format-attribute -Wmissing-include-dirs  
 *                    -Wredundant-decls -Wswitch-default -Wswitch-enum 
 *
 *  Description:
 *   A zero-indexed array A consisting of N integers is given. An equilibrium
 *  index of this array is any integer P such that 0 ? P < N and the sum of
 *  elements of lower indices is equal to the sum of elements of higher indices,
 *  i.e.
 *      A[0] + A[1] + ... + A[P?1] = A[P+1] + ... + A[N?2] + A[N?1].
 *   Sum of zero elements is assumed to be equal to 0.
 *  This can happen if P = 0 or if P = N?1.
 *
 *   For example, consider the following array A consisting of N = 8 elements:
 *      A[0] = -1
 *      A[1] =  3
 *      A[2] = -4
 *      A[3] =  5
 *      A[4] =  1
 *      A[5] = -6
 *      A[6] =  2
 *      A[7] =  1
 *  P = 1 is an equilibrium index of this array, because:
 *      A[0] = ?1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7
 *  P = 3 is an equilibrium index of this array, because:
 *      A[0] + A[1] + A[2] = ?2 = A[4] + A[5] + A[6] + A[7]
 *  P = 7 is also an equilibrium index, because:
 *      A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0
 *      and there are no elements with indices greater than 7.
 *
 *  P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ? P < N.
 *
 *   Write a function:
 *      int solution(vector<int> &A);
 *  that, given a zero-indexed array A consisting of N integers, returns any of
 *  its equilibrium indices. The function should return ?1 if no equilibrium
 *  index exists.
 *
 *   For example, given array A shown above, the function may return 1, 3 or
 *  7, as explained above.
 *
 *   Assume that:
 *  N is an integer within the range [0..100,000];
 *  each element of array A is an integer within the range
 *      [?2,147,483,648..2,147,483,647].
 *  Complexity:
 *      expected worst-case time complexity is O(N);
 *      expected worst-case space complexity is O(N), beyond input storage
 *          (not counting the storage required for input arguments).
 *  Elements of input arrays can be modified.
 *
 *  Bugs:
 *  --- None ---
 *
 *  TODO:
 *  --- None --- 
 *
 *  Notes:
 *  My score and program analysis - codility.com/demo/results/demoR9AYZF-AAQ/
 *
********************************************************************************
*******************************************************************************/



// you can use includes, for example:
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A) {
    unsigned eq_index = 1;   // 1 is the minimum value so that
    std::vector<int> valid_eq_indexes;

    while (eq_index < A.size())
    {
        if (std::accumulate(A.begin(), A.begin() + eq_index, 0ll) ==
            std::accumulate(A.begin() + eq_index + 1, A.end(), 0ll))
        {
            valid_eq_indexes.emplace_back(eq_index);
        }
        eq_index++;
    }


    if (valid_eq_indexes.size() >= 1)
    {
        srand((unsigned)time(NULL));
        return valid_eq_indexes.at(rand() % int(valid_eq_indexes.size()));
    }
    else
        return -1;
}


int main()
{
    // same values as in the online test
    std::vector<int> randoms{-1, 3, -4, 5, 1, -6, 2, 1};
    srand(unsigned(time(NULL)));

//    for (int i = 0; i < 100; i++)
//        randoms.emplace_back(rand() % 100);

    int equilibrum_index = solution(randoms);
    switch (equilibrum_index) {
    case -1:
        std::cout << "\nAn equilibrum index wasn't found";
        break;
    default:
        std::cout << "\nPossible equilibrum index: " << equilibrum_index;
    }

    return 0;
}

