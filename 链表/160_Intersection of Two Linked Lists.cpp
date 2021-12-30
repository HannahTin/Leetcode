/**
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
**/
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};
// 时间复杂度O（m+n），空间复杂度O（1）
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* pheadA = headA;
        ListNode* pheadB = headB;
        while(pheadA!=pheadB){
            pheadA = pheadA==nullptr?headB:pheadA->next;
            pheadB = pheadB==nullptr?headA:pheadB->next;
        }
        return pheadB;
        
    }
};