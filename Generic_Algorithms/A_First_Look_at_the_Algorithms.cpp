#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
bool isShorter(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }

int main()
{   
    vector<int> vi = {27, 210, 12, 47, 109, 83, 109};
    vector<int> vi_1 = {27, 210, 12, 47, 109, 83, 10};
    // string val = "a value";
    int val = 109;
    auto result = std::find(vi.cbegin(), vi.cend()-1, val); // return is a const iterator. if not find, it will return the last element in the range
    cout << "find value: " << *result << endl;
    
    auto result_1 = std::count(vi.cbegin(), vi.cend(), val); // type: ptrdiff_t
    cout << "cout: " << result_1 << endl;

    auto sum = std::accumulate(vi.cbegin(), vi.cend(), 0); // starting the summation with value 0
    cout << "sum: " << sum << endl;

    auto result_2 = std::equal(vi.cbegin(), vi.cend(), vi_1.cbegin());
    cout << "equal or not: " << result_2 << endl;

    auto result_3 = std::equal(vi.cbegin(), vi.cend()-1, vi_1.cbegin());
    cout << "equal or not: " << result_3 << endl;

    vector<int>::iterator it;
    fill(vi_1.begin(), vi_1.end(), 0);
    it = vi_1.begin();
    cout << "reset(fill): ";
    while (it != vi_1.end())
    {   
        cout << *it << ",";
        it++;
    }
    cout << endl;

    fill_n(vi_1.begin(), vi_1.size(), 1);
        it = vi_1.begin();
    cout << "reset(fill_n): ";
    while (it != vi_1.end())
    {   
        cout << *it << ",";
        it++;
    }
    cout << endl;

    fill_n(vi_1.begin(), 3, 2);
    it = vi_1.begin();
    cout << "reset(fill_n, some digit): ";
    while (it != vi_1.end())
    {   
        cout << *it << ",";
        it++;
    }
    cout << endl;

    fill_n(std::back_inserter(vi_1), 4, 3);
    it = vi_1.begin();
    cout << "reset(fill_n, back_inserter): ";
    while (it != vi_1.end())
    {   
        cout << *it << ",";
        it++;
    }
    cout << endl;

    std::replace(vi_1.begin(), vi_1.end(), 1, 42);
    it = vi_1.begin();
    cout << "replace: ";
    while (it != vi_1.end())
    {   
        cout << *it << ",";
        it++;
    }
    cout << endl;

    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)]; // a2 has the same size as a1
    // ret points just past the last element copied into a2
    auto ret = std::copy(std::begin(a1), std::end(a1), a2); // copy a1 into a2
    
    vector<string>::iterator it_1;
    vector<string> words = {"jumps", "over", "quick", "red", "slow", "the", "turtle", "fox"};
    vector<string> words_1 = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the" , "turtle"};
    cout << "before sort: ";
    it_1 = words.begin();
    while (it_1 != words.end())
    {
        cout << *it_1 << ",";
        it_1++;
    }
    cout << endl;
    
    sort(words.begin(), words.end());
    it_1 = words.begin();
    cout << "after sort: ";
    while (it_1 != words.end())
    {
        cout << *it_1 << ",";
        it_1++;
    }
    cout << endl;

        cout << "before unique: ";
    it_1 = words_1.begin();
    while (it_1 != words_1.end())
    {
        cout << *it_1 << ",";
        it_1++;
    }
    cout << endl;
    
    auto end_unique = unique(words_1.begin(), words_1.end()); // iterator to the end of unique words
    it_1 = words_1.begin();
    cout << "after unique: ";
    while (it_1 != words_1.end())
    {
        cout << *it_1 << ",";
        it_1++;
    }
    cout << endl;



    stable_sort(words.begin(), words.end(), isShorter); // isShorter是一个自定义的函数。
    it_1 = words.begin();
    cout << "after stable_sort with isShorter: ";
    while (it_1 != words.end())
    {
        cout << *it_1 << ",";
        it_1++;
    }
    cout << endl;

    sort(words.begin(), words.end(), isShorter); // isShorter是一个自定义的函数。
    it_1 = words.begin();
    cout << "after sort with isShorter: ";
    while (it_1 != words.end())
    {
        cout << *it_1 << ",";
        it_1++;
    }
    cout << endl;
}