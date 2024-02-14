#include "Linked_List.h"
#include <vector>

ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        
        if (head == nullptr) {
            // 如果是链表的第一个节点
            head = newNode;
            current = newNode;
        } else {
            // 否则，将新节点连接到链表尾部
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

ListNode* createCycledLinkedList(const std::vector<int>& values, int cyclePos) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        
        if (head == nullptr) {
            // 如果是链表的第一个节点
            head = newNode;
            current = newNode;
        } else {
            // 否则，将新节点连接到链表尾部
            current->next = newNode;
            current = newNode;
        }
    }
    ListNode* cycleNode = head;
    for (int i = 0; i < cyclePos; ++i){
        cycleNode = cycleNode->next;
    }
    current->next = cycleNode;
    return head;
}