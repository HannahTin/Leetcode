/**
赎金信

题目描述：
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    int record[26]={0};
    for (char m:magazine){
        record[m-'a']++;
    }
    for(char r:ransomNote){
       record[r-'a']--;
       if(record[r-'a']<0) return false;
    }
    return true;
        

}
