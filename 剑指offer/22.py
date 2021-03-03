'''
链表中倒数第k个节点

题目描述：输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
# 总结：第一时间想到的解法：
# 先遍历统计链表长度，记为 n ；
# 设置一个指针走 (n-k)步，即可找到链表倒数第 k个节点。
# 使用双指针则可以不用统计链表长度。

class ListNode:
    def __init__(self,x):
        self.x = x
        self.next =None

def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
    if not head or k==0 : return None # 输入指针为空指针或k=0
    first = head
    last = head
    for _ in range(k):
        if last.next != None: 
            last = last.next
        else:
            return None # 如果节点总数少于k
    while(last):
        last=last.next
        first = first.next
    return first


