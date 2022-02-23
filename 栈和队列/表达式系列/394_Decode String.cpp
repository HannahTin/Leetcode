/*
394. 字符串解码

给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"

1 <= s.length <= 30
s 由小写英文字母、数字和方括号 '[]' 组成
s 保证是一个 有效 的输入。
s 中所有整数的取值范围为 [1, 300] 

*/
using namespace std;
#include <string>
#include <stack>
// 用两个栈维护：字母栈、数字栈
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> num_st;
        stack<string> alp_st;
        int num =0;
        string str ="";
        for(char c:s){
            if('0'<=c and c <='9'){
                num = num*10+c-'0';
            }else if(c=='['){
                num_st.push(num);
                alp_st.push(str);
                num =0;
                str.clear();
            }else if(c>='a' and c<='z'){
                str+= c;
            }else if(c==']'){
                int repeat_times = num_st.top();
                num_st.pop();
                for(int i=0;i<repeat_times;i++){
                    alp_st.top()+=str;
                }
                str = alp_st.top();
                alp_st.pop();
            }

        }
        res+=str;
        return res;

    }
};