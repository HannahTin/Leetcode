/*
611. 有效三角形的个数
给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。

 

示例 1:

输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
*/
using namespace std;
#include<vector>
// 排序数组，则仅需要a+b>c；
// 枚举ab，二分查找c
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int left = j + 1, right = n - 1, k = j; //k=j是考虑了数组中可能有0的情况
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                ans += k - j;

            }
        }
        return ans;


    }
};