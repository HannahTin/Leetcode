/**
和为s的连续正数序列

题目描述：
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 和57题一样同样采用双指针法。

#include <vector>
using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    if(target == 1 || target == 2) return res;
    int small  = 1;
    int large = 2;
    int middle = (1 + target) /2;
    int currSum = small + large;
    while(small<middle){
        if(currSum < target){
            large ++;
            currSum += large;
        }
        else if(currSum > target){
            currSum -= small;
            small ++ ;
        }
        else {
            vector<int> ans;
            for(int i=small;i<=large;i++)
                ans.push_back(i);
            res.push_back(ans);
            large ++;
            currSum += large;

        }


    }
    return res;
}
