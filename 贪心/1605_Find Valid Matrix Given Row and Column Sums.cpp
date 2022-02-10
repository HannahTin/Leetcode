/*
1605. 给定行和列的和求可行矩阵
给你两个非负整数数组 rowSum 和 colSum ，其中 rowSum[i] 是二维矩阵中第 i 行元素的和， colSum[j] 是第 j 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。

请找到大小为 rowSum.length x colSum.length 的任意 非负整数 矩阵，且该矩阵满足 rowSum 和 colSum 的要求。

请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个 可行矩阵。

 

示例 1：

输入：rowSum = [3,8], colSum = [4,7]
输出：[[3,0],
      [1,7]]
解释：
第 0 行：3 + 0 = 3 == rowSum[0]
第 1 行：1 + 7 = 8 == rowSum[1]
第 0 列：3 + 1 = 4 == colSum[0]
第 1 列：0 + 7 = 7 == colSum[1]
行和列的和都满足题目要求，且所有矩阵元素都是非负的。
另一个可行的矩阵为：[[1,2],
                  [3,5]]
*/


// 看到示例要求构造至少一个非负整数构成的矩阵，那么我们先根据横、列构造一个全零矩阵。
// 下来，我们就要考虑矩阵有什么规律了，然而没什么卵规律可言。
// 那么，针对矩阵如何将维或者缩小范围呢？我们可以考虑今早的将所有数字填满，那么后面的让空着零就行了！
// 所以，针对matrix[i][j]这个单元格，我们尽量填入最大的值，那么如何获取最大值？
// 当然是该行、该列对应可取的最大值，即min(rowSum[i],colSum[j])，填入后对应行、列减去该值。
// 有了这个思路，就可以循环遍历获取结果了...那么如何证明？
// 我们遍历了第一行，针对每列执行上述操作，第一行肯定是满足了，并且后面的n-1行由于每列>=0，依然满足条件。
// 就减少了一行的范围，如此往复，最终即可获取结果。

#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};