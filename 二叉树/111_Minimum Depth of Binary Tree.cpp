/** 给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
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
//递归
int myDepth(TreeNode* node){
    if(node == nullptr) return 0;
    int leftDepth = myDepth(node->left);
    int rightDepth = myDepth(node->right);
    if(node->right==nullptr and node->left!=nullptr) return 1+leftDepth;
    if(node->right!=nullptr and node->left==nullptr) return 1+rightDepth;
    int depth = 1+min(leftDepth,rightDepth);
    return depth;

}
int minDepth(TreeNode* root) {
    return myDepth(root);

}

// 迭代：层序遍历记录第一个没有左右孩子节点的层数即为最小深度
int minDepth(TreeNode* root) {
    queue<TreeNode*> que;
    if(root) que.push(root);
    int dep = 0;
    while(!que.empty()){
        dep ++;
        int size = que.size();
        for(int i =0;i<size;i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left == nullptr and node->right==nullptr) return dep;
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return dep;

}
