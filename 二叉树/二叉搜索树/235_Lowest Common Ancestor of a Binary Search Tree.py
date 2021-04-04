'''
二叉搜索树的最近公共祖先

题目描述：
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# 递归写法：如果根节点比p和q的值都大，则p和q在根节点的左子树中，都小则在右子树中。否则返回root。
def lowestCommonAncestor(root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    if(root ==None): return None
    if(root.val> p.val and root.val>q.val):
        return  lowestCommonAncestor(root.left,p,q)
    elif(root.val< p.val and root.val<q.val):
        return lowestCommonAncestor(root.right,p,q)
    else:
        return root

