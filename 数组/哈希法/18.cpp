/**
四数之和

题目描述：
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：答案中不可以包含重复的四元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    if(nums.size() == 0 ) return res;
    for(int a =0;a<nums.size();a++){
        if(a>0 and nums[a] == nums[a-1]) continue;
        for(int b =a+1;b<nums.size();b++){
            if(b>a+1 && nums[b] == nums[b-1]) continue;
            int left = b+1;
            int right = nums.size() -1;
            while(left<right){
                if(nums[a] + nums[b] +nums[left] + nums[right] > target){
                    right --;

                }
                else if(nums[a] + nums[b] +nums[left] + nums[right] < target){
                    left ++;
                }
                else{
                    res.push_back({nums[a] ,nums[b] ,nums[left] , nums[right]});
                    while(right >left and nums[right] == nums[right-1]) right --;
                    while(right >left and nums[left] == nums[left+1]) left ++;
                    right --;
                    left ++;
                }
            }
        }
    }
    return res;


}