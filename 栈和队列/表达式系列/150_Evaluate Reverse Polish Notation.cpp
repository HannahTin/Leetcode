/**
根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

**/
using namespace std;
#include <stack>
#include <vector>
#include<string>
#include <unordered_set>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> op;
        op ={"+","-","*","/"};
        stack<int> st;
        for(string c:tokens){
            if(not st.empty() and op.count(c)){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if(c=="+") {
                    st.push(op1+op2);
                }
                else if(c=="-"){
                    st.push(op2-op1);
                } 
                else if(c=="*"){
                    st.push(op1*op2);
                } 
                else if(c=="/"){
                    st.push(op2/op1);
                } 
                
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();


    }
};