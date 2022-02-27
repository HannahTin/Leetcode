'''
移除链表元素

题目描述：
删除链表中等于给定值 val 的所有节点。
'''
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeElements(head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        '''
        # 设置虚拟头节点
        dummyhead = ListNode(0)
        dummyhead.next = head
        curr = dummyhead
        while(curr.next):
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return dummyhead.next
        '''
        # 直接删除
        while(head!=None and head.val==val):
            head = head.next
        curr = head
        while(curr and curr.next): # 注意判断head不是none
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return head

# 输入: 1->2->6->3->4->5->6, val = 6
# 输出: 1->2->3->4->5
head = None
for i in range(6,0,-1):
    head = ListNode(i,head)
head = removeElements(head, 6)
while(head != None):
    print(head.val)
    head = head.next


