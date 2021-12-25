/**
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
**/
// 因为这道题和76的场景类似，
// 也需要 window 中包含串 t 的所有字符，但76要找长度最短的子串，这道题要找长度相同的子串，也就是「字母异位词」。
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left =0,right =0,match=0;
        vector<int> res;
        unordered_map<char,int> needs;
        for(char c:p) needs[c]++;
        unordered_map<char,int> window;
        while(right<s.size()){
            if(needs.count(s[right])) {
                window[s[right]]++;
                if(needs[s[right]]==window[s[right]]) match++;
            }
            while(match == needs.size()){
                if(right-left+1==p.size()){
                    res.push_back(left);
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
            right++;
        }
        return res;

    }
};