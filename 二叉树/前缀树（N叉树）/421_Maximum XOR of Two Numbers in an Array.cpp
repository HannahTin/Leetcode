/**
421. 数组中两个数的最大异或值
给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

进阶：你可以在 O(n) 的时间解决这个问题吗？
**/
// 思路： 将所有数字转化成二进制形式。 将数字的二进制形式加入字典树，同时计算该数字在字典树中所能得到的最大异或值。
// 再用该数字的最大异或值尝试性更新 max_xor。返回 max_xor。
// 时间复杂度：O(N)。在字典树插入一个数的时间复杂度为 O(L)，找到一个数的最大异或值时间复杂度也为 O(L)。其中 L = 1 + [log2M]，M为数组中的最大数值，这里可以当做一个常量。因此最终时间复杂度为 O(N)。

// 空间复杂度：O(1)。维护字典树最多需要 O(2^L) = O(M) 的空间，但由于输入的限制，这里的 L 和 M 可以当做常数。

using namespace std;
#include <map>
#include <string>
#include <vector>
class Trie
{
private:
    Trie* next[2]={nullptr};
public:
    Trie(){}

    void insert(int x)  // 在前缀树中插入值x
    {
        Trie *root=this;
        // 高位存储来Trie的前面，所以我们从左向右存储
        for(int i=30;i>=0;i--)
        {
            // 取第i位的数字，30...0
            int u=x>>i&1;
            // 若第u位为空，则创建一个新节点，然后root移动到下一个节点
            if(!root->next[u])root->next[u]=new Trie();
            root=root->next[u];
        }
    }

    int search(int x)  // 在前缀树中寻找 x 的最大异或值
    {
        Trie *root=this;
        // res表示最大异或值，每次res*2表示左移一位，31循环后左移了31位了，+u表示加上当前的最低位数字
        int res=0;
        for(int i=30;i>=0;i--)
        {
            int u=x>>i&1;
            // 若 x 的第 u 位存在，我们走到相反的方向去，因为异或总是|值|相反才取最大值的
            if(root->next[!u])root=root->next[!u],res=res*2+!u;
            // 相反方向的节点为空，只能顺着相同方向走了
            else root=root->next[u],res=res*2+u;
        }
        // 由于上面我们得到的异或另一个数组元素，此时我们需要将这个数组元素与x异或得到 两个数的最大异或值
        res^=x;
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root=new Trie();
        for(auto x:nums)root->insert(x);
        int res=0;
        for(auto x:nums)
            res=max(res,root->search(x));
        return res;
    }
};