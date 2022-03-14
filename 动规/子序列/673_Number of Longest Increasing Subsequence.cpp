/*
673. 最长递增子序列的个数
给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。

 

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
*/
using namespace std;
#include <vector>
class Solution {
public:
// 1. 维护两个数组,定义如下：
// dp[i]：i之前（包括i）最长递增子序列的长度为dp[i]
// count[i]：以nums[i]为结尾的字符串，最长递增子序列的个数为count[i]
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        vector<int> dp(nums.size(),1);
        vector<int> count(nums.size(),1);
        int maxLen = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]= count[j];
                    }else if(dp[j]+1 == dp[i]){
                        count[i] += count[j];
                    }
                }
                if (dp[i] > maxLen) maxLen = dp[i];
            }
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxLen == dp[i]) result += count[i];
        }
        return result;



    }
};