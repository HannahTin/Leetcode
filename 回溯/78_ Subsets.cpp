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
// 典型回溯模版应用
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int startIndex) {
    result.push_back(path); // 收集子集
    if (startIndex >= nums.size()) { // 终止条件可以不加
        return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
}
