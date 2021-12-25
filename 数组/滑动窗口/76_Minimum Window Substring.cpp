/**
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
**/ 
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> needs;
        for(char c:t) needs[c]++;
        unordered_map<char,int> window;
        int match=0,start =0;
        int minLen=s.size()+1;
        for(int left =0,right =0;right<s.size();right++){
            char cur = s[right];
            if(needs.count(cur)) {
                window[cur]++;
                if(needs[cur]==window[cur]) match++;
            }
            while(match == needs.size()){
                if(right-left+1<minLen){
                    start = left;
                    minLen = right-left+1;
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen == s.size()+1 ?
                "" : s.substr(start, minLen);

    }
};