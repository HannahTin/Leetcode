/**
K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
**/

//  Definition for singly-linked list.
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* slow = nullptr;
            ListNode* fast = nullptr;
            ListNode* newhead = new ListNode();
            ListNode* curr=newhead;
            while(head){
                slow = head;
                fast = head;
                int count =k;
                while(count>1 && fast->next){
                    fast = fast->next;
                    count--;
                }
                if(count==1) {
                    head = fast->next;
                    fast->next = nullptr;
                    curr->next = reverseList(slow);
                    curr = slow;
                }
                else {
                    curr->next = slow;
                    return newhead->next;
                    }
                
            }
            curr->next = head;
            return newhead->next;


    }
};