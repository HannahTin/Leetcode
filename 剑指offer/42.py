'''
连续子数组的最大和

题目描述：
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。
'''
# 从数组的第一个数字开始进行累加，如果累加和小于0，则之前的累加和抛弃重新开始进行累加，否则就保存最大的累加和与后面的累加和进行比较和替换。
import sys
def maxSubArray(nums: list) -> int:
    if not nums: return 0
    currSum = 0 
    maxSum = -sys.maxsize -1
    for i in range(len(nums)):
        if(currSum <=0):
            currSum = nums[i]
        else:
            currSum += nums[i]
        if(currSum > maxSum):
            maxSum = currSum
    return maxSum


print(maxSubArray([1,-2,3,10,-4,7,2,-5])) # 18

