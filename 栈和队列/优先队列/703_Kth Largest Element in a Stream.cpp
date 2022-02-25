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
