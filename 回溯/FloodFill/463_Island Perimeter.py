'''
463. 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
'''
# 实际上，岛屿的周长是计算岛屿全部的「边缘」，而这些边缘就是我们在 DFS 遍历中，dfs 函数返回的位置。
class Solution:
    def islandPerimeter(self, grid: list) -> int:
        def dfs(i,j):
            if(not 0<=i<len(grid) or not 0<=j<len(grid[0]) or grid[i][j] == 0):
                return 1
            if (grid[i][j] == 2): return 0 #已经遍历过
            grid[i][j] = 2
            return dfs(i+1,j) + dfs(i,j+1)+dfs(i-1,j) + dfs(i,j-1)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j]==1):
                    return dfs(i,j)
        return 0

