/*
56. 合并区间

以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/
using namespace std;
#include <vector>
// 首先，将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：

// 如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
// 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(int i=0;i<intervals.size();i++){
            if(!merged.size() || merged.back()[1]< intervals[i][0]){
                merged.push_back(intervals[i]);
            }
            else{
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }

        }
        return merged;

    }
};
// python版本
// class Solution:
//     def merge(self, intervals: List[List[int]]) -> List[List[int]]:
//         intervals.sort(key=lambda x: x[0])
//         merged = []
//         for i in range(len(intervals)):
//             if not merged or merged[-1][1]<intervals[i][0]:
//                 merged.append(intervals[i])
//             else:
//                 merged[-1][1] = max(merged[-1][1],intervals[i][1])
//         return merged