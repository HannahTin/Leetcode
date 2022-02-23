/**
92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
**/
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 把待反转的部分分离出来反转，再接到原链表中。
// 时间复杂度：O(N)，其中 N 是链表总节点数。最坏情况下，需要遍历整个链表。
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = pre;
            pre=curr;
            curr = next;
        }
        return pre;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
        // 建议写在 for 循环里，语义清晰
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        // 第 3 步：切断出一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        // 注意：切断链接
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 第 4 步：同第 206 题，反转链表的子区间
        reverseList(leftNode);

        // 第 5 步：接回到原来的链表中
        pre->next = reverseList(leftNode);
        leftNode->next = curr;
        return dummyNode->next;
    }
};
// 方法一的缺点是：如果 left 和 right 的区域很大，恰好是链表的头节点和尾节点时，找到 left 和 right 需要遍历一次，
// 反转它们之间的链表还需要遍历一次，虽然总的时间复杂度为O(N)，但遍历了链表  2 次，可不可以只遍历一次呢？答案是可以的。
// 下面是头插法
// 下面我们具体解释如何实现。使用三个指针变量 pre、curr、next 来记录反转的过程中需要的变量，它们的意义如下：

// curr：指向待反转区域的第一个节点 left；
// next：永远指向 curr 的下一个节点，循环过程中，curr 变化以后 next 会变化；
// pre：永远指向待反转区域的第一个节点 left 的前一个节点，在循环过程中不变。
// 先将 curr 的下一个节点记录为 next；
// 执行操作 ①：把 curr 的下一个节点指向 next 的下一个节点；
// 执行操作 ②：把 next 的下一个节点指向 pre 的下一个节点；
// 执行操作 ③：把 pre 的下一个节点指向 next。
class Solution2 {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyNode->next;
    }
};