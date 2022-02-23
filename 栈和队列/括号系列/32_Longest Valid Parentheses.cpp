/*
32. 最长有效括号

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

 

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
*/
using namespace std;
#include <stack>
#include <string>
#include <vector>
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> mark(s.length());
        int left = 0, len = 0, ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                // 多余的右括号是不需要的，标记
                if(st.empty()) mark[i] = 1;
                else st.pop();
            }
        }
        // 未匹配的左括号是不需要的，标记
        while(!st.empty()) {
            mark[st.top()] = 1;
            st.pop();
        }
        // 寻找标记与标记之间的最大长度
        for(int i = 0; i < s.length(); i++) {
            if(mark[i]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;

    }
};