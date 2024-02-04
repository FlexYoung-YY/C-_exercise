#include <iostream>
// 在c++中，先定义function，再在main()中call。
// 可以反过来吗？

void while_func(int val) // define a parameter list
{   /* 
        wihle (condition)
            statement
    */
    int sum = 0, initial=1;
    while (initial <= val) {
        sum += initial; // assigns sum + val to sum
        // std::cout << "Current number is " << initial << std::endl;
        ++initial; // add 1 to initial
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
}

void for_func(int val) 
{   /* 
        for(init-statement; codition; expression)
    */
    int sum = 0;
    for (int initial = 1; initial <= val; ++initial)
        /* Here:
            initial is inside the for; it is not possible to use initial after this loop terminates
        */
        sum += initial; 
        // std::cout << "Current number is " << initial << std::endl;
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
}

void read_inputs_func()
{
    int sum = 0, value = 0;
    while (std::cin >> value) // read until end-of-file, calculating a running total of all values read
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
}

void if_func()
{   /*
    
    */
   int currVal = 0, val =0;
   if (std::cin >> currVal) {
        int cnt = 1; // store the count
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;
                currVal = val; // remenber the new value
                cnt = 1; // reset the counter
            }
        }
        std::cout << currVal << " occures " << cnt << " times " << std::endl;
   }
}

int main()
{
    // while_func(10); // difference between while_func() and while_func()?
    // for_func(11);
    //read_inputs_func();
    if_func();
    return 0;
}



