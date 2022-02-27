/*
剑指 Offer II 021. 删除链表的倒数第 n 个结点
给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        ListNode* pre = dummy;
        dummy->next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n){
            fast = fast->next;
            n--;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
            pre = pre->next;
        }
        pre->next = slow->next;
        return dummy->next;
    }
};