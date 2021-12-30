/**
给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lMSNwu
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//  先分别反转两个链表，再逐位相加，最后将结果链表反转
class Solution {
public:
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        else if(l2==nullptr) return l1;
        ListNode* p1 = reverseList(l1);
        ListNode* p2 = reverseList(l2);
        int temp =0;
        ListNode* res=new ListNode(0);
        ListNode* curr = res;
        while(true){
            if(p1){
                temp +=p1->val;
                p1=p1->next; 
            }
            if(p2){
                temp +=p2->val;
                p2 =p2->next;
            }
            curr->val = temp%10;
            temp /= 10;
            if(p1==nullptr && p2==nullptr && temp ==0) break;
            curr->next = new ListNode(0);
            curr = curr->next;


        }
        return reverseList(res);
        

    }
};