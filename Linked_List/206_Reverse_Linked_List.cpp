#include <iostream>
#include <vector>
#include "Linked_List.h"

using namespace std;

ListNode* reverse_list(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head; // 空链表或只有一个节点
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr!=nullptr){
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    };
    return prev;
}

// recursive way
ListNode* reverse_list_recursive(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* p = reverse_list_recursive(head->next); // 重要的是在rucursive过程中，确定第一步时，head的位置。
    head->next->next = head;
    head->next = nullptr;
    return p;
}

int main()
{   
    vector<int> nums = {1,2,3,4,5,6};
    //生成ListNode!!!
    ListNode* head = createLinkedList(nums);
    head = reverse_list(head);
    while (head!=nullptr){
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}