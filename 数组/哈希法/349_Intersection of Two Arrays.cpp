/**
两个数组的交集

题目描述：
给定两个数组，编写一个函数来计算它们的交集。
说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
**/
// python实现（set）很是简单，下面用c++ unordered_set实现。
// 不管用什么语言实现，思路都是一样的：由于要求输出结果中每个元素一定是唯一的，因此肯定需要set数据结构。交集即即在nums1又在nums2中的数字集合。
// 因此只要找到nums2在nums1的set中出现过的数字即可。
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> res_set;
    unordered_set<int> nums_set(nums1.begin(),nums1.end());
    for(int num:nums2){
        if(nums_set.find(num) != nums_set.end()){
            res_set.insert(num);
        }
            
    }
    return vector<int>(res_set.begin(), res_set.end());
}
 int main(){
    vector<int> res;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    res=intersection(nums1,nums2);
    for(int i:res)
        cout<<i<< " "; // 4,9


 }