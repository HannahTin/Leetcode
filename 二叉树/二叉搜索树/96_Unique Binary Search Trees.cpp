/**
不同的二叉搜索树
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
输入：n = 1
输出：1
**/
using namespace std;
#include <vector>

// dp
// G(n): 长度为 n 的序列能构成的不同二叉搜索树的个数。
// F(i,n): 以 i 为根、序列长度为 n 的不同二叉搜索树个数 (1≤i≤n)。
// G(n)= (i=1)∑(n) F(i,n)
// 对于边界情况，当序列长度为 1（只有根）或为 0（空树）时，只有一种情况，即：G(0)=1,G(1)=1
// F(i,n)=G(i−1)⋅G(n−i)
// 结合两个公式得到：G(n)= （i=1）∑（n）G(i−1)⋅G(n−i)
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

// 数学方法：卡特兰数
// C0=1， C_{n+1} = 2(2n+1)/(n+2) * C_n
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
