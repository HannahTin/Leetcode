'''
设计链表

题目描述：
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-linked-list
'''
#  下面用单链表的结构进行实现
class LinkedNode():
    def __init__(x):
        self.val = x
        self.next = None

class MyLinkedList(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.head = LinkedNode(0) # 给一个虚拟头节点


    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        if index <0 or index>=self.size:
            return -1
        curr = self.head
        for _ in range(index+1):
            curr = curr.next
        return curr.val


    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: None
        """
        self.addAtIndex(0,val)


    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: None
        """
        self.addAtIndex(self.size,val)


    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: None
        """
        if index > self.size: return
        if index < 0 : index = 0
        self.size += 1
        pred = self.head
        for _ in range(index):
            pred = pred.next
        to_add = LinkedNode(val)
        to_add.next = pred.next
        pred.next = to_add


    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: None
        """
        if index <0 or  index>= self.size:
            return
        self.size -= 1
        pred = self.head
        for _ in range(index):
            pred = pred.next
        pred.next = pred.next.next

# 双链表实现
class LinkedNode():
    def __init__(x):
        self.val = x
        self.next = None
        self.prev = None
class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 0
        self.head = LinkedNode(0)
        self.tail = LinkedNode(0)
        self.head.next = self.tail
        self.tail.prev = self.head


    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index <0  or index>=self.size: return -1
        if index + 1 < self.size - index:
            curr = self.head
            for _ in range(index+1):
                curr = curr.next
        else:
            curr = self.tail
            for _ in range(self.size - index):
                curr = curr.prev
        return curr.val


    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        pred = self.head
        to_add = LinkedNode(val)
        to_add.next = pred.next
        pred.next.prev = to_add
        to_add.prev = pred
        pred.next = to_add
        self.size += 1


    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        last = self.tail
        to_add = LinkedNode(val)
        to_add.next = last
        to_add.prev = last.prev
        last.prev.next = to_add
        last.prev = to_add
        self.size -= 1


    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index>self.size: return None
        if index < 0: index =0
        to_add = LinkedNode(val)
        if index < self.size-index:
            curr = self.head
            for _ in range(index):
                curr = curr.next
            succ = curr.next
        else: 
            curr = self.tail
            for _ in range(self.size - index):
                curr = curr.prev
            pred = curr.prev

        to_add.prev = pred
        to_add.next = succ
        succ.prev = to_add
        pred.next = to_add
        self.size += 1


    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0  or index>=self.size: return None
        if index < self.size-index:
            curr = self.head
            for _ in range(index):
                curr = curr.next
            succ = curr.next.next
        else: 
            curr = self.tail
            for _ in range(self.size - index):
                curr = curr.prev
            pred = curr.prev
        succ.prev = pred
        pred.next = succ
        self.size -= 1




# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)