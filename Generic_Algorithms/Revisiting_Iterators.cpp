#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

int main(){
    vector<int> vec;
    istream_iterator<int> in_iter(cin); // read ints from cin
    istream_iterator<int> eof; // istream ''end'' iterator
    // 不同于以下用while的方式进行存储
    // cout << accumulate(in_iter, eof, 0) << endl;
    while (in_iter != eof) // while there's valid input to read
    // postfix increment reads the stream and returns the old value of the iterator
    // we dereference that iterator to get the previous value read from the stream
        vec.push_back(*in_iter++);
    vector<int>::iterator it;
    it = vec.begin();
    while (it != vec.end())
    {   
        cout << *it << " ";
        it++;
    }
    cout << endl;    
    

}