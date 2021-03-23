'''
缺失的第一个正数

题目：
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
'''
# 使用置换的方法，将给定的数组「恢复」成下面的形式：

# 如果数组中包含 x∈[1,N]，那么恢复后，数组的第 x−1 个元素为 x。

# 在恢复后，数组应当有 [1, 2, ..., N] 的形式，但其中有若干个位置上的数是错误的，每一个错误的位置就代表了一个缺失的正数。以题目中的示例二 [3, 4, -1, 1] 为例，恢复后的数组应当为 [1, -1, 3, 4]，我们就可以知道缺失的数为 2。

def firstMissingPositive(nums: list) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(n):
            if(nums[i]!=i+1):
                return i+1
        return n+1

print(firstMissingPositive([1,2,0]))

# 我们对数组进行遍历，对于遍历到的数 x，如果它在 [1,N] 的范围内，那么就将数组中的第 x−1 个位置（注意：数组下标从 0 开始）打上「标记」。
# 在遍历结束之后，如果所有的位置都被打上了标记，那么答案是 N+1，否则答案是最小的没有打上标记的位置加 1。

def firstMissingPositive_2(nums: list) -> int:
    n = len(nums)
    for i in range(n):
        if(nums[i]<=0):
            nums[i] = n+1
    for i in range(n):
        num = abs(nums[i])
        if(num<=n):
            nums[num-1] = -abs(nums[num-1])
    for i in range(n):
        if(nums[i] >0):
            return i+1
    return n+1

