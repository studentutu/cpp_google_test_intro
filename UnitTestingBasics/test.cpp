#include "gtest/gtest.h"

#include "../TestCasesSolutions/TestCasesHeader.h"

TEST(TestTemplate, TestName)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


TEST(ActualTest, Test1)
{
    std::vector<int> test1{1, 3, 6, 4, 1, 2};
    int solution1 = TestCasesClass::solution_find_min_not_in_list_positive_opt(test1);
    EXPECT_EQ(solution1, 5);
}

TEST(ActualTest, Test2)
{
    std::vector<int> test1{1, 2, 3};
    int solution1 = TestCasesClass::solution_find_min_not_in_list_positive_opt(test1);
    EXPECT_EQ(solution1, 4);
}

TEST(ActualTest, Test3)
{
    std::vector<int> test1{-1, -3};
    int solution1 = TestCasesClass::solution_find_min_not_in_list_positive_opt(test1);
    EXPECT_EQ(solution1, 1);
}


TEST(ActualTestUbisoft, Test1)
{
    std::string test = "aaBabcDaA";

    std::string solution1 = TestCasesClass::solution_find_next(test);
    std::cout << solution1;
    bool isTrue = solution1 == "B";
    EXPECT_EQ(isTrue, true);
}

TEST(ActualTestUbisoft, Test2)
{
    std::string test = "Codility";
    std::string solution1 = TestCasesClass::solution_find_next(test);
    std::cout << solution1;

    bool isTrue = solution1 == "NO";
    EXPECT_EQ(isTrue, true);
}

TEST(ActualTestUbisoft, Test3)
{
    std::string test = "WeTestCodErs";
    std::string solution1 = TestCasesClass::solution_find_next(test);
    std::cout << solution1;

    bool isTrue = solution1 == "T";
    EXPECT_EQ(isTrue, true);
}

TEST(ActualTestUbisoft, Test11)
{
    std::vector<int> test{1, 8, 7, 3, 4, 1, 8};
    int solution1 = TestCasesClass::ubisoft_task_four(test);
    EXPECT_EQ(solution1, 3);
}

TEST(ActualTestUbisoft, Test12)
{
    std::vector<int> test{5, 5, 5, 7, 7, 7};
    int solution1 = TestCasesClass::ubisoft_task_four(test);
    EXPECT_EQ(solution1, 2);
}

TEST(ActualTestUbisoft, Test13)
{
    std::vector<int> test{6, 10, 1, 4, 3};
    int solution1 = TestCasesClass::ubisoft_task_four(test);
    EXPECT_EQ(solution1, 4);
}

TEST(ActualTestUbisoft, Test14)
{
    std::vector<int> test{4, 1, 5, 4};
    int solution1 = TestCasesClass::ubisoft_task_four(test);
    EXPECT_EQ(solution1, 3);
}

TEST(ActualTestUbisoft, Test21)
{
    std::string stringToCheck = "abccbd";
    std::vector<int> test{0, 1, 2, 3, 4, 5};
    int solution1 = TestCasesClass::ubisoft_task_five(stringToCheck, test);
    EXPECT_EQ(solution1, 2);
}

TEST(ActualTestUbisoft, Test22)
{
    std::string stringToCheck = "aabbcc";
    std::vector<int> test{1, 2, 1, 2, 1, 2};
    int solution1 = TestCasesClass::ubisoft_task_five(stringToCheck, test);
    EXPECT_EQ(solution1, 3);
}

TEST(ActualTestUbisoft, Test23)
{
    std::string stringToCheck = "aaaa";
    std::vector<int> test{3, 4, 5, 6};
    int solution1 = TestCasesClass::ubisoft_task_five(stringToCheck, test);
    EXPECT_EQ(solution1, 12);
}

TEST(ActualTestUbisoft, Test24)
{
    std::string stringToCheck = "ababa";
    std::vector<int> test{10, 5, 10, 5, 10};
    int solution1 = TestCasesClass::ubisoft_task_five(stringToCheck, test);
    EXPECT_EQ(solution1, 0);
}

TEST(ActualTestUbisoft, Test25)
{
    std::string stringToCheck = "aaaa";
    std::vector<int> test{5, 2, 3, 3};
    int solution1 = TestCasesClass::ubisoft_task_five_opt(stringToCheck, test);
    EXPECT_EQ(solution1, 8);
}