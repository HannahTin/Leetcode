#include <vector>
#include<iostream>
using namespace std;
// 于其把dp[i - 1]这一层拷贝到dp[i]上，不如只用一个一维数组了，只用dp[j]（一维数组，也可以理解是一个滚动数组）。
// 这就是滚动数组的由来，需要满足的条件是上一层可以重复利用，直接拷贝到当前层。
int one_dims_bagging(vector<int>& weights,vector<int>& value,int& bagweight){
    vector<int> dp(bagweight+1,0);
    for(int i=0;i<weights.size();i++){
        for(int j = bagweight;j>=weights[i];j--){ // 注意倒序，同样是因为一个物品只能加入背包一次。
            dp[j] = max(dp[j],dp[j-weights[i]]+value[i]);
        }
    }
    return dp[bagweight];
}
int main(){
    vector<int> weights = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    int res=one_dims_bagging(weights,value,bagweight);
    cout<<res<<endl;// 3 5


}
