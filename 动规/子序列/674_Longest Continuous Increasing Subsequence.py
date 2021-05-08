'''
674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
'''
# 贪心 时间复杂度：O(n) 空间复杂度：O(1)
class Solution:
    def findLengthOfLCIS(self, nums: list) -> int:
        if(len(nums) == 0): return 0
        res = 1
        count = 1
        for i in range(len(nums)-1):
            if nums[i+1] >nums[i]:
                count +=1
            else: count =1
            res = max(res,count)
        return res
# dp 时间复杂度：O(n) 空间复杂度：O(n)
# dp[i]：以下标i为结尾的数组的连续递增的子序列长度为dp[i]。
def findLengthOfLCIS(self, nums:list) -> int:
    if(len(nums) == 0): return 0
    dp=[1]*len(nums)
    for i in range(0,len(nums)-1):
        if(nums[i+1]>nums[i]):
            dp[i+1] = dp[i]+1
    return max(dp)