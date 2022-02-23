/*
343. 整数拆分
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。

 

示例 1:

输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
*/
using namespace std;
#include <vector>
class Solution {
public:
// 其实可以从1遍历j，然后有两种渠道得到dp[i].

// 一个是j * (i - j) 直接相乘。

// 一个是j * dp[i - j]，相当于是拆分(i - j)，对这个拆分不理解的话，可以回想dp数组的定义。
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i-1;j++){
                dp[i]=max(dp[i],max(dp[i-j]*j,j*(i-j)));
            }
        }
        return dp[n];

    }
};
class Solution {
public:
// 本题也可以用贪心，每次拆成n个3，如果剩下是4，则保留4，然后相乘，但是这个结论需要数学证明其合理性！
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int result = 1;
        while (n > 4) {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};