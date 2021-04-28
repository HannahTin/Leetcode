'''
974. 和可被 K 整除的子数组
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
'''
# 思路：仍然是采用前缀和的思路，哈希表中保存的是余数的个数
class Solution:
    def subarraysDivByK(self, A: list, K: int) -> int:
        dic = {0:1}
        presum = 0
        res  = 0
        for i in range(len(A)):
            presum += A[i]
            key = (presum % K + K) % K  # presum 为负数时，需要对其纠正
            if key in dic:
                res+=dic[key]
            dic[key]=dic.setdefault(key,0)+1
        return res

