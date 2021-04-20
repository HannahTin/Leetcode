'''
417. 太平洋大西洋水流问题
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
'''
# 思路
# 逆流而上！分别从太平洋和大西洋出发，向陆地扩散，记录能到达的点，分别存储于Pacific和Atlantic数组中
# Pacific和Atlantic的交集即为所求
# 复杂度分析
# 时间复杂度：O(m*n),m,n为大陆横纵坐标
# 空间复杂度：O(m*n)
class Solution:
    def pacificAtlantic(self, heights: list) -> list:
        m,n=len(heights),len(heights[0])
        pos=[(0,1),(0,-1),(1,0),(-1,0)]

        def dfs(x,y,arr):
            arr[x][y]=1
            for dx,dy in pos:
                xx,yy=x+dx,y+dy
                if 0<=xx<m and 0<=yy<n and heights[xx][yy]>=heights[x][y] and not arr[xx][yy]:
                    dfs(xx,yy,arr)

        Pacific=[[0]*n for _ in range(m)]
        Atlantic=[[0]*n for _ in range(m)]

        for i in range(n):
            dfs(0,i,Pacific)
            dfs(m-1,i,Atlantic)
        for j in range(m):
            dfs(j,0,Pacific)
            dfs(j,n-1,Atlantic)
        # print(Pacific)
        # print(Atlantic)
        return [[i,j] for i in range(m) for j in range(n) if Pacific[i][j] and Atlantic[i][j]]

s = Solution()
s.pacificAtlantic([[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]])