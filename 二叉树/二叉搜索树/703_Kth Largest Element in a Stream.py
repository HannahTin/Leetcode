'''
数据流中的第 K 大元素
设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
'''
import heapq
# 维护一个小根堆
# 时间复杂度：
# 初始化时间复杂度为：O(nlogk) ，其中 n 为初始化时 nums 的长度；

# 单次插入时间复杂度为：O(logk)。

# 空间复杂度：O(k)。需要使用优先队列存储前 k 大的元素

class KthLargest:

    def __init__(self, k: int, nums: list):
        self.k=k
        self.hp = [num for num in nums[:k]] # k个数入堆
        heapq.heapify(self.hp)
        for i in range(self.k,len(nums)):
            heapq.heappush(self.hp,nums[i])
            heapq.heappop(self.hp)

    def add(self, val: int) -> int:
        heapq.heappush(self.hp,val)
        if len(self.hp) > self.k:
            heapq.heappop(self.hp)
        return self.hp[0]
        



# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)