/*
1005. K 次取反后最大化的数组和
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

 

示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
*/
// 思路：
/**
第一步：将数组按照绝对值大小从大到小排序，「注意要按照绝对值的大小」
第二步：从前向后遍历，遇到负数将其变为正数，同时K--
第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
第四步：求和
**/
// 第一次贪心：局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大。

// 处理之后，如果K依然大于0，此时的问题是一个有序正整数序列，如何转变K次正负，让 数组和 达到最大。

// 第二次贪心：局部最优：只找数值最小的正整数进行反转，当前数值可以达到最大（例如正整数数组{5, 3, 1}，反转1 得到-1 比 反转5得到的-5 大多了），全局最优：整个 数组和 达到最大。
using namespace std;
#include <vector>

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int p1,int p2){return abs(p1)>abs(p2);});
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0 and k>0){
                nums[i]*=-1;
                k--;
            }
        }
        while(k--) nums[nums.size()-1]*=-1;
        int res=0;
        for(int num:nums) res+= num;
        return res;

    }
};
// 借鉴下面的sort写法
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        while (K--) A[A.size() - 1] *= -1;  // 第三步 
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};