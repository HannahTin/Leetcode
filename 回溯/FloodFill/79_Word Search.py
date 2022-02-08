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

# c++写法
'''
class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj] and check(board, visited, newi, newj, s, k + 1)) {
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
'''