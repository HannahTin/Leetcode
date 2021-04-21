'''
382. 链表随机节点
给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？
'''
# 蓄水池抽样证明其实是数学归纳法，具体可参考：https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/
# 先解决只抽取一个元素的问题，这个问题的难点在于，随机选择是「动态」的，比如说你现在你有 5 个元素，你已经随机选取了其中的某个元素 a 作为结果，但是现在再给你一个新元素 b，你应该留着 a 还是将 b 作为结果呢，以什么逻辑选择 a 和 b 呢，怎么证明你的选择方法在概率上是公平的呢？

# 先说结论，当你遇到第 i 个元素时，应该有 1/i 的概率选择该元素，1 - 1/i 的概率保持原有的选择。看代码容易理解这个思路：
import random
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head


    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        curr = self.head
        count = 0
        res = 0
        while curr:
            count += 1
            if(random.randrange(count) == 0):
                res = curr.val
            curr=curr.next
        return res
# 返回链表中k个节点的随机值呢
    def getRandomk(self,k)->list:
            """
            Returns k random nodes' value.
            :rtype: int
            """
            curr = self.head
            res =[]
            # // 前 k 个元素先默认选上
            for index in range(k):
                if curr: 
                    res[index]=curr.val
                    curr = curr.next
            i = k
            # while 循环遍历链表
            while curr: 
                i += 1
                # 生成一个 [0, i) 之间的整数
                # 这个整数小于 k 的概率就是 k/i
                index = random.randrange(i)
                if(index<k):
                    res[index]= curr.val
                curr=curr.next
            return res
