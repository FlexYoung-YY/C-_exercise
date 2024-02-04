#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

vector<vector<int>> merge(vector<vector<int>> left, vector<vector<int>> right){
    vector<vector<int>> sorted;
    vector<vector<int>>::iterator ptr1 = left.begin();
    vector<vector<int>>::iterator ptr2 = right.begin();
    // cout << (*ptr1)[0] << endl;
    while (ptr1!=left.end()&& ptr2!=right.end()){
        if ((*ptr1)[0] < (*ptr2)[0]){
            sorted.push_back(*ptr1);
            ++ptr1;
        }
        else if ((*ptr1)[0] > (*ptr2)[0]){
            sorted.push_back(*ptr2);
            ++ptr2;
        }
        else {
            if ((*ptr1)[1] < (*ptr2)[1]){
                sorted.push_back(*ptr1);
                ++ptr1;
            }
            else if ((*ptr1)[1] > (*ptr2)[1]){
                sorted.push_back(*ptr2);
                ++ptr2;
            }
        }
    }
    if (ptr1==left.end()){
        while(ptr2!=right.end()){
            sorted.push_back(*ptr2);
            ++ptr2;
        }
        return sorted;
    }
    if (ptr2==right.end()){
        while(ptr1!=left.end()){
            sorted.push_back(*ptr1);
            ++ptr1;
        }
        return sorted;
    }
    return sorted;
}
    
vector<vector<int>> mergeSort(vector<vector<int>> intervals){
    if (intervals.size() <= 1){
        return intervals; // 在vector中少于1个interval，相当于已经排列好了
    }
    int mid_idx = intervals.size() / 2;
    vector<vector<int>> left(intervals.begin(), intervals.begin() + mid_idx); 
    vector<vector<int>> right(intervals.begin() + mid_idx, intervals.end());

    vector<vector<int>> sortedleft = mergeSort(left);
    vector<vector<int>> sortedright = mergeSort(right);

    return merge(sortedleft, sortedright); 
}

int main()
{   
    vector<vector<int>> intervals = {{8,10},{2,6},{1,3},{15,18}};
    vector<vector<int>> sortedintervals = mergeSort(intervals);
    vector<vector<int>>::iterator it = sortedintervals.begin();
    /*
    while(it!=sortedintervals.end()-1){
        if ((*it)[1] >= (*(it+1))[0]){
            (*it)[1] = (*(it+1))[1]; 
            sortedintervals.erase(it+1);
        }
        ++it;
        
    }
    */
    vector<vector<int>> merged;
    for (auto interval : sortedintervals) {
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, simply append it.
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        // otherwise, there is overlap, so we merge the current and previous
        // intervals.
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    cout << merged.size() << endl;
    return 0;
}
    


