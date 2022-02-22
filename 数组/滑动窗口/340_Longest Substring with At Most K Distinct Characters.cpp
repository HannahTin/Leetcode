/*
340. 至多包含 K 个不同字符的最长子串

给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。

 

示例 1:

输入: s = "eceba", k = 2
输出: 3
解释: 则 T 为 "ece"，所以长度为 3。
示例 2:

输入: s = "aa", k = 1
输出: 2
解释: 则 T 为 "aa"，所以长度为 2。
*/
// 
using namespace std;
#include <string>
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> map;
        if(k==0){return 0;}
        int n = s.size();
        int ans =0;
        for(int l=0,r=0;r<n;r++){
            map[s[r]]++;
            while(map.size()>k){
                map[s[l]]--;
                if(map[s[l]]==0){map.erase(s[l]);}
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
