/**
216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
**/
using namespace std;
#include <vector>
// 回溯，主要在退出的条件识别

// 两个条件
// 1、k的限制，如果k达到了，sum没达到，不合格；
// 2、n的限制，如果当前累加和已经超大，不合格；

// start的设置可以避免重复数据。

class Solution {
public:
    int k;
    int n;
    vector<vector<int>> ans;

    void dfs(int index, vector<int>& cur, int sum, int start) {
        if ((index >= k && sum < n) || sum > n) {
            return;
        }
        if (index == k && sum == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (sum + i > n) {
                continue;
            }
            sum += i;
            cur.push_back(i);
            dfs(index + 1, cur, sum, i + 1);
            sum -= i;
            cur.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        this->k = k;
        this->n = n;
        
        dfs(0, cur, 0, 1);
        return ans;
    }
};

