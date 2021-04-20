'''
飞地的数量
给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。

移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。

返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。
'''
#  此题和130题：被围绕的面积基本一致
class Solution:
    def numEnclaves(self, grid: list) -> int:
        if not grid:
            return
        n, m = len(grid), len(grid[0])
        def dfs(x, y):
            if not 0 <= x < n or not 0 <= y < m or grid[x][y] != 1:
                return
            grid[x][y] = 0
            dfs(x + 1, y)
            dfs(x - 1, y)
            dfs(x, y + 1)
            dfs(x, y - 1)
        
        for i in range(n):
            dfs(i, 0)
            dfs(i, m - 1)
        
        for i in range(m - 1):
            dfs(0, i)
            dfs(n - 1, i)
        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    res +=1
        return res