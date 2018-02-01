/*
 * decltype.cpp
 * Copyright (C) 2018 Nemanja Micovic <nmicovic@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>

// Computing the return type using decltype.
// Using auto for function return type is cpp11 thing, it tells to
// the compiler that we shall give the return type of function after
// argument list.
template <typename Container, typename Index>
auto authAndIndexV1(Container& c, Index i) -> decltype(c[i])
{
    // authenticateUser();
    return c[i];
}

// We can also do this (remove '-> decltype(c[i])') which cpp14 let's us do
// as it can deduce the type of auto automatically.
// Problem arrises with code like this:
// std::vector<int> vs{1, 2, 3};
// authAndIndexWrong(vs, 2) = 10; // auto is deduced to int not int& so
// code won't compile.
template <typename Container, typename Index>
auto authAndIndexWrong(Container& c, Index i)
{
    // authenticateUser();
    return c[i];
}

// To fix the problem, we can do the following construction.
// decltype(auto) means:
//  - auto -> automatically deduce the type
//  - decltype -> use decltype rules during deduction
template <typename Container, typename Index>
decltype(auto) authAndIndexV2(Container& c, Index i)
{
    // authenticateUser();
    // Now whatever type function returns, compiler will deduce to it
    // because of the decltype(auto).
    // Here it means int& rather then int as in previous function.
    return c[i];
}

template <typename Container, typename Index>
decltype(auto) authAndIndexV3(Container&& c, Index i)
{
    // authenticateUser();
    return std::forward<Container>(c)[i];
}

int main(void)
{
    int x = 20;

    // We declare the variable 'y' of type as same as variable 'x'.
    decltype(x) y = 30;

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::vector<int> vs{1, 2, 3};
    std::cout << "authAndIndexV1: " << authAndIndexV1(vs, 1) << std::endl;
    // authAndIndexWrong(vs, 1) = 99;  // error: expression is not assignable
    std::cout << "authAndIndexV2: " << authAndIndexV2(vs, 1) << std::endl;

    // Doesn't compile:
    // decltype.cpp:40:16: note: candidate function [with Container = std::vector<int, std::allocator<int> >,
    //      Index = int] not viable: expects an l-value for 1st argument
    // decltype(auto) authAndIndexV2(Container& c, Index i)
    //                                          ^
    // authAndIndexV1(std::vector<int>{1, 2, 3, 4, 5}, 3) = 2;
     //authAndIndexV2(std::vector<int>{1, 2, 3, 4, 5}, 3) = 2;
    return 0;
}


