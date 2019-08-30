# 题目：两数相加
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

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
                break;   
                
            tempList.next=ListNode(0)
            tempList=tempList.next
        return result
   '''
   解题思路：
   单链表的创建和修改，注意判断进位的特殊情况
   '''
