/*
 * runtime.array.size.cpp
 * Copyright (C) 2018 Nemanja Micovic <nmicovic@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <array>

// Motivation behind this template is to deduce the number of elements
// that array is allowed to take.
// We mark it as constexpr in order to have the value available
// during compilation.
//
// Part 'noexcept' is to help compilers generate better code,
// see Meyers book about effective modern cpp.
template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6};

    // Declaring a new array of length as same as 'nums'.
    // Do note that size of nums2 is calculated during compliation
    // as 'arraySize' is an constexpr.
    int nums2[arraySize(nums)];

    // Naturally we would prefer std::array rather then regular arrays, so...
    std::array<int, arraySize(nums)> nums3;

    std::cout << "Array size of nums: " << arraySize(nums) << std::endl;
    std::cout << "Array size of nums2: " << arraySize(nums2) << std::endl;
    std::cout << "Array size of nums3: " << nums3.size() << std::endl;

    return 0;
}

