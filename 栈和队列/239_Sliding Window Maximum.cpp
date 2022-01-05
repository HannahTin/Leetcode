/**
滑动窗口最大值

题目描述：
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。
**/
// 单调队列,首先定义单调队列
#include <vector>
#include<iostream>
#include <deque>
using namespace std;
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }
    
    int max() { return data.front(); }
    
    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //先填满窗口的前 k - 1
            window.push(nums[i]);
        } else { // 窗口向前滑动
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res;
    int k =3;
    res = maxSlidingWindow(nums,k);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<endl;
    } // [3,3,5,5,6,7]

}