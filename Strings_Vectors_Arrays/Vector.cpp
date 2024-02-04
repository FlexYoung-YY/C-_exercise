#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9};
    vector<int> v1{1,2,3,4,5,6,7};
    vector<int> v2{0,2,3,4,5,6,7,8};
    vector<int> v3{0,2,3,4,5,6,7,8,9};
    for (auto &i : v) // for each element in v (note: i is a reference)
        i *= i; // square the element value
    for (auto i : v) // for each element in v
        cout << i << " "; // print the element
        cout << endl;
    cout << (v > v1) << endl;
    cout << (v > v2) << endl;
    cout << (v > v3) << endl;
    cout << (v1 < v2) << endl;
}
