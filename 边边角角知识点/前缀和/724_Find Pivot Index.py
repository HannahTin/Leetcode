'''
724. 寻找数组的中心下标
给你一个整数数组 nums，请编写一个能够返回数组 “中心下标” 的方法。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心下标，返回 -1 。如果数组有多个中心下标，应该返回最靠近左边的那一个。

注意：中心下标可能出现在数组的两端。
'''
# 时间复杂度为O（N），空间复杂度为O（N）
class Solution:
    def pivotIndex(self, nums: list) -> int:
        presum = [0]*(len(nums)+1) # 保留前缀和数组
        for i in range(len(nums)):
            presum[i+1] = presum[i] + nums[i]
        for i in range(1,len(nums)+1): # 注意边界
            if(presum[i-1] == presum[-1] -presum[i]):
                return i-1
        return -1