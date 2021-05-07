/**
买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
**/
using namespace std;
#include <vector>
// 本题一开始我没动态规划,下面是python实现代码，时间复杂度为O(n),空间复杂度为O（1）
/**
def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        min_num = sys.maxsize
        res = 0
        for i in range(len(prices)):
            min_num = min(min_num,prices[i])
            res = max(res,prices[i] - min_num)
        return res
**/
// 下面用动规实现下：参考https://mp.weixin.qq.com/s/keWo5qYJY4zmHn3amfXdfQ
//时间复杂度为O(n),空间复杂度为O（n）
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};
//优化一下空间：时间复杂度为O(n),空间复杂度为O（1）
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(2)); // 注意这里只开辟了一个2 * 2大小的二维数组
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }
        return dp[(len - 1) % 2][1];
    }
};


