'''
523. 连续的子数组和
给定一个包含 非负数 的数组和一个目标 整数 k ，
编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n * k ，其中 n 也是一个整数。
'''
# 相比于能被k整除的连续数组，多加了数组长度至少为2的限制
class Solution:
    def checkSubarraySum(self, nums: list, k: int) -> bool:
        if k==0: return False # 要判断k是否为0的情况
        dic = {0:-1} #字典中key为余数 val为第一次出现的索引
        presum = 0
        for i in range(len(nums)):
            presum += nums[i]
            key =  presum % k
            if key in dic:
                if i-dic[key]>=2:
                    return True
                continue
            dic[key]=i
        return False
