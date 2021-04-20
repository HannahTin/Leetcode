'''
1254. 统计封闭岛屿的数目
有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。

我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。

如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。

请返回封闭岛屿的数目。
'''
# 时间复杂度：O(mn)。其中m、n分别为矩阵的行数和列数。
# 空间复杂度：O(mn)。递归所需要的栈空间大小为mn。
class Solution:
    def closedIsland(self, grid: list) -> int:
        res = 0
        def dfs(i,j):
            nonlocal val
            if(not 0<=i<len(grid) or not 0<=j<len(grid[0])):
                val = 0
                return 0
            if(grid[i][j] == 1):return
            grid[i][j] = 1
            dfs(i+1,j) 
            dfs(i,j+1)
            dfs(i-1,j) 
            dfs(i,j-1)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j] == 0):
                    val = 1
                    dfs(i,j)
                    res += val
        return res