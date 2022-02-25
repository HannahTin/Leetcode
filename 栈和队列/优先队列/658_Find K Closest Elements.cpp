/*
658. 找到 K 个最接近的元素


给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
*/
using namespace std;
#include <vector>
#include<queue>
// 首先是用最大堆实现的
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> que;
        for (int i = 0; i < k; ++i) {
            que.emplace(abs(arr[i]-x),i);
        }
        for (int i = k; i < arr.size(); ++i) {
            int dist = abs(arr[i]-x);
            if ((dist < que.top().first) || (dist==que.top().first && i<que.top().second)) {
                que.pop();
                que.emplace(dist, i);
            }
        }
        vector<int> ret(k);
        for (int i = 0; i <k; i++) {
            ret[i] = arr[que.top().second];
            que.pop();
        }
        sort(ret.begin(),ret.end());
        return ret;

    }
};
// 利用数组的已排序特性，采用二分
// 二分查找大小为k的所有窗口的左边界
// 下面是左闭右开写法
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        // 返回从low开始的k长度的数组
        return vector<int>(arr.begin() + l, arr.begin() + k + l);

    }
};