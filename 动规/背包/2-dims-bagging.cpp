#include <vector>
#include<iostream>
using namespace std;
int two_dims_bagging(vector<int>& weights,vector<int>& value,int& bagweight){
    // 二维数组
    vector<vector<int>> dp(weights.size()+1,vector<int>(bagweight+1,0));
    // 初始化,注意倒序
    for(int j = bagweight;j>=weights[0];j--){
        dp[0][j] = dp[0][j-weights[0]]+value[0];
    }
    // 开始利用递归公式遍历了！
    for(int i = 1;i<weights.size();i++){ //遍历物品
        for (int j =0;j<=bagweight;j++){ //遍历背包
            if(j<weights[i]) dp[i][j] = dp[i-1][j]; //肯定不能放
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i]]+value[i]);//不取物品i和取物品i
        }
    }
    return dp[weights.size()-1][bagweight];


}
int main(){
    vector<int> weights = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    int res=two_dims_bagging(weights,value,bagweight);
    cout<<res<<endl;// 3 5


}