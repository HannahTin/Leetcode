'''
移除重复节点

题目描述：
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
输入：[1, 2, 3, 3, 2, 1]
输出：[1, 2, 3]

输入：[1, 1, 1, 1, 2]
输出：[1, 2]

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。

如果不得使用临时缓冲区，该怎么解决？
链接： https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
'''
#  注意审题，未排序链表
class ListNode:
    def __init__(self, x):
         self.val = x
         self.next = None

def removeDuplicateNodes(head: ListNode) -> ListNode:
    # 使用临时缓冲区：哈希表res。时间复杂度为o(n),空间复杂度也为o(n).
    # 如果不得使用临时缓冲区，该怎么解决？  那就只能暴力遍历解决了，时间复杂度为o(n^2),空间复杂度也为o(1)。只能以时间换空间了。如下为暴力解法。
    '''
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeDuplicateNodes(ListNode* head) {
    if(head==NULL) return head;
    ListNode* p = head;//第一层循环的指针
    ListNode* pz; //第二层循环移动指针
    while(p!=NULL){
        pz=p;
        while(pz->next!=NULL){
            if(pz->next->val == p->val) {
                p->next = p->next->next;
                pz = p.next;
            }
            else
                pz=pz->next;

        }
        p=p->next;
    }
    '''
    if not head: return head
    p = head
    res = {p.val}
    while(p.next):
        curr = p.next
        if (curr.val not in res):
            res.add(curr.val)
            p=p.next
        else:
            p.next=p.next.next
    return head

node6 = ListNode(1)
node6.next=None
node5 = ListNode(2)
node5.next=node6
node4 = ListNode(3)
node4.next=node5
node3 = ListNode(3)
node3.next=node4
node2 = ListNode(2)
node2.next=node3
head = ListNode(1)
head.next=node2
head = removeDuplicateNodes(head)
p=head
while(p!=None):
    print(p.val)
    p=p.next
        


