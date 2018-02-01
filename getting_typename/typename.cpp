/*
 * typename.cpp
 * Copyright (C) 2018 Nemanja Micovic <nmicovic@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <boost/type_index.hpp>

template <typename T>
void f(const T& param)
{
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    // show T
    // with_cvr -> with const, volatile and reference
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << '\n';
    // show param type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n\n";
}


int main(void)
{
    f(10);
    f("pera");
    f(2.3);
    f('s');

    f([] (int x) { x++; });

    int x = 99;
    f([x] (int y) { return x + y; });

    return 0;
}


