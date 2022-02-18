'''
1120. 子树的最大平均值

给你一棵二叉树的根节点 root，找出这棵树的 每一棵 子树的 平均值 中的 最大 值。

子树是树中的任意节点和它的所有后代构成的集合。

树的平均值是树中节点值的总和除以节点数。

输入：[5,6,1]
输出：6.00000
解释： 
以 value = 5 的节点作为子树的根节点，得到的平均值为 (5 + 6 + 1) / 3 = 4。
以 value = 6 的节点作为子树的根节点，得到的平均值为 6 / 1 = 6。
以 value = 1 的节点作为子树的根节点，得到的平均值为 1 / 1 = 1。
所以答案取最大值 6。


'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        self.res = -float('inf')
        def traversal(root):
            if(root==None): return 0,0
            ls, ln = traversal(root.left)
            rs, rn = traversal(root.right)
            self.res = max(self.res,(ls+rs+root.val)/(ln+rn+1))
            return ls+rs+root.val, ln+rn+1
        traversal(root)
        return self.res

# c++解法
# struct TreeNode {
#      int val;
#      TreeNode *left;
#      TreeNode *right;
#      TreeNode() : val(0), left(nullptr), right(nullptr) {}
#      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
#  };

# class Solution {
# public:
#     double res = DBL_MIN;
#     pair<double,double> traversal(TreeNode* root){
#         if(root==nullptr) return {0,0};
#         auto lc = traversal(root->left);
#         auto rc = traversal(root->right);
#         res = max(res,(lc.first+rc.first+root->val)/(lc.second+rc.second+1));
#         return {lc.first+rc.first+root->val, lc.second+rc.second+1};

#     }
#     double maximumAverageSubtree(TreeNode* root) {
#         traversal(root);
#         return res;
#     }
# };