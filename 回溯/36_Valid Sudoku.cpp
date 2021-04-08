/**
 有效的数独
 
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool valid(vector<vector<char>>& board,int row,int col,char ch){
        for(int i =0;i<9;i++){
            if(board[row][i] == ch and i!= col) return false;
            if(board[i][col] == ch and i!= row) return false;
            if(board[(row/3)*3+i/3][(col/3)*3 + i%3]==ch and (row/3)*3+i/3!=row and (col/3)*3 + i%3!=col) return false;
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board,int row,int col){
        if(col ==9) return dfs(board,row+1,0);
        if(row == 9) return true;
        for(int i =row;i<9;i++){
            for(int j = col;j<9;j++){
                if(board[i][j] != '.'){
                    if(valid(board,i,j,board[i][j]) ) return dfs(board,i,j+1);
                    else return false;
                }
                else return dfs(board,i,j+1);
            }
        }
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return dfs(board,0,0);
        

    }
};