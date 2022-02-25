/*
347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
*/
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto& num : nums) {
            cnt[num]++;
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>,decltype(cmp)> que(cmp);
        for (auto& it : cnt) {
            que.emplace(it);
            if (que.size()> k) {
                que.pop();
            }
        }
        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = que.top().first;
            que.pop();
        }
        return ret;

    }
};