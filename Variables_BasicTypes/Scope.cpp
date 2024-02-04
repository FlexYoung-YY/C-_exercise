#include <iostream>
// Program for illustration purposes only: It is bad style for a function
// to use a global variable and also define a local variable with the same name
int reused = 42; // reused has global scope
int main()
{   
    //example 1:
    int unique = 0; // unique has block scope
    // output #1: uses global reused; prints 42 0
    std::cout << reused << " " << unique << std::endl;
    int reused = 0; // new, local object named reused hides global reused
    // output #2: uses local reused; prints 0 0
    std::cout << reused << " " << unique << std::endl;
    // output #3: explicitly requests the global reused; prints 42 0
    std::cout << ::reused << " " << unique << std::endl;
    
    //example 2:
    int i = 100, sum = 0;
    
    for (int i = 0; i != 10; ++i)
        sum += i; // i here is in for-statement scope, so sum will be 45 after for-loop
    std::cout << i << " " << sum << std::endl; // i here is out of for-loop scope, use the definition int i = 100
    
    return 0;
}