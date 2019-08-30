# 题目：合并两个有序链表
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1==None and l2==None:
            return None
        tmp = []
        while l1:
            tmp.append((l1,l1.val))
            l1 = l1.next
        while l2:
            tmp.append((l2,l2.val))
            l2 = l2.next
        tmp.sort(key=lambda tmp: tmp[1]) 
        head_ = point = tmp.pop(0)[0] 
        point.next = None
        while tmp:
            point.next = tmp.pop(0)[0]
            point = point.next
            point.next = None
        return head_
     
'''
解题思路：
简单题，相当于单链表排序。将两个有序链表合并成一个链表再排序即可。
'''
