#include <string>
#include <iostream>
using std::string; 
using std::cout;
using std::cin;
using std::endl;

int main()
{   
    const string s = "Keep out!";
    for (auto &c : s) 
        {
        cout << typeid(c).name() << endl;
        cout << typeid(s).name() << endl;
        }   
}