// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
/**输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

**/
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<bool> visited;
    vector<int> nums;
    vector<vector<int>> res;
    void dfs(vector<int> path){
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i] == true) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(path);
            path.pop_back();
            visited[i] = false;
        }
          
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        if(nums.size()==0) return res;
        visited = vector<bool>(nums.size());
        vector<int> path;
        dfs(path);
        return res;

    }
};