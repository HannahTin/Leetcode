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
