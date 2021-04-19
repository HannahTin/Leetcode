/**
1372. 二叉树中的最长交错路径
给你一棵以 root 为根的二叉树，二叉树中的交错路径定义如下：

选择二叉树中 任意 节点和一个方向（左或者右）。
如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。
改变前进方向：左变右或者右变左。
重复第二步和第三步，直到你在树中无法继续移动。
交错路径的长度定义为：访问过的节点数目 - 1（单个节点的路径长度为 0 ）。

请你返回给定树中最长 交错路径 的长度。
**/
// 思路：记录当前结点是左/右孩子，即记录当前路径的方向;搜索其孩子时，根据上一条路径方向判断;如果当前路径方向相反，路径长度+1，如果相同，路径长度置为1
// 代码参考了题解，真的妙！
using namespace std;
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int res=0;
    void dfs(TreeNode* root,int flag,int dis){//(当前结点，左/右孩子，路径长度)
        if(!root)return;//空结点返回
        res=max(res,dis);//更新最大值
        if(flag){//如果当前结点是其父结点的右孩子
            dfs(root->left,0,dis+1);//搜索其左孩子时，满足ZigZig，路径长度+1
            dfs(root->right,1,1);//搜索其右孩子时，不满足ZigZig，路径长度置为1
        } 
        else{//如果当前结点是其父结点的左孩子
            dfs(root->left,0,1);//搜索其左孩子时，不满足ZigZig，路径长度置为1
            dfs(root->right,1,dis+1);//搜索其右孩子时，满足ZigZig，路径长度+1
        }       
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left,0,1);//0左节点
        dfs(root->right,1,1);//1右结点
        return res;
    }
};