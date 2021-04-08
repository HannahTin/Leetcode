/**
字母大小写全排列

给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
示例：
输入：S = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]

输入：S = "3z4"
输出：["3z4", "3Z4"]

输入：S = "12345"
输出：["12345"]
**/
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    string S;
    vector<string> res;
    void dfs(string path,int start){
        if(path.size() == S.size()){
            res.push_back(path);
            return;
        }
        for(int i =start;i<S.size();i++){
            if(isalpha(S[i])){
                dfs(path+char(tolower(S[i])),i+1);
                dfs(path+char(toupper(S[i])),i+1);
            }else{
                dfs(path+S[i],i+1);
            }
        }


    }
public:
    vector<string> letterCasePermutation(string S) {
        this->S = S;
        if(S.size() == 0) return res;
        dfs("",0);
        return res;

    }
};