#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    // sort(nums.begin(), nums.end());
    // 三指针交换排序
    vector<int>::iterator ptr1 = nums.begin();
    vector<int>::iterator ptr2 = nums.end() - 1;
    vector<int>::iterator current = nums.begin();
    while (current <= ptr2){
        if (*current==1){
            swap(*current, *ptr1);
            ptr1++;
        }
        else if (*current==0){
            swap(*current, *ptr2);
            ptr2--;
        }
        else {current++;}
    }
    for (auto i : nums){
        cout << i << " ";
    }
    return 0;
}