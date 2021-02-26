'''
删除链表的节点

题目描述：
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。
'''
#  注意python和c++中对节点类的定义。
'''
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteNode(head: ListNode, val: int) -> ListNode:
        if not head: return None
        if(head.val==val):return head.next
        p = head
        while(p.next!=None and p.next.val!=val): 
            p = p.next
        if p.next!=None:# 如果是空指针，直接返回head，若非空，执行删除操作（覆盖目标节点）
            p.next=p.next.next
        return head