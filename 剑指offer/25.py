'''
合并两个排序的链表

题目描述：
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
'''
#  最先想到的就是归并,下面是归并的想法。
# 其次还可以把两个链表的值保存在一个数组中进行排序，然后再构建新的链表  
# 时间复杂度为O(n),空间复杂度为O(1)
class ListNode:
     def __init__(self, x):
        self.val = x
        self.next = None
def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    if not l1 and not l2:return None
    curr = new_head = ListNode(0)
    while(l1 and l2):
        if l1.val <= l2.val:
            curr.next = l1
            l1 = l1.next
        elif(l1.val > l2.val):
            curr.next = l2
            l2 = l2.next
        curr = curr.next
    curr.next = l1 if l1 else l2
    return new_head.next

        


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