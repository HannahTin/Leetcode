/**
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 * */
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int n;
    vector<bool> col;
    vector<bool> main;
    vector<bool> sub;
    vector<vector<string>> res;
    void dfs(int row,vector<string> path){
        if(row == n){
            res.push_back(path);
            return;
        }
        for(int j =0;j<n;j++){
            if(col[j] || main[j-row+n-1] || sub[row+j])
                continue;
            string temp(n,'.');
            temp[j]='Q';
            col[j] =true;
            main[j-row+n-1] = true;
            sub[row+j] = true;
            path.push_back(temp);
            dfs(row+1,path);
            path.pop_back();
            col[j] =false;
            main[j-row+n-1] = false;
            sub[row+j] = false;
        }


    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        if(n==0) return res;
        col = vector<bool>(n);
        main = vector<bool>(2*n-1);
        sub = vector<bool>(2*n-1);
        vector<string> path;
        dfs(0,path);
        return res;
    }
};