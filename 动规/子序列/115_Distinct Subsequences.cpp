/**
115. 不同的子序列
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
**/
using namespace std;
#include <vector>
#include <string>
// dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1,vector<uint64_t>(t.size()+1));
        for(int i=0;i<s.size();i++) dp[i][0] = 1;
        for(int j=1;j<t.size();j++) dp[0][j] = 0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
            //当s[i - 1] 与 t[j - 1]相等时，dp[i][j]可以有两部分组成。
            // 一部分是用s[i - 1]来匹配，那么个数为dp[i - 1][j - 1]。
            // 一部分是不用s[i - 1]来匹配，个数为dp[i - 1][j]。
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
            // 当s[i - 1] 与 t[j - 1]不相等时，dp[i][j]只有一部分组成，不用s[i - 1]来匹配，即：dp[i - 1][j]
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];

    }
};