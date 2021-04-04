/**
路径总和（是否存在）

题目描述：
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

叶子节点 是指没有子节点的节点。。
 * */

using namespace std;
#include <algorithm> 
#include <queue>
#include <vector>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root== nullptr) return false;
    if(root->left == nullptr and root->right==nullptr) return root->val == targetSum;
    return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);


}