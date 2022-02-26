using namespace std;
#include <vector>
#include <queue>
/*
253. 会议室 II

给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

 

示例 1：

输入：intervals = [[0,30],[5,10],[15,20]]
输出：2
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        /**
         * 按照会议开始时间从小到大 将会议排序！
         */
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i = 0;i < n;i++){
            if (!que.empty()) {
                int poll = que.top();
                if (poll <= intervals[i][0]) {
                     /**
                     * 说明当前开会时间时，最近结束的会议还未结束
                     * 所以需要新增会议室！
                     */
                    que.pop();
                }
            }
            que.emplace(intervals[i][1]);
        }
        return que.size();

    }
};