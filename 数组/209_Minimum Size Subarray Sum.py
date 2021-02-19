"""
长度最小的子数组

题目描述:
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
"""
# 首先最容易想到暴力枚举，但时间复杂度太高，下面的python实现用时挺长，可以换成c++。
# 本题求长度最小的连续子数组，滑动窗口其实也可以理解为双指针法的一种！只不过这种解法更像是一个窗口的移动，所以叫做滑动窗口更适合一些。
# 滑动窗口的精妙之处在于根据当前窗口内子序列的情况，不断调节子序列的起始位置。从而将O(n^2)的暴力解法降为O(n)。
def minSubArrayLen(target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        """
        # 暴力枚举，但时间复杂度为o(n^2),空间复杂度为o(1)
        n = len(nums)
        result = n + 1
        sum = 0 
        for i in range(n):
            for j in range(i,n):
                sum += nums[j]
                if(sum>=target):
                    result = min(result,j-i+1)
                    break
        return 0 if result==n+1 else result
        """
        # 滑动窗口, 时间复杂度为o(n),空间复杂度为o(1)
        n = len(nums)
        result = n + 1
        start = end = 0
        sum = 0
        while(end < n):
            sum += nums[end]
            while(sum >= target): 
                result = min(result,end-start+1)
                sum -= nums[start] # 精髓之处了
                start += 1
            end += 1
        return 0 if result == n+1 else result

print(minSubArrayLen(4, [1,4,4]))   # 期望输出：1
print(minSubArrayLen(7, [2,3,1,2,4,3]))  # 期望输出：2
print(minSubArrayLen(11, [1,1,1,1,1,1,1,1]))  #期望输出：0
