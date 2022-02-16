/*
283. 移动零

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
*/
using namespace std;
#include <vector>
// 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。

// 右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

// 注意到以下性质：

// 左指针左边均为非零数；
// 右指针左边直到左指针处均为零。
// 因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
// 和27题移除元素很像
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0,right =0;
        while(right<nums.size()){
            if(nums[right]){
                swap(nums[left],nums[right]);
                left ++;
            }
            right ++;
        }
    }
};