/*
2161. 根据给定数字划分数组
给你一个下标从 0 开始的整数数组 nums 和一个整数 pivot 。请你将 nums 重新排列，使得以下条件均成立：

所有小于 pivot 的元素都出现在所有大于 pivot 的元素 之前 。
所有等于 pivot 的元素都出现在小于和大于 pivot 的元素 中间 。
小于 pivot 的元素之间和大于 pivot 的元素之间的 相对顺序 不发生改变。

输入：nums = [9,12,5,10,14,3,10], pivot = 10
输出：[9,5,3,10,10,12,14]
解释：
元素 9 ，5 和 3 小于 pivot ，所以它们在数组的最左边。
元素 12 和 14 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [9, 5, 3] 和 [12, 14] ，它们在结果数组中的相对顺序需要保留。

*/
using namespace std;
#include<vector>
class Solution {
public:
// 左右指针遍历数组
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n,pivot);//初始化结果数组为pivot
        int left =0,right = n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                res[left] = nums[i];
                left++;
            }else if (nums[i]>pivot){
                res[right] =nums[i];
                right--;

            }
        }
        reverse(res.begin()+right+1,res.end());//为保持相对顺序，需要对比pivot大的进行反转
        return res;
        
    }
};