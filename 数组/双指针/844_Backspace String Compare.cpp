/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，请你判断二者是否相等。# 代表退格字符。

如果相等，返回 true ；否则，返回 false 。

注意：如果对空文本输入退格字符，文本继续为空。

 

示例 1：

输入：s = "ab#c", t = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
*/
using namespace std;
#include <vector>
#include <string>
// 栈来遍历，重构字符串
// 时间复杂度：O(N+M)，其中 N和 M分别为字符串 S 和 T的长度。我们需要遍历两字符串各一次。
// 空间复杂度：O(N+M)，其中 N和 M分别为字符串 S和 T的长度。主要为还原出的字符串的开销。
class SolutionOne {
public:
    string build(string str){
        string res;
        for(char s:str){
            if(s!='#'){
                res.push_back(s);
            }
            else if(!res.empty()){
                res.pop_back(); 
            }
        }
            return res;
        }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};
// 定义两个指针，分别指向两字符串的末尾。每次我们让两指针逆序地遍历两字符串，直到两字符串能够各自确定一个字符，然后将这两个字符进行比较。重复这一过程直到找到的两个字符不相等，或遍历完字符串为止。
// 时间复杂度：O(N+M)
// 空间复杂度：O(1)
class SolutionTwo {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        int skipS = 0;
        int skipT =0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skipS ++,i--;
                }
                else if(skipS>0){
                    skipS --,i--;
                }
                else break;
            }
            while(j>=0){
                if(t[j]=='#'){
                    skipT ++,j--;
                }
                else if(skipT>0){
                    skipT --,j--;
                }
                else break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;

    }
};

