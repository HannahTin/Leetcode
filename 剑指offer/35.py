'''
复杂链表的复制

题目描述：
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
# 时间复杂度 O(N)： 两轮遍历链表，使用 O(N) 时间。
'''
def copyRandomList(head: 'Node') -> 'Node':
    if not head: return
    dic = {}
    # 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
    cur = head
    while cur:
        dic[cur] = Node(cur.val)
        cur = cur.next
    cur = head
    # 4. 构建新节点的 next 和 random 指向
    while cur:
        dic[cur].next = dic.get(cur.next)
        dic[cur].random = dic.get(cur.random)
        cur = cur.next
    # 5. 返回新链表的头节点
    return dic[head]


'''
# 方法二：拼接+拆分
# 时间复杂度 O(N) ： 三轮遍历链表，使用 O(N) 时间。
# 空间复杂度 O(1) ： 节点引用变量使用常数大小的额外空间。
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        curr = head
        # 1. 复制各节点，并构建拼接链表
        while curr:
            node = Node(curr.val)
            node.next = curr.next
            curr.next = node
            curr = node.next
        # 2. 构建各新节点的 random 指向
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
        # 3. 拆分两链表
        old = head
        new_head = new= head.next
        while new.next:
            old.next = old.next.next
            new.next = new.next.next
            old = old.next
            new = new.next
        old.next = None
        return new_head
   



