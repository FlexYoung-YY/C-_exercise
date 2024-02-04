#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int>& A, int i, bool mustPick) {
		// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if(i >= A.size()) return mustPick ? 0 : -1e5;       
        if(mustPick)
            return max(0, A[i] + solve(A, i+1, true));                  // either stop here or choose current element and recurse
        return max(solve(A, i+1, false), A[i] + solve(A, i+1, true));   // try both choosing current element or not choosing
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = INT_MIN;
    int currentSum = 0;
    int first_element = 0;
    int last_element = 0;
    // 最简单的版本，只需要得出最大值是多少，我们并不关心是哪一段subarray，因此需要更新maxSum和currentSum    
    for (int i = 0; i < nums.size(); i++) 
    {
        currentSum += nums[i];
            
        if (currentSum > maxSum) 
        {
            maxSum = currentSum;
            last_element = i; // 记录subarray的结尾
        }
            
        if (currentSum < 0)
        {
            currentSum = 0;
            first_element = i + 1; // 更新新的subarray的开头
        }   
    }
    maxSum = solve(nums, 0, false);
    cout << maxSum << endl;
    cout << "[" <<first_element << "," << last_element << "]" << endl;
    
}

