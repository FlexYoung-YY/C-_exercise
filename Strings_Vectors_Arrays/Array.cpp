#include <vector>
#include <string>
#include <iostream>
#include <cstddef>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int (*p)[4] = ia;
    p = &ia[2];
    cout << (*p)[3] << endl;
}
