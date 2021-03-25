/**
2020/3/18 百度笔试原题 最大正方形
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
**/
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size()==0 or matrix[0].size()==0) return 0;
    int maxside;
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<int>> dp(rows,vector<int>(columns));
    for(int i = 0;i<rows;i++){
        for (int j =0;j<columns;j++){
            if(matrix[i][j] == '1'){
                if(i == 0 or j ==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxside = max(dp[i][j],maxside);
            }
        }
    }
    int maxSquare = maxside * maxside;
    return maxSquare;

}
int main(){
    char matrix[4][5] = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    int area = maximalSquare(matrix);
    cout<<area<<endl;


}