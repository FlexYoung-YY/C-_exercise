#include <iostream>
#include <vector>
#include "Linked_List.h"

using namespace std;



int main()
{   
    vector<int> nums = {1,2,3,4,5,6,7,8};
    //生成ListNode!!!
    ListNode* head = createLinkedList(nums);
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* even_head = head->next;
    /*
    ListNode* curr = head;
    while (curr!=nullptr && curr->next!=nullptr){  
        odd->next = curr->next->next;
        if (curr->next == nullptr){
            even->next = nullptr;
        }
        else even->next = curr->next->next;
        
        if (odd->next!=nullptr){
            odd = odd->next;
        }
        if (even->next!=nullptr){
            even = even->next;
        }
        curr = curr->next;
    }
    */

    // more simple way
    while (even!=nullptr && even->next!=nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    while (head!=nullptr){
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}