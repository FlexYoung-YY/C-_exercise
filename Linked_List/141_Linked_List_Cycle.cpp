#include <iostream>
#include <vector>
#include "Linked_List.h"
#include <unordered_set>

using namespace std;

int main()
{   
    vector<int> nums = {3,2,0,4};
    //生成ListNode!!!
    ListNode* head = createCycledLinkedList(nums, 2);
    ListNode* head =createLinkedList(nums);
    if (head==nullptr or head->next==nullptr){
            cout << "false" << endl;
        }
    /*
    // using hash set

    unordered_set<ListNode*> Node_set;
    while (Node_set.find(head)==Node_set.end() && head!=nullptr){
        Node_set.insert(head);
        cout << head->val << endl;
        head = head->next;
    }
    cout << head->val << endl;
    */
    
    // using two pointers
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (slow!=fast){
        if (fast==nullptr || fast->next ==nullptr){
            cout << "false" << endl;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << fast->val << endl;
    
    /*
    while (headA!=nullptr){
        cout << headA->val << endl;
        headA = headA->next;
    }
    */
    return 0;
}