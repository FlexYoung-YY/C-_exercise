#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

// 876. Middle of the Linked List
ListNode* findMid(ListNode* head){
    //for (int i = 0; i < nums.size(); i++) // for 循环实现方便吗？
    ListNode* mid = head;
    ListNode* end = head;
    ListNode* temp = head;
    // 区别：.next 用于直接访问对象的成员；->用于通过指针访问对象的成员
    // .操作符左边期望是一个对象；->操作符左边期望是一个指针。 
    // !!! 在检查 end->next 之前，最好先检查 end 是否为 NULL，以防止 end 为 NULL 时访问 end->next 导致未定义行为。
    while (end!=NULL && end->next!=NULL){
        temp = mid;
        mid = mid->next;    
        end = end->next->next;
        // cout << mid << endl; 指针所指向的地址
        // cout << &mid << endl; 指针本身的地址
    };
    
    return temp;
}
ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummyHead(-100);
        ListNode* ptr = &dummyHead;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;

        return dummyHead.next;
}

ListNode* mergeSort(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head; // 空链表或只有一个节点，已经有序
    }
    ListNode* mid = findMid(head);
    ListNode* secondHalf = mid->next;
    mid->next = nullptr;
    cout << mid->val << endl;
    ListNode* sortedFirst = mergeSort(head);
    ListNode* sortedSecond = mergeSort(secondHalf);

    return merge(sortedFirst, sortedSecond);
}
int main()
{   
    vector<int> nums = {-1,5,3,4,0};
    //生成ListNode!!!
    ListNode* head = createLinkedList(nums);
    
    head = mergeSort(head);
    return 0;
}
    


