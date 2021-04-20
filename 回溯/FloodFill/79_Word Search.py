'''
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
'''
class Solution:
    def exist(self, board: list, word: str) -> bool:
        def dfs(i,j,begin):
            if(not 0<=i<len(board) or not 0<=j<len(board[0]) or board[i][j]!=word[begin]):
                return False
            if(begin == len(word)-1): return True
            board[i][j] = ' '
            res = dfs(i + 1, j, begin + 1) or dfs(i - 1, j, begin + 1) or dfs(i, j + 1, begin + 1) or dfs(i, j - 1, begin + 1)
            if res == True:return True
            else: board[i][j] =word[begin]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if(dfs(i,j,0)): return True
        return False

