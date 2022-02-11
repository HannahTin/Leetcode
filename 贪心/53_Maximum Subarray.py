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