#include <iostream>
#include <vector>

#include "TestCasesHeader.h"

int main(int argc, char* argv[])
{
    std::vector<int> test1{1, 3, 6, 4, 1, 2};
    int solution1 = TestCasesClass::solution_find_min_not_in_list_positive_opt(test1);
    if(solution1 != 5)
    {
        std::cout << "First Test case failed";
        return -1;
    }
    std::vector<int> test2{1, 2, 3};
    int solution2 = TestCasesClass::solution_find_min_not_in_list_positive(test2);
    if(solution2 != 4)
    {
        std::cout << "Second Test case failed";
        return -1;
    }
    std::vector<int> test3{-1, -3};
    int solution3 = TestCasesClass::solution_find_min_not_in_list_positive(test3);
    if(solution3 != 1)
    {
        std::cout << "Third Test case failed";
        return -1;
    }
    return 0;
}