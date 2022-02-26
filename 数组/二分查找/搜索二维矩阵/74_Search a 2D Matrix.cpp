/*
74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
*/
using namespace std;
#include<vector>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 先搜索行
        int row = matrix.size(),col=matrix[0].size();
        int left =0,right =row,middle;
        while(left<right){
            middle = left+(right-left)/2;
            if(target==matrix[middle][0]) return true;
            // 比当前行第一个数字大，可能在当前行，也可能在下一行，因此先检查是否在当前行
            else if(target>matrix[middle][0] and target<= matrix[middle][col-1]) break;
            else if(target<matrix[middle][0]) right=middle;
            else left = middle+1; 
        }
        int target_row = middle;
        // cout<<middle<<endl;
        // 再搜索列
        left =0,right= col;
        while(left<right){
            middle = left+(right-left)/2;
            if(target==matrix[target_row][middle]) return true;
            else if(target>matrix[target_row][middle]) left = middle+1;
            else right = middle;
        }
        return false;
    }
};