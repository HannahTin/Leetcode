/**
滑动窗口最大值

题目描述：
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。
**/
// 优先队列（最大堆）维持窗口内的值，堆顶即为最大值。
#include <vector>
#include<iostream>
#include <queue>

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair< int,int >> q;
    for (int i = 0; i < k; ++i) {
        q.emplace(nums[i], i);
    }
    vector<int> ans = {q.top().first};
    for(int i =k;i<n;i++){
        q.emplace(nums[i],i);
        while (q.top().second <= i - k) {
            q.pop();
        }
        ans.push_back(q.top().first);
    }
    return ans;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res;
    int k =3;
    res = maxSlidingWindow(nums,k);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

}