/*
392. 判断子序列

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

 

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
*/
#include<string>
#include<vector>
using namespace std;
// 双指针做法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if(lens>lent) return false;
        int indexs=0,indext=0;
        while(indexs<lens and indext<lent){
            if(s[indexs]==t[indext]){
                indexs++;
            }
            indext++;
        }
        return indexs>=lens;



    }
};
// dp:该解法中对 t 的处理与 s 无关，且预处理完成后，可以利用预处理数组的信息，线性地算出任意一个字符串 
// s 是否为 t 的子串。这样我们就可以解决「后续挑战」啦。

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