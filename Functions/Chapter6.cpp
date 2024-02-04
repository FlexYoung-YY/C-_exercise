#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
typedef string::size_type sz;

void reset(int *ip)
{
    *ip = 0; // changes the value of the object to which ip points
    ip = 0; // changes only the local copy of ip; the argument is unchanged
}

void reset(int &i)
{
    i=1; // changes the value of the object to which i refers
}

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size(); // position of the first occurrence, if any
    occurs = 0; // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) 
    {
        if (s[i] == c) 
        {
            if (ret == s.size())
                ret = i; // remember the first occurrence of c
            ++occurs; // increment the occurrence count
        }
    }
    return ret; // count is returned implicitly in occurs
}

bool is_sentence(const string &s)
{
    // if there's a single period at the end of s, then s is a sentence
    string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

// Using a Marker to Specify the Extent of an Array
void print(const char *cp)
{
    if (cp) // if cp is not a null pointer
        while (*cp) // so long as the character it points to is not a null character
            cout << *cp++ << endl; // print the character and advance the pointer
}

//Using the Standard Library Conventions
void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << endl; // print the current element and advance the pointer
}

//Explicitly Passing a Size Parameter
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) 
    {
        cout << ia[i] << endl;
    }
}

// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[10]) // but here is only for an array with 10 integers
{
    for (auto elem : arr)
        cout << elem << endl;
}

// calculate val!, which is 1 * 2 * 3 . . . * val
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}

void screen(sz ht, sz wid, char backgrnd)
{
    cout<< ht << wid << backgrnd << endl;
}