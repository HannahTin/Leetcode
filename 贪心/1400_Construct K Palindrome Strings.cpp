/*
1400. 构造 K 个回文字符串
给你一个字符串 s 和一个整数 k 。请你用 s 字符串中 所有字符 构造 k 个非空 回文串 。

如果你可以用 s 中所有字符构造 k 个回文字符串，那么请你返回 True ，否则返回 False 。
输入：s = "annabelle", k = 2
输出：true
解释：可以用 s 中所有字符构造 2 个回文字符串。
一些可行的构造方案包括："anna" + "elble"，"anbna" + "elle"，"anellena" + "b"

*/
// 先把奇数出现次数拆出来，然后比较奇数数量和k的大小，因为奇数只能单独成串，所以至少要有奇数个串，才能构成回文
using namespace std;
#include<string>
#include<unordered_map>
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char, int> mp;
        for(auto& c:s) mp[c]++;
        int cnt = 0;
        for(auto &[k, v]: mp) if(v&1) cnt++;
        return cnt<=k;

    }
};