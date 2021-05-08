/**
188. 买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
**/
using namespace std;
#include<vector>
// 本题相比III的区别在于最多买卖k次，II最多买卖2次。
// 使用二维数组 dp[i][j] ：第i天的状态为j，所剩下的最大现金是dp[i][j]

// j的状态表示为：

// 0 表示不操作
// 1 第一次买入
// 2 第一次卖出
// 3 第二次买入
// 4 第二次卖出
// .....
// 大家应该发现规律了吧 ，除了0以外，偶数就是卖出，奇数就是买入。

// 题目要求是至多有K笔交易，那么j的范围就定义为 2 * k + 1 就可以了。
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for(int i=1;i<2*k;i+=2){
            dp[0][i] = -prices[0];
        }
        for (int i = 1;i < prices.size(); i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) { 
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];

    }
};