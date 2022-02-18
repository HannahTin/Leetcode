/**
第一次只出现一次的字符

题目描述：
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
**/
// 思路：s只包含小写字母可以采用数组作为哈希表，否则可另创建新的哈希表map。检查字符是否重复出现，必用哈希。
#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

char firstUniqChar(string s) {
        unordered_map<char,bool> dic;
        for (char c:s){
            dic[c] = dic.find(c)==dic.end();
        }
        for (char c:s){
            if(dic[c]) return c;
        }
        return ' ';

    }

int main(){
    cout<<firstUniqChar("abaccdeff") ; // b

}
// class Solution {
// public:
//     char firstUniqChar(string s) {
//         vector<int> v(26);
//         for (int i = 0; i < s.size(); ++i) {
//             v[s[i] - 'a']++;
//         }
//         for (int i = 0; i < s.size(); ++i) {
//             if (v[s[i] - 'a'] == 1)
//                 return s[i];
//         }
//         return ' ';
//     }
// };