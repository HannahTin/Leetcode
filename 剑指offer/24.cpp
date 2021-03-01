/*
反转链表

题目描述：
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}

    
};
// 迭代做法，时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表一次。空间复杂度：O(1)。

ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    
int main() {
    ListNode *node5, *node4, *node3, *node2, *head;
    node5 = new ListNode(2);
    node4 = new ListNode(3);
    node3 = new ListNode(3);
    node2 = new ListNode(2);
    head = new ListNode(1);
    head->next = node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    head = reverseList(head);
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}
    
        
