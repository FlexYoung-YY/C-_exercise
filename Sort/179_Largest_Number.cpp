#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums = {3,30,34,5,9};
    sort(nums.begin(), nums.end(), [](int a, int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a); // 返回为true表示第一个参数在第二个参数之前。
    });
    sort(nums.begin(), nums.end());
    string ans = "";
    for (auto i : nums){
        ans += to_string(i);
    }
    cout << ans << endl;
    return 0;
}