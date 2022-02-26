/*
240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
*/
using namespace std;
#include<vector>
// 因此我们可以从整个矩阵的右上角开始枚举，假设当前枚举的数是 x：

// 如果 x 等于target，则说明我们找到了目标值，返回true；
// 如果 x小于target，则 x左边的数一定都小于target，我们可以直接排除当前一整行的数；
// 如果 x 大于target，则 x 下边的数一定都大于target，我们可以直接排除当前一整列的数；
// 时间复杂度分析： 每一步会排除一行或者一列，矩阵一共有 n 行，m 列，所以最多会进行n+m步。所以时间复杂度是 O(n+m)。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        // 从右上角开始找
        int i =0,j=col-1;
        while(i<row and j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
        
    }
};