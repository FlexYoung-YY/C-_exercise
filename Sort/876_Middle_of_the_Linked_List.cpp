#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;


int main(){
    vector<int> nums = {-1,5,3,4,0};
    //生成ListNode!!!
    ListNode* head = createLinkedList(nums);
    //for (int i = 0; i < nums.size(); i++) // for 循环实现方便吗？
    ListNode* mid = head;
    ListNode* end = head;
    // 区别：.next 用于直接访问对象的成员；->用于通过指针访问对象的成员
    // .操作符左边期望是一个对象；->操作符左边期望是一个指针。 
    // !!! 在检查 end->next 之前，最好先检查 end 是否为 NULL，以防止 end 为 NULL 时访问 end->next 导致未定义行为。
    while (end!=NULL && end->next!=NULL){
        mid = mid->next;    
        end = end->next->next;
        // cout << mid << endl; 指针所指向的地址
        // cout << &mid << endl; 指针本身的地址
    };
    cout << mid->val << endl;

}