'''
695. 岛屿的最大面积
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
'''
class Solution:
    def maxAreaOfIsland(self, grid: list) -> int:
        res = 0
        def dfs(i,j):
            if(not 0<=i<len(grid) or not 0<=j<len(grid[0]) or grid[i][j] == 0):
                return 0
            count = 1
            grid[i][j] = 0
            count += dfs(i+1,j) + dfs(i,j+1)+dfs(i-1,j) + dfs(i,j-1)
            return count

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res = max(res,dfs(i,j))
        return res