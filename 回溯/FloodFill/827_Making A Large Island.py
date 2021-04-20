'''
最大人工岛
在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。

进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）

示例 1:

输入: [[1, 0], [0, 1]]
输出: 3
解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿
'''
# 思路参考https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-/
# 不能在方格中标记岛屿的面积，而应该标记岛屿的索引（下标），另外用一个数组记录每个岛屿的面积，
# 这道题实际上是对网格做了两遍 DFS：第一遍 DFS 遍历陆地格子，计算每个岛屿的面积并标记岛屿；第二遍 DFS 遍历海洋格子，观察每个海洋格子相邻的陆地格子。
class Solution:
    def largestIsland(self, grid: list) -> int:
        no = 2
        area = []
        def dfs(i,j,no):
            if(not 0<=i<len(grid) or not 0<=j<len(grid[0]) or grid[i][j]!=1):
                return 0
            count = 1
            grid[i][j] = no
            count += dfs(i+1,j,no) + dfs(i,j+1,no)+dfs(i-1,j,no) + dfs(i,j-1,no)
            return count

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j]==1):
                    temp = dfs(i,j,no)
                    area.append(temp)
                    no += 1
        # print(grid)
        # print(area)
        res = max(area) if area else 0
        def changeSea(i,j):
            window = set()
            areaSum = 1
            if (i-1 >= 0 and grid[i-1][j]!=0): window.add(grid[i-1][j])
            if (i+1 < len(grid) and grid[i+1][j]!=0): window.add(grid[i+1][j])
            if (j-1 >= 0 and grid[i][j-1]!=0): window.add(grid[i][j-1])
            if (j+1 < len(grid[0]) and grid[i][j+1]!=0): window.add(grid[i][j+1])
            for index in window:
                areaSum += area[index-2]
            return areaSum
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if(grid[i][j]==0):
                    # print(changeSea(i,j))
                    res = max(res,changeSea(i,j))
        return res
       




s = Solution()
print(s.largestIsland([[1,0,1],[1,0,1]]))
print(s.largestIsland([[0,0],[0,0]]))
print(s.largestIsland([[1,1],[1,1]]))