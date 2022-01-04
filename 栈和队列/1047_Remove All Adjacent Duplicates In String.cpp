/*8
删除字符串中的所有相邻重复项

给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

**/
using namespace std;
#include<string>
#include<stack>
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c:s){
            if(not st.empty() and c == st.top()){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};
// 将字符串作为栈使用
class Solution2 {
public:
    string removeDuplicates(string s) {
        string res;
        for(char c:s){
            if(res.empty() || res.back()!=c ){
                res.push_back(c);
            }
            else{
                res.pop_back();
            }
        }
        return res;
    }
};