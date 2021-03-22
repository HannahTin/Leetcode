'''
连续子数组的最大和

题目描述：
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。
'''
# 看到求最值应该会想到动态规划做法。
# dp[i]中i表示数组的第i项，dp[i]表示以第i个数字结尾的子数组的最大值。
#  递归公式为：dp[i] = dp[i-1] + nums[i] (i != 0 and if dp[i-1] >0)
#                  = nums[i] (i=0 or  if dp[i-1]<=0)
# 初始化： dp[0] = nums[0]
#  遍历顺序：从前往后遍历

import sys
def maxSubArray(nums: list) -> int:
    if not nums: return 0
    dp = [0]*(len(nums))
    dp[0] = nums[0]
    max_sum = dp[0]
    for i in range(1,len(nums)):
        if(dp[i-1]<=0):
            dp[i] = nums[i]
        else:
            dp[i] = dp[i-1] + nums[i]
        if(dp[i]>max_sum): max_sum = dp[i]
    return max_sum

print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4])) # 6
print(maxSubArray([-1])) # -1
print(maxSubArray([-1,-2])) # -1