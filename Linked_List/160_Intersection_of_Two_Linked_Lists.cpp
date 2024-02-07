#include <iostream>
#include <vector>
#include "Linked_List.h"
#include <unordered_set>

using namespace std;


int main()
{   
    vector<int> nums = {5,6,1,8,4,5};
    //生成ListNode!!!
    ListNode* headA = createLinkedList(nums);
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(1);
    headB->next->next = headA->next->next->next;

    // using hash set
    /*
    unordered_set<ListNode*> Node_set;
    while (headA){
        Node_set.insert(headA);
        headA = headA->next;
    }
    while (headB){
        if (Node_set.find(headB) != Node_set.end()){
            cout << headB->val << endl;
            break;
        }
        else headB = headB->next;
    }
    */
    
    // using two pointers
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (p1!=p2){
        p1 = p1 == nullptr ? headB : p1->next;
        p2 = p2 == nullptr ? headA : p2->next;
    }
    if(p1!=nullptr){
        cout << p1->val << endl;
    }
    /*
    while (headA!=nullptr){
        cout << headA->val << endl;
        headA = headA->next;
    }
    */
    return 0;
}