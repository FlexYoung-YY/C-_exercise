#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums  = {0,1,2,2,3,0,4,2};
    int val = 2;
    
    /* 简单地使用erase和remove实现
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    */
    
    /* 双指针，i遍历整个vector，如果不等于val，就记录到j位置上，并将j位置往后挪（i为遍历指针，j为位置指针）
    int j = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] != val){
            nums[j] = nums[i];
            j++;
        }    
    }
    */
    int i = 0;
    int n = nums.size();
    while (i < n){
        if (nums[i] == val){
            nums[i] = nums[n-1]; // reduce array size by one，把最后一位的数字挪上来
            n--; // 由于这里i没有变，下个循环继续check现在换上来的i位置的值是否为val，此外n--减少一位必然为val的值。
        }
        else i++;
    }

    /*
    
    */

    vector<int>::iterator it = nums.begin();
    while (it!=nums.end()){
        
        ++it; //先递增，在使用递增后的迭代器
        // it++; //先使用原始的迭代器，然后再增加
        cout << *it << endl; // 不同之处在于cout的时候用*(++it)还是*(it++)
    }
    return 0;
}