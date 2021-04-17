'''
124. 二叉树中的最大路径和
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。
'''
# Definition for a binary tree node.
# 和543二叉树的直径一样都是树形dp的题目。
import sys
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        res = -sys.maxsize -1
        def dfs(node):
            nonlocal res
            if not node: return 0
            left= max(dfs(node.left),0)
            right = max(dfs(node.right),0)
            res = max(res,left+right+node.val)
            return max(left,right)+node.val

        dfs(root)
        return res
