/**
丢失的数字

题目描述：
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
**/
// 本题并不难，哈希表便可以实现O(n)和O(n)的时间和空间复杂度，
// 难点在于能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
// 答案就是位运算

// 哈希法，这里我采用数组的哈希实现
int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> assist(n+1);
        for (int i =0;i<n;i++){
            assist[nums[i]]=1;
        }
        for (int i =0;i<= n;i++){
            if(assist[i] == 0)
                return i;
        }
        return 0;

}
