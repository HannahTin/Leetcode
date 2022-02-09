/*
435. 无重叠区间

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
*/
using namespace std;
#include<vector>
// 正确的思路其实很简单，求解最多有几个互不相交的区间，可以分为以下三步：

// 从区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。
// 把所有与 x 区间相交的区间从区间集合 intvs 中删除。
// 重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
// 把这个思路实现成算法的话，可以按每个区间的 end 数值升序排序，因为这样处理之后实现步骤 1 和步骤 2 都方便很多:

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [this](vector<int>& p1, vector<int>& p2){
            return p1[1]<p2[1]; 
        });
        int count = 1;
        int x_end = intervals[0][1];
        for(auto& interv:intervals){
            int start = interv[0];
            if(start>=x_end){
                count ++;
                x_end = interv[1];
            }
        }
        return n-count;
      
        

    }
};