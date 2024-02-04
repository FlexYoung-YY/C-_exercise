#ifndef CHAPTER7_H
#define CHAPTER7_H
#include <string>
#include <vector>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;
    // alternative way to declare a type member using a type alias
    // using pos = std::string::size_type;
    
    friend class Window_mgr;
    // Window_mgr::clear must have been declared before class Screen
    // friend void Window_mgr::clear(ScreenIndex);
    
    Screen() = default; // needed because Screen has another constructor
    
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    
    char get() const // get the character at the cursor
        { return contents[cursor]; } // implicitly inline; because it is defined in head file

    inline char get(pos ht, pos wd) const; // explicitly inline; because the inline keyword
    
    Screen &move(pos r, pos c); // can be made inline later

    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
        { do_display(os); return *this; }
    
    const Screen &display(std::ostream &os) const
        { do_display(os); return *this;}
    
    void some_member() const;
private:
    static const int i;
    pos cursor = 0; // 这里的初始化？？？现在也可以了，是三种初始化方式之一。声明时初始化->初始化列表->构造函数初始化
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const
        {os << contents;}
    
    mutable size_t access_ctr; // may change even in a const object

};

class Window_mgr
{
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
    // add a Screen to the window and returns its index
    ScreenIndex addScreen(const Screen&);
private:

    //Screens this Window_mgr is tracking
    // by default, a Window_mgr has one standard sized blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')}; //in-class initializers
};



inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c ; // move cursor to the column within that row
    return *this; // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width; // compute row location
    return contents[row + c]; // return character at the given column
}


inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this; // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch; // set specified location to given value
    return *this; // return this object as an lvalue
}

#endif