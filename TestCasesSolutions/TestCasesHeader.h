#pragma once
#include <algorithm>
#include <set>
#include <vector>

class TestCasesClass
{
public :
    /**
     * \brief Find the first positive number (minimum) that is not is list
     */
    int static solution_find_min_not_in_list_positive(std::vector<int>& parameters_int_as_vector)
    {
        int result = 1;
        // write your code in C++14 (g++ 6.2.0)
        std::sort(parameters_int_as_vector.begin(), parameters_int_as_vector.end());

        for (const auto& element : parameters_int_as_vector)
        {
            if (element < 0)
            {
                continue;
            }
            if (element == result)
            {
                result = element + 1;
            }
        }
        return result;
    }

    int static solution_find_min_not_in_list_positive_opt(std::vector<int>& parameters_int_as_vector)
    {
        // int result = 1;
        // int previous = -1;
        // bool all_negatives_checked = false;
        // write your code in C++14 (g++ 6.2.0)
        std::sort(parameters_int_as_vector.begin(), parameters_int_as_vector.end());
        for (const auto& element : parameters_int_as_vector)
        {
            if (element < 0)
            {
                continue;
            }
            bool isValueFound = std::find(
                    parameters_int_as_vector.begin(),
                    parameters_int_as_vector.end(),
                    element + 1)
                != parameters_int_as_vector.end();

            if (!isValueFound)
            {
                return element + 1;
            }
        }
        return std::max(parameters_int_as_vector.back() + 1, 1);
    }


    /**
     * \brief Ubisoft c++ challenge
     */
    std::string static solution_find_next(std::string& to_check)
    {
        std::set<char> check_lower_case;
        std::set<char> check_upper_case;

        for (const auto& char_To_Check : to_check)
        {
            if (std::islower(char_To_Check))
            {
                check_lower_case.insert(char_To_Check);
            }
            else
            {
                check_upper_case.insert(char_To_Check);
            }
        }
        std::vector<char> check_unions_only;
        std::set<char> check_lower_case_to_upper;
        for (auto& ch : check_lower_case)
        {
            check_lower_case_to_upper.insert(std::toupper(ch));
        }
        std::set_intersection(
            check_lower_case_to_upper.begin(),
            check_lower_case_to_upper.end(),
            check_upper_case.begin(),
            check_upper_case.end(),
            std::back_inserter(check_unions_only));

        if (check_unions_only.size() == 0)
        {
            return "NO";
        }

        char resultFrom = *std::max_element(check_unions_only.begin(), check_unions_only.end());

        return std::string{resultFrom};
    }


    /**
    * \brief Ubisoft c++ challenge
    */
    int static ubisoft_task_four(std::vector<int>& to_check_vector)
    {
        std::set<int> set(to_check_vector.begin(), to_check_vector.end());
        int prev_value = -1;
        int max_diff = 1;
        int difference = 0;
        for (const auto& value : set)
        {
            if (prev_value != -1)
            {
                difference = std::abs(value - prev_value);
                if (difference > max_diff)
                {
                    max_diff = difference;
                }
            }
            prev_value = value;
        }

        return max_diff;
    }

    int static ubisoft_task_five(std::string& string_to_check, std::vector<int>& to_check_vector)
    {
        char previous_item = '0';
        int summ_deletions = 0;
        std::set<int> already_deleted;
        for (size_t i = 0; i < string_to_check.size(); ++i)
        {
            if (previous_item != '0')
            {
                if (string_to_check.at(i) == previous_item)
                {
                    int price_of_left = to_check_vector[i - 1];
                    int price_of_right = to_check_vector[i];
                    bool check_min_left = price_of_right > price_of_left;
                    summ_deletions += check_min_left ? price_of_left : price_of_right;

                    already_deleted.insert(check_min_left ? (i - 1) : i);
                }
            }
            previous_item = string_to_check.at(i);
        }
        return summ_deletions;
    }

    int static ubisoft_task_five_opt(std::string& string_to_check, std::vector<int>& to_check_vector)
    {
        std::vector<std::pair<char, int>> all_pairs;
        for (size_t i = 0; i < string_to_check.length(); ++i)
        {
            all_pairs.push_back(
                std::make_pair<char&, int&>(string_to_check[i], to_check_vector[i])
            );
        }
        int total_price_of_deleted_letters = 0;
        for (size_t i = 0; i < all_pairs.size() - 1; i++)
        {
            auto current_element = all_pairs.at(i);
            auto next_element = all_pairs.at(i + 1);

            // Is the same letter?
            if (current_element.first == next_element.first)
            {
                // Compare prices and select cheapest
                int index_of_cheapest_element;
                auto cheapest_element = current_element;
                if (current_element.second < next_element.second)
                {
                    cheapest_element = current_element;
                    index_of_cheapest_element = i;
                }
                else
                {
                    cheapest_element = next_element;
                    index_of_cheapest_element = i + 1;
                }

                total_price_of_deleted_letters += cheapest_element.second;
                all_pairs.erase(all_pairs.begin() + index_of_cheapest_element);
                i--;
            }
        }
        return total_price_of_deleted_letters;
    }
};