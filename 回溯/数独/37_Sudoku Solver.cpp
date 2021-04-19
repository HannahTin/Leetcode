/**
解数独


题目描述：
编写一个程序，通过填充空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
**/
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool valid(vector<vector<char>>& board,int row,int col,char ch){ // 判断是不是行有效，列有效和小正方形区域内有效
        for(int i =0;i<9;i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == ch) return false;
        }
        return true;

    }
    bool dfs(vector<vector<char>>& board,int row,int col){
        if(col == 9) return dfs(board,row+1,0);
        if(row == 9) return true;
        for(int i=row;i<9;i++){
            for(int j =col;j<9;j++){
                if(board[i][j] != '.'){
                    return dfs(board,i,j+1);
                }
                else{
                    for(char ch = '1';ch<='9';ch++){
                        if(!valid(board,i,j,ch)) continue; // 这个字符没效就换下一个！
                        board[i][j] = ch; //有效就填上
                        if(dfs(board,i,j+1)) return true; // 填上之后后面的也有效，那就是全局有效
                        board[i][j] = '.'; //否则回溯

                    }
                    return false;

                }
            }
        }
        return false;// 无所谓 return true也行，反正也不会执行到这一步。

    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);

    }
};