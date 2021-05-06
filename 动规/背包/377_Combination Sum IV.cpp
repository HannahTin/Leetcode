/**
377. 组合总和 Ⅳ
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
**/
// 本质是本题求的是排列总和，而且仅仅是求排列总和的个数，并不是把所有的排列都列出来。
// 如果本题要把排列都列出来的话，只能使用回溯算法爆搜。
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];

    }
};


