#include <iostream>
int main()
{   
    int ival = 42;
    int ival_1 = 10;
    int *p = &ival;
    std::cout << "example 1: " << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "ival: " << ival << std::endl;
    std::cout << "&ival: " << &ival << std::endl;
    std::cout << "ival_1: " << ival_1 << std::endl;
    std::cout << "&ival_1: " << &ival_1 << std::endl;

    p = &ival_1; // value in p is changed; p now is points to ival_1
    std::cout << "example 2: " << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "ival: " << ival << std::endl;
    std::cout << "&ival: " << &ival << std::endl;
    std::cout << "ival_1: " << ival_1 << std::endl;
    std::cout << "&ival_1: " << &ival_1 << std::endl;

    *p = ival; // value in ival_1 is changed and address is unchanged; p unchanged 
    std::cout << "example 3: " << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "ival: " << ival << std::endl;
    std::cout << "&ival: " << &ival << std::endl;
    std::cout << "ival_1: " << ival_1 << std::endl;
    std::cout << "&ival_1: " << &ival_1 << std::endl;

    int *p1 = &ival;
    std::cout << (p1 == p) << std::endl; // be careful, we are comparing pointer or value of pointer?
    
    int **pp = &p;
    std::cout << "example 4: " << std::endl;
    std::cout << "p: " << p << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "&p: " << &p << std::endl;
    std::cout << "pp: " << pp << std::endl;
    std::cout << "*pp: " << *pp << std::endl;    
    std::cout << "ival_1: " << ival_1 << std::endl;
    std::cout << "&ival_1: " << &ival_1 << std::endl;

}