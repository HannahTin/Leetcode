/**
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
**/
using namespace std;
#include <vector>
// 思路: 0-1背包应用题，题目中物品是nums[i]，重量是nums[i]，价值也是nums[i]，背包体积是sum/2。
// 时间复杂度：O(n)
// 空间复杂度：O(n)，虽然dp数组大小为一个常数，但是大常数
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(20000+1,0); //如果题目给的价值都是正整数那么非0下标都初始化为0就可以了，如果题目给的价值有负数，那么非0下标就要初始化为负无穷。
        // 如果是int，可以用INT_MAX表示正无穷，INT_MIN表示负无穷，需要包含limits.h。
        // 如果是double，可以用DBL_MAX表示正无穷，-DBL_MAX表示负无穷(注意不是DBL_MIN)，需要包含float.h。
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        int target = sum / 2;
          // 开始 01背包 
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 集合中的元素正好可以凑成总和target 
        if (dp[target] == target) return true;
        return false;  


    }
};
