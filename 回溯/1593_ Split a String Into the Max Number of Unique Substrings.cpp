/**
1593. 拆分字符串使唯一子字符串的数目最大

题目描述：
给你一个字符串 s ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。

字符串 s 拆分后可以得到若干 非空子字符串 ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 唯一的 。

注意：子字符串 是字符串中的一个连续字符序列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
    string s;
    int maxCount = 0;
    void dfs(unordered_set<string> path,int count,int start){
        if(start == s.size()){
            maxCount = max(maxCount,count);
        }
        for(int i=start;i<s.size();i++){
            string substr = s.substr(start,i-start+1);
            if(path.find(substr) == path.end()){
                path.insert(substr);
                count++;
                dfs(path,count,i+1);
                count --;
                path.erase(substr);
            }
        }

    }
public:
    int maxUniqueSplit(string s) {
        if(s.size()==1) return 1;
        this->s = s;
        unordered_set<string> path;
        dfs(path,0,0);
        return maxCount;



    }
};