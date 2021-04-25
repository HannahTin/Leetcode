/**
存在重复元素III

题目描述：
给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

示例 1：

输入：nums = [1,2,3,1], k = 3, t = 0
输出：true
**/
// 时间复杂度：Set 基于红黑树，查找和插入都是 O(logk) 复杂度。整体复杂度为 O(nlogk)
// 空间复杂度：O(k)

using namespace std;
#include <vector>
#include <set>
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        for (int i = 0; i < nums.size(); i++) {
            auto lb = st.lower_bound((long)nums[i] - t);
            if (lb != st.end() && *lb <= (long)nums[i] + t) return 1;
            st.insert(nums[i]);
            if (i >= k) st.erase(nums[i - k]);
        }
        return 0;
    }
};
