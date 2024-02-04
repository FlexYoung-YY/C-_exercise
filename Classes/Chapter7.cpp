#include <iostream>
#include "Chapter7.h"
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
//必须放在另一个CPP文件里；如果放在头文件里，则必须为inline（内联函数）
//r若既非内联函数，也没有放在另一个CPP文件里，则会报错multiple definition。
void Screen::some_member() const
{   
    cout << access_ctr << endl;
    ++access_ctr; // keep a count of the calls to any member function
    cout << access_ctr << endl;
}

/*void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = string(s.height * s.width, ' ');
}

// return type is seen before we're in the scope of Window_mgr
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}*/