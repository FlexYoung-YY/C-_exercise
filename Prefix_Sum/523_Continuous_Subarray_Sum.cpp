#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> nums = {23,2,6,4,7};
    int k = 6;
    int n = nums.size();
    int sum = 0;

    /* 时间复杂度有点高 O（n^2）    
    for (int i = 2; i <= n; i++){
        sum = 0;
        for (int j = 0; j < i; j++){
            sum += nums[j];
        }
        if (sum % k == 0){
            cout << "true" << endl;
            cout << sum << endl;
        }
        for (int j = 0; j < n - i; j++){
            sum = sum - nums[j] + nums[j+i];
            if (sum % k == 0){
                cout << "true" << endl;
                cout << sum << endl;
            }
        }
    }
    */
    
    // 利用mod的特性，如果一个数组在增长的过程中，两个mod值相同，那么说明中间的数组是可以被整除的
    map<int, int> result;
    result[0] = -1; // 防止出现前n个元素和正好是a good subarray的情况。
    for (int i = 0; i < n; i++){
        sum += nums[i];
        if (result.count(sum % k) && i - result[sum % k] > 1){
            cout << "true" << endl;
            cout << i << result [sum % k] << endl;
        }
        if (!result.count(sum % k)){
            result[sum % k] = i;
        }
    }
}

