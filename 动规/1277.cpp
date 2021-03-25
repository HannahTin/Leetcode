/**
统计全为 1 的正方形子矩阵

题目描述：
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
**/
// 思路和221题最大正方形的面积是完全一样的，dp[i][j]的意思同样是以(i,j)为右下角的正方形的最大边长，个数就是最大边长是几就是正方形有几个。
int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int count = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for(int i =0;i<rows;i++){
            for(int j =0;j<columns;j++){
                if(matrix[i][j]==1){
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                       dp[i][j]=min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    count += dp[i][j];
                }
            }
        }
        return count;


    }