/**
礼物🎁的最大价值

题目描述：
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
// 说下状态转移方程： dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j]
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() or grid[0].empty()) return 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(columns));
        dp[0][0]= grid[0][0];
        for(int j = 1;j<columns;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j]; 
        }
        for(int i = 1;i<rows;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i =1;i<rows;i++){
            for(int j=1;j<columns;j++){
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][columns-1];
        
    }