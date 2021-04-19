/**
子集

题目描述：
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例: 输入: nums = [1,2,3]
输出:
[
[3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
**/
using namespace std;
#include <vector>
#include <iostream>
// 典型回溯模版应用
class Solution {
private:    
    vector<vector<int>> res;
    vector<int> nums;
    void dfs(vector<int> path,int start){
        res.push_back(path);
        for(int i = start;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(path,i+1);
            path.pop_back();
        }

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0) return res;
        vector<int> path;
        this->nums = nums;
        dfs(path,0);
        return res;


    }
};
int main(){
    Solution* s = new Solution();
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s->subsets(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
}
