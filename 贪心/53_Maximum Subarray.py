'''
53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
'''
import sys
# 暴力:lc 会超时
class Solution:
    def maxSubArray(self, nums: list) -> int:
        ans = 0
        res = -sys.maxsize-1
        for i in range(len(nums)):
            ans  = 0
            for j in range(i,len(nums)):
                ans += nums[j]
                res = max(res,ans)
     
# 贪心
# 局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。

# 全局最优：选取最大“连续和”

# 局部最优的情况下，并记录最大的“连续和”，可以推出全局最优。
class Solution:
    def maxSubArray(self, nums: list) -> int:
        n = len(nums)
        ans = 0
        res = -sys.maxsize-1
        for i in range(n):
            ans += nums[i]
            res = max(res,ans)
            if(ans<0):
                ans =0
        return res

#分治
