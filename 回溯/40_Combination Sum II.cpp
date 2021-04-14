/**
组合总和ii

题目描述：
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<int> candidates;
    int target;
    vector<vector<int>> res;
    void dfs(vector<int> path,int sum,int start){
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i =start;i<candidates.size();i++){
            if(sum>target) return;
            if(i>start and candidates[i]==candidates[i-1]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(path,sum,i+1);
            sum -= candidates[i];
            path.pop_back();

        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() ==0) return res;
        this->candidates = candidates;
        this->target = target;
        sort(this->candidates.begin(),this->candidates.end());
        vector<int> path;
        dfs(path,0,0);
        return res;

    }
};