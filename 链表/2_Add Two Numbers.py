'''
题目：两数相加

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
'''
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
'''
解题思路：
单链表的创建和修改，注意判断进位的特殊情况
'''
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0)
        tempList = result
        temp = 0
        
        while True:
            if l1 != None:
                temp=temp+l1.val
                l1=l1.next 
            if l2 != None:
                temp=temp+l2.val
                l2=l2.next
            tempList.val=temp%10 
            temp=int(temp/10)
            if (l1==None and l2==None and temp==0):
                break  
                
            tempList.next=ListNode(0)
            tempList=tempList.next
        return result
 

