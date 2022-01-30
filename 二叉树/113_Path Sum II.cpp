/**
路径之和（找到所有路径）

题目描述：
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。
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
class Solution {
private:
    vector<vector<int>> res;
public:
    void myPath(TreeNode* root,vector<int> ans,int targetSum){
        ans.push_back(root->val);
        if(root->left ==nullptr and root->right==nullptr and targetSum==root->val){
            res.push_back(ans);
        }
        if(root->left !=nullptr) myPath(root->left,ans,targetSum-root->val);
        if(root->right !=nullptr) myPath(root->right,ans,targetSum-root->val);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return res;
        myPath(root,{},targetSum);
        return res;     
    }
};