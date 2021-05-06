/**
494. 目标和
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。
**/
using namespace std;
#include<vector>
// 思路：如何转化为01背包问题呢。
// 假设加法的总和为x，那么减法对应的总和就是sum - x。
// 所以我们要求的是 x - (sum - x) = S
// x = (S + sum) / 2
// 此时问题就转化为，装满容量为x背包，有几种方法。
// 大家看到(S + sum) / 2 应该担心计算的过程中向下取整有没有影响。
// 这么担心就对了，例如sum 是5，S是2的话其实就是无解的，所以：if ((S + sum) % 2 == 1) return 0; // 此时没有方案
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (target > sum) return 0; // 此时没有方案
        if ((target + sum) % 2 == 1) return 0; // 此时没有方案，考虑溢出还好此题没有溢出
        int bagSize = (target + sum) / 2; 
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;//理论上也很好解释，装满容量为0的背包，有1种方法，就是装0件物品。
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];

    }
};