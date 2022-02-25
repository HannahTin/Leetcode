/*
703. 数据流中的第 K 大元素

设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：

KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
*/
using namespace std;
#include <queue>
#include <vector>
// 求排序后的第 k 大元素，也就是求最大的k个数中最小的那个。由此我们可以使用一个大小为k的小根堆来保存给定数组中最大的k个数，这样堆顶就是我们所求的元素。

// 为什么大小为k的小根堆中保存的是给定数组中最大的k个数？

// 因为数组中的元素不断插入堆的过程中，若堆已满，则弹出堆顶元素即最小的元素，所以再不断重复此操作后，小的元素都被弹出，剩下的就是给定数组中最大的k个数。


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> que;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++){
            que.emplace(nums[i]);
            if(que.size()>k){
                que.pop();
            }
        }
    }
    
    int add(int val) {
        if(que.empty() || que.size()<k) que.emplace(val);
        else if(val>que.top()){
            que.pop();
            que.emplace(val);
        }
        return que.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
