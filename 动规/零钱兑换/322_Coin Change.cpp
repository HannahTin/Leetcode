/**
322. 零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。
**/
using namespace std;
#include <vector>
// 完全背包变体：物品的重量就是硬币的面额，物品的价值也是硬币的面额，背包容量就是总金额
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);//注意初始化值
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) { // 遍历物品
            for(int j = coins[i]; j <= amount; j++) { // 遍历背包容量
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];

    }
};
