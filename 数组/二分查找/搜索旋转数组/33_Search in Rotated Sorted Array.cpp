/**
搜索旋转排序数组

整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
**/
using namespace std;
#include <vector>
// 思路：将数组从中间分开，一定有一部分的数组是有序的。能够根据有序的那部分判断出 target 在不在这个部分：

// 如果 [l, mid - 1] 是有序数组，且 target 的大小满足 [[nums[l],nums[mid])，则我们应该将搜索范围缩小至 [l, mid - 1]，否则在 [mid + 1, r] 中寻找。
// 如果 [mid, r] 是有序数组，且 target 的大小满足 (nums[mid],nums[r]]，则我们应该将搜索范围缩小至 [mid + 1, r]，否则在 [l, mid - 1] 中寻找。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return nums[0] == target ? 0 : -1;
        int left =0,right = n-1;
        while(left<=right){
            int middle  = left + (right - left)/2;
            if(nums[middle]==target) return middle;
            if(nums[0]<=nums[middle]){
                if(nums[0]<=target and target<nums[middle]){
                    right = middle -1;
                }
                else{
                    left = middle+1;
                }
            }
            else{
                if(nums[middle]<target and target <= nums[right]){
                    left = middle+1;
                }
                else{
                    right = middle-1;
                }

            }
        }
        return -1;
    }
};