/**
把数组排成最小的数

题目描述：
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

 

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
**/
using namespace std;
#include <string>
#include <vector>
// 字典序排序，使用内置函数
// C++ 定义为 (string& x, string& y){ return x + y < y + x; } ；
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });
        for(int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};
//快排 时间复杂度 O(NlogN) 空间复杂度 O(N)
class Solution {
private:
    void swap(vector<string>& lyst, int i,int j){
        string tmp = lyst[i];
        lyst[i] = lyst[j];
        lyst[j] = tmp;

    }
    int partition(vector<string>& lyst,int left,int right){
        string pivot = lyst[left];
        lyst[left] = lyst[right];
        lyst[right] = pivot;
        int boundary = left;
        for(int index=left;index<right;index++){
            if(lyst[index]+pivot<pivot+lyst[index]){ //和原始快排代码相比，基本只改了这里，具体证明可以参考热门题解
            // https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
                swap(lyst,index,boundary);
                boundary ++;
            }
        }
        swap(lyst,right,boundary);
        return boundary;
    }
    void quickSortHelper(vector<string>& lyst,int  left,int right){
        if(left<right){
            int pivotLocation = partition(lyst,left,right);
            quickSortHelper(lyst,left,pivotLocation-1);
            quickSortHelper(lyst,pivotLocation+1,right);


        }
    }
    void quickSort(vector<string>& lyst){
        quickSortHelper(lyst,0,lyst.size()-1);
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        quickSort(strs);
        string res;
        for(string s : strs)
            res.append(s);
        return res;
    }
};