/**
有效的字母异位词

题目描述：
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
**/
// 思路：字母异位即长度相同，各个字母出现的次数也相同只是位置不同。
// 因此我们首先要判断s和t的长度，然后看t中的字母是否在s中出现过，并且出现次数是不是和s相同。

#include <iostream>
#include <string>
using namespace std;

 bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
}
int main(){
    cout<<isAnagram("anagram","nagaram"); // 1
    cout<< isAnagram("rat","car"); //0

}