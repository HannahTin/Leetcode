/**
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

**/
using namespace std;
#include <string>
#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right=0,maxLen =0;
        set<char> window;
        while(right<s.size()){
            window.insert(s[right]);
            if(right-left+1>maxLen) maxLen = right-left+1;
            right++;
            while(window.find(s[right])!=window.end()){
                window.erase(s[left]);
                left++;
            }
            

        }
        return maxLen;

    }
};