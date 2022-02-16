/*
557. 反转字符串中的单词 III

给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例 1：

输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
示例 2:

输入： s = "God Ding"
输出："doG gniD"
*/
using namespace std;
#include<vector>
#include <string>
// 方法1:新开一个数组，保存每个单词的反转形式，时间、空间复杂度：O(N)
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int length = s.size();
        int i=0;
        while(i<length){
            int start = i;
            while(i<length and s[i]!=' '){
                i++;
            }
            for(int p=start;p<i;p++){
                ret.push_back(s[start+i-1-p]);
            }
            while(i<length and s[i]==' '){
                ret.push_back(' ');
                i++;
            }
        }
        return ret;
    }
};
// 方法2:原地双指针交换，时间复杂度：O(N)、空间复杂度：O(1)
class Solution2 {
public:
    string reverseWords(string s) {
        int i=0;
        while(i<s.size()){
            int start = i;
            while(i<s.size() and s[i]!=' '){
                i++;
            }
            int left = start,right = i-1;
            while(left<=right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            while(i<s.size() and s[i] == ' '){
                i++;
            }
        }
        return s;
        

    }
};