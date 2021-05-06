/**
474. 一和零
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 
**/
// 题其实是01背包问题！这不过这个背包有两个维度，一个是m 一个是n，而不同长度的字符串就是不同大小的待装物品。
// 1.确定dp和下标：dp[i][j]：最多有i个0和j个1的strs的最大子集的大小为dp[i][j]。
// 2.递推公式：dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
// 3.dp数组如何初始化：0
// 4. 按照0-1背包遍历：外层遍历物品，内层背包容量从后往前遍历
// 物品就是strs里的字符串，背包容量就是题目描述中的m和n。
// 5. 举例验证dp
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0)); // 默认初始化0
        for (string str : strs) { // 遍历物品
            int oneNum = 0, zeroNum = 0;
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];

    }
};