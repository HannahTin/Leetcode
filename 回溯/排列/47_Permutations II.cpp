//全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
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
            if(visited[i] == true || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue; //改变了这里！！
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(path);
            path.pop_back();
            visited[i] = false;
        }
          
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        if(nums.size()==0) return res;
        visited = vector<bool>(nums.size());
        sort(this->nums.begin(),this->nums.end());// 还有这里，注意一定是this->nums,害得我找错找了好久
        vector<int> path;
        dfs(path);
        return res;

    }
};
