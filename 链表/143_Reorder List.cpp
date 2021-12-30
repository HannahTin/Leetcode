/**
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

输入：head = [1,2,3,4]
输出：[1,4,2,3]
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 思路：先将链表后半段反转，最后合并
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* SecondStart = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* p1 = head;
        ListNode* p2 = SecondStart;
        while(p2){
            ListNode* p1_temp = p1->next;
            ListNode* p2_temp = p2->next;
            p1->next = p2;
            p1 = p1_temp;
            p2->next = p1;
            p2 = p2_temp;

        }

    }
};