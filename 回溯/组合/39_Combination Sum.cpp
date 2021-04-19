/**
组合总和（剪枝）

题目描述：
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
**/
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    int path = 0;
    int target;
    vector<int> candidates;
    int sum =0;
    void dfs(vector<int> path,int sum,int start){
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(sum>target ) return;
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(path,sum,i);
            path.pop_back();
            sum -= candidates[i];

        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() ==0 or target<=0) return res;
        this->target = target;
        this->candidates = candidates;
        vector<int> path;
        dfs(path,0,0);
        return res;
    }
};