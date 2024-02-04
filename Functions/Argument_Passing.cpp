#include <iostream>
#include "Chapter6.h" 

using std::cout;
using std::endl;
using std::cin;
using std::end;
using std::begin;

int main(){
    int i = 42;
    int j = 42;
    reset(&i);
    reset(j);
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    
    // const Paramters and Arguments
    const int ci1 = 42; // we cannot change ci; const is top-level
    int i1 = ci1; // ok: when we copy ci, its top-level const is ignored
    int * const p = &i1; // const is top-level; we can't assign to p
    *p = 0; // ok: changes through p are allowed; i is now 0

    int i2 = 42;
    const int ci2 = i2;
    string::size_type ctr = 0;
    reset(&i2); // calls the version of reset that has an int* parameter
    // reset(&ci); // error: can't initialize an int* from a pointer to a const int object, the initialization happends inside the funcion in Chapter6.cpp
    reset(i2); // calls the version of reset that has an int& parameter
    // reset(ci); // error: can't bind a plain reference to the const object ci
    // reset(42); // error: can't bind a plain reference to a literal
    // reset(ctr); // error: types don't match; ctr has an unsigned type
    // find_char("Hello World!", 'o', ctr); // ok: find_char's first parameter is a reference to const, but failed at compile time.
    // But find_char is used in is_senetece().
    cout << is_sentence("Hello World.") << endl;
    int j3[] = {5, 6};
    char j4[] = {'7', '8'};
    print(j4);
    print(begin(j3), end(j3));
    print(j3, end(j3) - begin(j3));
    screen();
    screen(66);
}