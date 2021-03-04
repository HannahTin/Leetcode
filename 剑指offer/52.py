'''
两个链表的第一个公共节点

题目描述：
输入两个链表，找出它们的第一个公共节点。
'''
# 以下代码实现的解法思路是，1）得到两个相交链表的长度，分别记为 len1, len2, 假设 len1 > len2；
# 2）p1指向链表1的头节点, p2指向链表2的头节点；
# 3）p1先移动 len1 - len2的距离；
# 4）之后p1和p2同时移动, 并比较两个指针指向的节点是否相同, 如果相同,则说明两个链表相交, 返回该节点. 如果不相同, 继续移动, 直到链表结尾, 说明两个链表不相交；
# 还有一种解法思路是先遍历第一个链表到他的尾部，然后将尾部的next指针指向第二个链表(尾部指针的next本来指向的是null)。这样两个链表就合成了一个链表，判断原来的两个链表是否相交也就转变成了判断新的链表是否有环的问题了：即判断单链表是否有环。
def getIntersectionNode(headA: ListNode, headB: ListNode) -> ListNode:
    if not(headA and  headB): return None
    lenA = lenB = 0
    p = headA
    q = headB
    while(headA):
        lenA += 1
        headA = headA.next
    
    while(headB):
        lenB += 1
        headB = headB.next
    
    if lenA>lenB:
        for i in range(0,lenA-lenB):
            p = p.next
    elif lenB>lenA:
        for i in range(0,lenB-lenA):
            q = q.next
    else:
        pass
    while(p):
        if(p == q): 
            return True
            break
        p = p.next
        q = q.next   
    return None


   



