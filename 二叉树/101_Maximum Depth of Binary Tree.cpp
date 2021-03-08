/**
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

**/

using namespace std;
#include <algorithm> 
#include <queue>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// 递归写法
int myDepth(TreeNode* node){
    if(node==nullptr) return 0;
    int leftDepth = myDepth(node->left);
    int rightDepth = myDepth(node->right);
    int depth = 1+ max(leftDepth,rightDepth);
    return depth;

}
int maxDepth(TreeNode* root) {
    return myDepth(root);
}
// 迭代写法：层序遍历的层数即为最大深度
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    queue<TreeNode*> que;
    int depth = 0;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i=0;i<size;i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        depth += 1; 
    }
    return depth;

}
