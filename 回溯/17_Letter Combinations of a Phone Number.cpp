/**
 电话号码的排列组合

 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
private:
    string digits;
    vector<string> res;
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    void dfs(string path,int start){
        if(path.size() == digits.size()){
            res.push_back(path);
            return;
        }
        for(int i =start;i<digits.size();i++){
            string temp = phoneMap.at(digits[i]);
            for(int j=0;j<temp.size();j++){
                dfs(path+temp[j],i+1);
            }
        } 


    }
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.size()==0) return res;
        dfs("",0);
        return res;
    }
};