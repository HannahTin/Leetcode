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
//递归写法
class Solution {
private:
    int targetSum;
public:
    bool traversal(TreeNode* node,int currSum){
        if(node->left ==nullptr and node->right == nullptr){
            if(currSum == targetSum) return true;
        }
        if(node->left){
            currSum += node->left->val;
            if(traversal(node->left, currSum)) return true;
            currSum -= node->left->val;
        }
        if(node->right){
            currSum += node->right->val;
            if(traversal(node->right, currSum)) return true;
            currSum -= node->right->val;
        }
        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        this->targetSum = targetSum;
        return traversal(root,root->val);
    }
};
// 迭代写法:如果用栈模拟回溯，栈里一个元素不仅要记录该节点指针，还要记录从头结点到该节点的路径数值总和。
// c++定义为：pair<treenode*, int> pair<节点指针，路径数值>
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        stack<pair<TreeNode*,int>> st;
        st.push(pair<TreeNode*,int>(root,root->val));
        while(!st.empty()){
            pair<TreeNode*,int> node = st.top();
            st.pop();
            if(node.first->left==nullptr and node.first->right==nullptr and node.second==targetSum) return true;
            if(node.first->left){
                st.push(pair<TreeNode*,int>(node.first->left,node.second+node.first->left->val));

            }
            if(node.first->right){
                st.push(pair<TreeNode*,int>(node.first->right,node.second+node.first->right->val));
            }

        }
        return false;

    }
};


