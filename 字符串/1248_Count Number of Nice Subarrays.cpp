/**
统计「优美子数组」

题目描述：
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 和1371题一样 首先利用前缀和计算
int numberOfSubarrays(vector<int>& nums, int k) {
    int ans=0,odd=0,n=nums.size();
    vector<int> cnt(1+n,0);
    cnt[0]=1;
    for(int i =0;i<n;i++){
        odd += nums[i] &1;
        ans += odd>=k?cnt[odd-k]:0;
        cnt[odd] += 1;
    }
    return ans;

 }

 int main(){
     vector<int> res = {1,1,2,1,1};
     cout<<numberOfSubarrays(res,3)<<endl;

 }