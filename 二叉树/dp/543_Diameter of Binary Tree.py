'''
543. 二叉树的直径
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
'''
# 🌲形dp问题：这一类问题通常的解决的思路是：通过对树结构执行一次深度优先遍历，采用 后序遍历 的方式，一层一层向上传递信息，
# 并且利用「无后效性」的思想（固定住一些状态，或者对当前维度进行升维）解决问题。即这一类问题通常采用「后序遍历」 + 「动态规划（无后效性）」的思路解决。
# 时间复杂度：O(N)O(N)，这里 NN 是树的结点总数；
# 空间复杂度：O(N)O(N)，空间复杂度取决于递归调用栈的深度。
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        res = 0
        def dfs(node):
            nonlocal res
            if (node == None): return 0
            left = dfs(node.left)
            right = dfs(node.right)
            res = max(res,left+right)
            return max(left,right)+1
        dfs(root)
        return res