#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* 
我们当然可以运用快速排序或者归并排序来实现
归并排序已经在21，148实现过了，在此不再赘述
我们这里用快速排序和快速选择两种方式（类似的思想来解决问题）
*/

// 修改副本和修改原始的引用是有区别的！！

void quickSort(vector<int>& nums, int low, int high){
    if (low < high){
        int pivot = nums[low];
        int lt = low;   // 小于 pivot 区域的右边界
        int gt = high;  // 大于 pivot 区域的左边界
        int i = low + 1;
    // 多一个指针，lt 跟 i的区别可以拉开一段区间，该区间内元素是相等的
    // 实际上我们最后关注的是lt和gt指针的位置，中间是相等的区间，我们不用去管排序
    while (i <= gt) {
        if (nums[i] < pivot) {
            std::swap(nums[i], nums[lt]);
            ++lt;
            ++i;
        } else if (nums[i] > pivot) {
            std::swap(nums[i], nums[gt]);
            --gt;
        } else {
            ++i;
        }
    }
        quickSort(nums, low, lt-1);
        quickSort(nums, gt+1, high);
    }
    
}

int quickSelect(vector<int> nums, int k, int low, int high){
    // quickSelect和quickSort的主要区别在于我们根据index，可以只要关心 k 可能所在的区间
    if (low < high){
        int pivot = nums[low];
        int lt = low;   // 小于 pivot 区域的右边界
        int gt = high;  // 大于 pivot 区域的左边界
        int i = low + 1;
    
        while (i <= gt) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[lt]);
                ++lt;
                ++i;
            } 
            else if (nums[i] > pivot) {
                std::swap(nums[i], nums[gt]);
                --gt;
            } 
            else {
            ++i;
            }
        }
        // cout << lt << gt << endl;
        if (gt+1==k){
            return nums[gt+1];
        }
        else if(lt-1==k){
            return nums[lt-1];
        }
        else if(k<gt+1 && k>lt-1){
            return nums[gt];
        }
        else if(k<lt-1){
            return quickSelect(nums, k, low, lt-1);
        }   
        else if(k>gt+1){
            return quickSelect(nums, k-gt-1, gt+1, high);
        }
    }
}

priority_queue<int> KthLargest_heap(vector<int>& nums, int k){
    priority_queue<int> heap;
    for (int num : nums){
        heap.push(-num); // priority_queue is a max-heap by default
        if (heap.size() > k){
            heap.pop();
        }
    }
    return heap;
}

int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 5;
    // quickSort(nums, 0, nums.size()-1);
    cout << quickSelect(nums, k-1, 0, nums.size()-1) << endl;
    // solution using heap(priority_queue)
    priority_queue<int> heap = KthLargest_heap(nums, k);
    cout << -heap.top() << endl;
}