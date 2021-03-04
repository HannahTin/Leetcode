# 题目：（右）旋转链表
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head==None or head.next==None:
            return head
        n=0
        point=head
        while point.next:
            n+=1
            point=point.next
        point.next=head
        m=n+1-k%(n+1)
        for index in range(0,m):
            point=point.next
        result=point.next
        point.next=None
        return result
'''
解题思路:
先遍历整个链表获得链表长度n，然后此时把链表头和尾链接起来，在往后走n+1-k%(n+1)个节点就到达新链表的头结点前一个点，这时断开链表即可。
'''
