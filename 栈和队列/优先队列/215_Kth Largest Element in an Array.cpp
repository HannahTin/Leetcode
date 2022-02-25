/*
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

 

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/
using namespace std;
#include <vector>
// 快排
class Solution {
private:
    void swap(vector<int>& lyst, int i,int j){
        int tmp = lyst[i];
        lyst[i] = lyst[j];
        lyst[j] = tmp;

    }
    int partition(vector<int>& lyst,int left,int right){
        int pivot = lyst[left];
        lyst[left] = lyst[right];
        lyst[right] = pivot;
        int boundary = left;
        for(int index=left;index<right;index++){
            if(lyst[index]>pivot){
                swap(lyst,index,boundary);
                boundary ++;
            }
        }
        swap(lyst,right,boundary);
        return boundary;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int boundary = partition(nums,left,right);
        while(boundary!=k-1){
             if (boundary>k-1){
                right = boundary-1;
                boundary = partition(nums,left,right);

             } else{
                left = boundary +1;
                boundary = partition(nums,left,right);

            }
        }
           
        return nums[k-1];

    }
};