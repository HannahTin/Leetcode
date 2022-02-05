/*
二叉树的最近公共祖先

题目描述：
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/
using namespace std;
#include <vector>
#include <algorithm> 
#include <unordered_set>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
/*
归纳如下三点：

求最小公共祖先，需要从底向上遍历，那么二叉树，只能通过后序遍历（即：回溯）实现从低向上的遍历方式。

在回溯的过程中，必然要遍历整颗二叉树，即使已经找到结果了，依然要把其他节点遍历完，因为要使用递归函数的返回值（也就是代码中的left和right）做逻辑判断。

要理解如果返回值left为空，right不为空为什么要返回right，为什么可以用返回right传给上一层结果。
*/
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q || root==nullptr) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        if (left == nullptr) return right;
        return left;  
    }
};
/*
下面给出c++写法，只要二叉树中节点都不相同，可以求出任意m个节点的最近公共祖先
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。

参考：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/er-cha-shu-de-zui-jin-gong-gong-zu-xian-by-leetc-2/​	
时间复杂度：O(N)，其中 N 是二叉树的节点数。二叉树的所有节点有且只会被访问一次，因此时间复杂度为 O(N)。

空间复杂度：O(N)，其中 N 是二叉树的节点数。递归调用的栈深度取决于二叉树的高度，二叉树最坏情况下为一条链，此时高度为 N，因此空间复杂度为 O(N)O(N)。
*/
class Solution2 {
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
