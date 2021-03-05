'''
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
'''
# 解题思路：同样将k个链表的合并在同一个节点数组中，利用数组排序方法进行排序，然后再各节点串联。
# 时间复杂度为O(kn+knlogkn)，空间复杂度为o(kn)
def mergeKLists(lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        nodeList = []
        for i in range(len(lists)):
            currentNode = lists[i]
            #遍历某个链表
            while(currentNode):
                nodeList.append(currentNode)
                currentNode = currentNode.next
                
        #根据node的val对数组进行排序  
        nodeList = sorted(nodeList,key = lambda x:x.val)
        
        #对排序好的数组的元素，一个个地连接成新的链表（这里的tempHead是为了方便设置的头节点）
        tempHead = ListNode(0)
        currentNode = tempHead
        for i in range(len(nodeList)):
            currentNode.next = nodeList[i]
            currentNode = currentNode.next
            
        return tempHead.next

# 解题思路：可以参见合并两个有序链表，数组中的两两归并
# 时间复杂度为O(k^2n),空间复杂度为O(1)
def mergeTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
        if(( not l1) or ( not l2)): return l1 if l1 else l2
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
def mergeKLists(lists: List[ListNode]) -> ListNode:
        ans = None
        for i in range(len(lists)):
             ans = self.mergeTwoLists(ans,lists[i])
        return ans

# 解题思路：可以参见合并两个有序链表，数组中的分治归并
# 另外，还可以设置优先队列保存k个链表的第一个节点
