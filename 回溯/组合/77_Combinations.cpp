/**
组合

题目描述：
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
**/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    int k;
    int n;
    vector<vector<int>> res;
    void dfs(vector<int> path,int start){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            dfs(path,i+1);
            path.pop_back();
        }
    }


public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> path;
        dfs(path,1);
        return res;
    }
};
int main(){
    Solution* s = new Solution();
    vector<vector<int>> res = s->combine(4,2);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
}