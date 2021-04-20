'''
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
'''
# 和岛屿面积题基本一样，只不过不用算count了，更简单了呢，还有注意grid里面存的是str不是int了！
class Solution:
    def numIslands(self, grid: list) -> int:
        res = 0
        def dfs(i,j):
            if(not 0<=i<len(grid) or not 0<=j<len(grid[0]) or grid[i][j]=='0'):
                return 
            grid[i][j] = '0'
            dfs(i+1,j)
            dfs(i,j+1)
            dfs(i-1,j) 
            dfs(i,j-1)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j]=='1'): 
                    dfs(i,j)
                    res+=1
        return res