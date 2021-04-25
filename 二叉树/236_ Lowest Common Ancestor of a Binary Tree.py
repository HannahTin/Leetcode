'''
二叉树的最近公共祖先

题目描述：
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if root==None:
            return None
        if root.val == p.val or root.val == q.val:
            return root
        left = lowestCommonAncestor(root.left,p,q)
        right = lowestCommonAncestor(root.right,p,q)
        if not left and not right:return None
        if not left: return right
        if not right:return left
        return root
# 下面给出c++写法，只要二叉树中节点都不相同，可以求出任意m个节点的最近公共祖先
# 所有 Node.val 互不相同 。
# p != q
# p 和 q 均存在于给定的二叉树中。
'''
参考：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/​	
时间复杂度：O(N)，其中 N 是二叉树的节点数。二叉树的所有节点有且只会被访问一次，因此时间复杂度为 O(N)。

空间复杂度：O(N)，其中 NN 是二叉树的节点数。递归调用的栈深度取决于二叉树的高度，二叉树最坏情况下为一条链，此时高度为 N，因此空间复杂度为 O(N)O(N)。

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, unordered_set<TreeNode*>& vec) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left,vec);
        bool rson = dfs(root->right, vec);
        if ((lson && rson) || (vec.count(root) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || vec.count(root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> vec ={p,q};
        dfs(root,vec);
        return ans;
    }
};
'''