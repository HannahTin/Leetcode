'''
统计「优美子数组」

题目描述：
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
# 同样采用前缀和技巧，哈希表中保存的是奇数的个数。
class Solution:
    def numberOfSubarrays(self, nums: list, k: int) -> int:
        dic ={0:1}
        oddnum = 0
        res = 0
        for i in range(len(nums)):
            oddnum += nums[i]&1
            if oddnum-k in dic:
                res += dic[oddnum-k]
            dic[oddnum] = dic.setdefault(oddnum,0)+1
        return res
