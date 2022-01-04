/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

**/
// 括号匹配是使用栈解决的经典问题
using namespace std;
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> st;
        unordered_map<char,char> pairs;
        pairs = {{')','('},{'}','{'},{']','['}};
        for(char c:s){
            if(pairs.count(c)){
                if(st.empty() || ( not st.empty() and st.top()!=pairs[c])) return false;
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.empty();

       

    }
};