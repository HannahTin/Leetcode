'''
560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
'''
#思路：前缀和的思想是这样的——对于给定的数组nums，我们额外开辟一个数组presums:preSum[i] 就是 nums[0..i-1] 的和。
# 那么如果我们想求 nums[i..j] 的和，只需要一步操作 preSum[j+1]-preSum[i] 即可，而不需要重新去遍历数组了。
# 下面注释中的解法是O（N^2）,空间复杂度为O(N)
'''
int subarraySum(int[] nums, int k) {
    int n = nums.length;
    // 构造前缀和
    int[] sum = new int[n + 1];
    sum[0] = 0; 
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + nums[i];
    
    int ans = 0;
    // 穷举所有子数组
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            // sum of nums[j..i-1]
            if (sum[i] - sum[j] == k)
                ans++;

    return ans;
}
'''
# 时间复杂度为O(N)，空间复杂度为O(1)
# 本题需要优化前缀和+hashmap
class Solution:
    def subarraySum(self, nums: list, k: int) -> int:
        dic = {0:1}
        presum = 0
        res  = 0
        for i in range(len(nums)):
            presum += nums[i]
            if presum - k in dic:
                res+=dic[presum-k]
            dic[presum]=dic.setdefault(presum,0)+1
        return res

