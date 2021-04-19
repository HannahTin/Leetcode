/**
子集 ii

题目描述：
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
using namespace std;
#include <vector>
class Solution {
private:
    vector<int> nums;
    vector<vector<int>> res;
    void dfs(vector<int> path,int start){
        res.push_back(path);
        for(int i =start;i<nums.size();i++){
            if(i>start and nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(path,i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size()==0) return res;
        this->nums = nums;
        vector<int> path;
        sort(this->nums.begin(),this->nums.end());
        dfs(path,0);
        return res;


    }
};