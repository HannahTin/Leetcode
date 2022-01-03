/**
给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 

示例 1：

输入：words = ["bella","label","roller"]
输出：["e","l","l"]
**/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 整体思路就是统计出搜索字符串里26个字符的出现的频率，然后取每个字符频率最小值，最后转成输出格式就可以了。
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minfreq(26,INT_MAX);
        vector<int> freq(26);
        for (const string& word: words) {
            fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1,i+'a');
            }
        }
        return ans;
       

    }
};