'''
下一个更大元素 I

题目描述：
给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中
'''
// 这个算法的时间复杂度不是那么直观，如果你看到 for 循环嵌套 while 循环，可能认为这个算法的复杂度也是 O(n^2)，但是实际上这个算法的复杂度只有 O(n)。
// 分析它的时间复杂度，要从整体来看：总共有 n 个元素，每个元素都被 push 入栈了一次，
// 而最多会被 pop 一次，没有任何冗余操作。所以总的计算规模是和元素规模 n 成正比的，也就是 O(n) 的复杂度。
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> hashmap;
        stack<int> st;
        // 倒着往栈里放
        for(int i = nums2.size()-1;i>=0;i--){
            while(!st.empty() and st.top()<= nums2[i]){
                st.pop();
            }
            int value = st.empty()?-1:st.top();
            hashmap.insert({nums2[i],value});
            st.push(nums2[i]);
        }
        for(int j = 0;j<nums1.size();j++){
            res.push_back(hashmap[nums1[j]]);
        }
        return res;


    }
