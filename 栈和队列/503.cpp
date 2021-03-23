/**
下一个更大元素 II
题目描述：
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，
这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
// 相比496题来说，本题唯一的不同的是数组可以循环。可以利用取模进行模拟。
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = 2*n-1;i>=0;i--){
        while(!st.empty() and st.top()<= nums[i%n]){
            st.pop();
        }
        res[i%n] = st.empty()?-1:st.top();
        st.push(nums[i%n]);
    }
    return res;
}
