/**
把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
// 首先用回溯做，然后进行优化，因为递归过程中有重复的子问题，就用动态规划做。
// 时间复杂度：O(2^n) 
// 空间复杂度：O(n)递归树的深度可以达到 n。
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
private:
    string num;
    int res = 0;
    int path = 0;
    void dfs(int start){
        if(path == num.size()){
            res +=1;
            return;
        }
        for(int i=start;i<num.size();i++){
            if(num[i]!='0' and i<num.size()-1  and num[i+1]-'0'+(num[i]-'0')*10 <=25){
                path+= 2;
                dfs(i+2);
                path -= 2;
            }
            path += 1;
            dfs(i+1);
            path -= 1;
        }
    }
public:
    int translateNum(int num) {
        this->num = to_string(num);
        if(num<0) return 0;
        if(num>=0  and num<=9) return 1;
        if(num>=10 and num<=25) return 2;
        dfs(0);
        return res;
    }
};