#include <string>
#include <vector>
#include <iostream>
#include "Chapter7.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    Screen myScreen(5,5,'X');
    myScreen.display(cout);
    cout << "\n";
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.some_member();
}