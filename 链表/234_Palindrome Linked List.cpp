/**
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
**/

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// 思路：将链表后半部分反转，然后与前半段比较是否回文，最后把后半段再反转回去。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* slow= head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newStart = reverseList(slow);
        ListNode* firstEnd = slow;
        ListNode* p1 = head;
        ListNode* p2 = newStart;
        bool res = true;
        while(p2){
            if(p1->val != p2->val) {
                res = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        reverseList(newStart);
        return res;
    }
};