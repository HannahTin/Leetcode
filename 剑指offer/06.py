'''
从尾到头打印链表

题目描述：
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
'''

def reversePrint(head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        if head== None: return[]
        p = head
        res = [head.val]
        while(p!=None and p.next!=None):
            p = p.next
            res.append(p.val)
        res.reverse()
        return res
