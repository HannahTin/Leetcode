/**
两数之和

题目描述：
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
// 很明显暴力的解法是两层for循环，时间复杂度为O(n^2)。
// 使用哈希法最为合适，之前已经介绍过，数组和set在哈希法中的应用，那么来看下使用数组和set来做哈希法的局限。
// 数组的大小是受限的，就是如果元素很少，而哈希值太大很分散就会造成内存空间的浪费
// set是一个集合，里面放的元素只能是一个key，而两数之和这个题，不仅要判断y是否存在还要记录y的下标位置。因为要返回x和y的下标。所以set也不能用。
// 此时就要选择另一种数据结构：map，map是一种key：value的存储结构，可以用key存储数值，用value存储数值所在下标
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> res_map;
    for(int i =0;i<nums.size();i++){
        auto p =res_map.find(target - nums[i]);
        if(p!= res_map.end()){
            return {p->second,i};
        }
        res_map.insert({nums[i],i});


    }
    return {};

}
int main(){
    vector<int> res;
    vector<int> nums={2, 7, 11, 15};
    int target=9;
    res = twoSum(nums,target);
    for( int i :res){
        cout<<i<<endl;
    }


}
