#include <iostream>
#include <vector>
#include "Linked_List.h"

using namespace std;


int main()
{   
    vector<int> nums = {1,2,3,4,5};
    int left = 2;
    int right = 4;
    ListNode* head = createLinkedList(nums);
    ListNode* curr = head;
    ListNode* prev = nullptr;
    // iterative way
    
    /*
    while (left > 1){
        prev = curr;
        curr = curr->next;
        left--;
        right--;
    }
    ListNode* con = prev;
    ListNode* tail = curr;

    while (right > 0){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        right--;
    }
    con->next = prev;
    tail->next = curr;
    */

    while (head->next!=nullptr){
        cout << head->val << endl;
        head = head->next;
    }
    cout << head->val << endl;
    return 0;
}