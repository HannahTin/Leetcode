'''
1034. 边框着色
给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。

只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。

连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。

给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid 。
'''
class Solution:
    def colorBorder(self, grid: list, r0: int, c0: int, color: int) -> list:
        row = len(grid)
        col = len(grid[0])
        origColor = grid[r0][c0]
        visited = [[False]*col for _ in range(row)]
        def dfs(x,y)->int:
            if not 0 <= x < row or not 0 <= y < col:
                return 0
            # 碰壁：遇到其他颜色，超出 origColor 区
            if(visited[x][y] == True): return 1
            if grid[x][y] != origColor: return 0
            visited[x][y] = True
            surround = dfs(x - 1, y)+ dfs(x + 1, y)+ dfs( x, y - 1,)+ dfs(x, y + 1)
            if (surround < 4):
                grid[x][y] = color
            return 1
        dfs(r0,c0)
        return grid
# 还有区域填色
'''
void fill(int[][] image, int x, int y, int origColor, int newColor) {
    // 出界：超出数组边界
    if (!inArea(image, x, y)) return;
    // 碰壁：遇到其他颜色，超出 origColor 区域
    if (image[x][y] != origColor) return;
    // 已探索过的 origColor 区域
    if (image[x][y] == -1) return;
    // choose：打标记，以免重复
    image[x][y] = -1;
    fill(image, x, y + 1, origColor, newColor);
    fill(image, x, y - 1, origColor, newColor);
    fill(image, x - 1, y, origColor, newColor);
    fill(image, x + 1, y, origColor, newColor);
    // unchoose：将标记替换为 newColor
    image[x][y] = newColor;
}
'''