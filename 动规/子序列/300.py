'''
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
'''
def lengthOfLIS(nums: list) -> int:
    if(len(nums) == 0): return 0
    dp = [1]*(len(nums))
    max_len = 1
    for i in range(1,len(nums)):
        for j in range(0,i):
            if(nums[i] > nums[j]):
                dp[i]= max(dp[i],dp[j]+1)
        max_len = max(max_len,dp[i])
    return max_len

print(lengthOfLIS([10,9,2,5,3,7,101,18]))
print(lengthOfLIS([7,7,7,7,7]))


