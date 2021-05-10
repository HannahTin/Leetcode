/**
392. 判断子序列
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
输入：s = "abc", t = "ahbgdc"
输出：true

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
**/
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 定义长度
        int len1 = s.length(), len2 = t.length();
        if(len1 > len2) {
            return false;
        }
        // 定义索引
        int index1 = 0, index2 = 0;
        while(index1 < len1 && index2 < len2) {
            // 如果当前位置相等，更新s的索引
            if(s[index1] == t[index2]) {
                index1 ++;
            }
            index2 ++;
        }
        // 返回是否遍历完s
        return index1 >= len1;
    }
};
//dp 时间复杂度：O(n * m) 空间复杂度：O(n * m)
// dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size() + 1, 0));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;

    }
};
