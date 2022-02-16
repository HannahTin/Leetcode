/**
977. 有序数组的平方

给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
**/
using namespace std;
#include <iostream>
#include <vector>
// 时间复杂度为O(n),空间复杂度为O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
int main() {
    vector <int> nums = {-4,-1,0,3,10};
    Solution mysolution = Solution();
    vector<int> ans = mysolution.sortedSquares(nums);
    for(int k:ans){
        cout<<k<<"  ";
    }
    return 0;
}





