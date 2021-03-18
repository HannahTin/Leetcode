/**
三数之和

题目描述：
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
// 一层for循环num[i]为确定值，然后循环内有left和right下表作为双指针，找到nums[i] + nums[left] + nums[right] == 0。
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 这里用哈希法细节处理则十分复杂，这里采用双指针法
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    if(nums.size()==0 || nums[0] > 0) return res; // 如果最小的数还大于0，肯定不会有解了
    for(int i =0;i<nums.size();i++){
        if (i > 0 && nums[i] == nums[i - 1]) {   // 对a取值去充
                continue;
        }
        int left =  i+1;
        int right = nums.size()-1;
        while(left < right){
            if(nums[left]+nums[right]+nums[i] >0){
                right --;
            }
            else if(nums[left]+nums[right]+nums[i]<0){
                left ++;
            }
            else{
                res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while(right>left && nums[right] == nums[right-1]) right --; // 0，0，0 的情况，可能直接导致 right<=left 了
                while(right>left && nums[left] == nums[left+1]) left ++; // 对b和c取值去充
                right --;
                left ++;
            }
        }
        
        
    }
    return res;



}