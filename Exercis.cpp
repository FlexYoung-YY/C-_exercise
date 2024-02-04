#include <iostream>
#include <typeinfo>
#include "Sales_data.h"

int main()
{   
    Sales_data data1;
    int i = 0;
    const int ci = i, &cr = ci;
    auto d = &i;
    auto e = &ci;
    auto &n = i;
    auto *p2 = &ci;
    std::cout << std::is_const<decltype(n)>::value << std::endl;
    std::cout << typeid(n).name() << std::endl;
}