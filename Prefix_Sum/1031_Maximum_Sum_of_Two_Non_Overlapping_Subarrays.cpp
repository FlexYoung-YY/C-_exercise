#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {0,6,5,2,2,5,1,9,4};
    int firstLen = 1;
    int secondLen = 2;
    int n = nums.size();
    //vector<int> leftSum(n-firstLen-secondLen, 0);
    //vector<int> rightSum(n-firstLen-secondLen, 0);
    int firstSum_1 = 0;
    int secondSum_1 = 0;
    int firstSum_2 = 0;
    int secondSum_2 = 0;
    
    for (int i = 0; i < firstLen; i++){
        firstSum_1 += nums[i];
    }


    for (int i = secondLen; i < secondLen + firstLen; i++){
        firstSum_2 += nums[i];
    }

    for (int i = 0; i < secondLen; i++){
        secondSum_2 += nums[i];
    }


    int sum_1 = 0;
    int sum_2 = 0;
    int currentSum = 0;
    int totalSum = 0;
    // firstLen in first
    for (int i = 0; i < n - secondLen - firstLen + 1; i++){
        secondSum_1 = 0;
        for (int j = firstLen + i; j < firstLen + secondLen + i; j++){
            secondSum_1 += nums[j];
        }
        int currentSum = 0;
        sum_1 = secondSum_1 + firstSum_1;
        cout << "first: " << firstSum_1 << "; second: " << secondSum_1 << endl;
        for (int j = firstLen + i; j < n - secondLen; j++){   
            secondSum_1 = secondSum_1 - nums[j] + nums[j + secondLen];
            currentSum = firstSum_1 + secondSum_1;
            sum_1 = max(currentSum, sum_1);
            cout << "Second:" << secondSum_1 << endl;

        }
        firstSum_1 = firstSum_1 - nums[i] + nums[i + firstLen];
        totalSum = max(totalSum, sum_1);
    }
    // 然后再来一遍 secondLen 在前的情况
    // 时间复杂度在LeetCode上为最佳？？？
    cout << totalSum << endl;

}

