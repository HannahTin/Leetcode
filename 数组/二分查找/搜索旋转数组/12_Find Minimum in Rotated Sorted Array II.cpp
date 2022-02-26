/*
154. 寻找旋转排序数组中的最小值 II

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。
请你找出并返回数组中的 最小元素 。

示例 1：

输入：nums = [1,3,5]
输出：1
示例 2：

输入：nums = [2,2,2,0,1]
输出：0
*/
using namespace std;
#include <vector>
// 我们考虑数组中的最后一个元素 x：在最小值右侧的元素，它们的值一定都小于等于 x；
// 而在最小值左侧的元素，它们的值一定都大于等于 x。因此，我们可以根据这一条性质，通过二分查找的方法找出最小值。

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if(nums[pivot]>nums[high]){
                low = pivot + 1;
            }else{
                high -=1; //因为本题数组有重复元素，因此，当nums[pivot]和nums[high]相等，那就是high--；
            }
        }
        return nums[low];

    }
};