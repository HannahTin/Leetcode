/*
567. 字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。

 

示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false
*/
#include <vector>
#include <unordered_map>
#include<string>
using namespace std;
// 和字母异位词一样
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left =0,right =0,match=0;
        vector<int> res;
        unordered_map<char,int> needs;
        for(char c:s1) needs[c]++;
        unordered_map<char,int> window;
        while(right<s2.size()){
            if(needs.count(s2[right])) {
                window[s2[right]]++;
                if(needs[s2[right]]==window[s2[right]]) match++;
            }
            while(match == needs.size()){
                if(right-left+1==s1.size()){
                    return true;   //修改了这里
                }
                char c2 = s2[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
            right++;
        }
        return false;

    }
};
