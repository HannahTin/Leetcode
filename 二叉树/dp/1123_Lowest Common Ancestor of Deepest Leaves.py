'''
1123. 最深叶节点的最近公共祖先
给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。

回想一下：

叶节点 是二叉树中没有子节点的节点
树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    # 但这种计算会存在节点的重复深度计算
    # 时间复杂度：O(n^2)。getDepth 函数在最坏情况下的复杂度为 O(n)。最坏情况下，调用 lca 函数 O(n) 次。
    # 空间复杂度：O(n)。最坏情况下的递归深度为 O(n)

    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
            def dfs(node):
                if not node: return 0
                left = dfs(node.left)
                right = dfs(node.right)
                return max(left,right)+1
            if not root: return None
            nleft = dfs(root.left)
            nright = dfs(root.right)
            if(nleft == nright): return root
            elif(nleft>nright): return self.subtreeWithAllDeepest(root.left)
            elif(nleft<nright): return self.subtreeWithAllDeepest(root.right)
    # 每次计算是否包含最深叶节点的开销有点接受不了了，我们是否有机会优化这部分开销，答案是肯定的。
    # 利用后序遍历，我们可以把复杂度降到 O(n)。下面附c++代码。在自下而上的后序遍历过程中记录高度值，避免重复运算。
    '''
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* dfs(TreeNode* node,int& height){
        if(!node) return nullptr;
        int lh=0,rh=0;
        TreeNode* left_node = dfs(node->left,lh);
        TreeNode* right_node = dfs(node->right,rh);
        height = max(lh,rh)+1;
        if(lh == rh) return node;
        else if(lh>rh) return left_node;
        else return right_node;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = 0;
        return dfs(root,height);
    }
};
    '''
