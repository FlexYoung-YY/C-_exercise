#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

// recursive way
// time O(n+m); space O(n+m) due to calling the function recursively

ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode head;
    //如果指针为非空指针，则被判断为true
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val){
        // 可以通过recursive tree来想象。
        // 其实相当于从底层向上实现。
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else {
        list2->next = merge(list2->next, list1);
        return list2;
    }
}

int main(){
    vector<int> nums_1 = {1,2,4};
    vector<int> nums_2 = {1,3,4};
    //生成ListNode!!!
    ListNode* list_1 = createLinkedList(nums_1);
    ListNode* list_2 = createLinkedList(nums_2);
    ListNode* sortedList = merge(list_1, list_2);
    while (sortedList){
        cout << sortedList->val << endl;
        sortedList = sortedList->next;
    }
    /* iterative way
    ListNode head(-101);
    ListNode* sortedList = &head;
    while (list_1&&list_2){
        if (list_1->val < list_2->val){
            sortedList->next = list_1;
            list_1 = list_1->next;
        }
        else {
            sortedList->next = list_2;
            list_2 = list_2->next;
        }
        sortedList = sortedList->next;
        cout << sortedList->val << endl;
    }
    */
}