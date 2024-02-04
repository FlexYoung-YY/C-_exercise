#include <iostream>

int main(){
    /*
    bool b = 42; // b is true
    int i = b; // i has value 1
    i = 3.14; // i has value 3
    double pi = i; // pi has value 3.0
    unsigned char c = -1; // assuming 8-bit chars, c has value 255
    signed char c2 = 256; // assuming 8-bit chars, the value of c2 is undefined
    */
    
    /*
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    std::cout << i - u2 << std::endl;
    std::cout << u2 - i << std::endl;
    */

    //std::cout << i << std::endl;
    extern double pi;
    pi = 3.14;

    return 0;
}
