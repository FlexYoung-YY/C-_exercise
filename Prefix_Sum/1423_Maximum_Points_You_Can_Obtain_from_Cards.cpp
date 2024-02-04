#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {100, 40, 17, 9, 73, 75};
    int k = 3;
    /*vector<int> leftsum(k+1, 0);
    vector<int> rightsum(k+1, 0);
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i <= k; i++){
        leftsum[i+1] = leftsum[i] + nums[i];
        rightsum[i+1] = rightsum[i] + nums[nums.size()-i-1];
    }
    
    for (int i = 0; i <= k; i++){
        sum = leftsum[i] + rightsum[k-i];
        max_sum = max(sum, max_sum);
        cout << leftsum[i] << rightsum[k-i] << endl;
    }
    cout << max_sum << endl;
    */
    int total = 0;
    
        
    for (int i: nums){
        total += i;
    }
    int min_sum = total;
    //双循环实现sliding window可以，但不优。
    //具体可见OneNote
    for (int i = 0; i <= k; i++){
        int sum = 0;
        for (int n = i; n < nums.size() - k + i; n++){
            sum += nums[n];
        }
        min_sum = min(min_sum, sum);
        cout << min_sum << endl;
    }

}

