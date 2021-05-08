'''
最长递增子序列

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
'''
# dp[i]表示i之前包括i的最长上升子序列。时间复杂度：O(n^2) 空间复杂度：O(n)
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
# 贪心+二分 时间复杂度：O(nlogn)；空间复杂度：O(n)
class Solution:
    def lengthOfLIS(self, nums: list) -> int:
        d = []
        for n in nums:
            if not d or n > d[-1]:
                d.append(n)
            else:
                l, r = 0, len(d) - 1
                loc = r
                while l <= r:
                    mid = (l + r) // 2
                    if d[mid] >= n:
                        loc = mid
                        r = mid - 1
                    else:
                        l = mid + 1
                d[loc] = n
        return len(d)



