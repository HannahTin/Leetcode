/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
*/
using namespace std;
#include <vector>
class Solution {
public:
    int search_leftbound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        bool isinArray = false;
        while(left<right){
            int middle = left+(right-left)/2;
            if(nums[middle]>target){
                right = middle;
            }
            else if(nums[middle]<target){
                left = middle+1;
            }
            else{
                isinArray = true;
                right = middle;
            }
        }
        if (isinArray) return left;
        else return -1;
    }
    int search_rightbound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        bool isinArray = false;
        while(left<right){
            int middle = left+(right-left)/2;
            if(nums[middle]>target){
                right = middle;
            }
            else if(nums[middle]<target){
                left = middle+1;
            }
            else{
                isinArray = true;
                left = middle+1;
            }
        }
        if (isinArray) return left-1;
        else return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{search_leftbound(nums, target), search_rightbound(nums, target)};

    }
};
