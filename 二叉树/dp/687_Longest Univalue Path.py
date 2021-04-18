'''
最长同值路径
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        res = 0
        def dfs(node):
            nonlocal res
            if not node: return 0
            left = dfs(node.left)
            right = dfs(node.right)
            arrowLeft = arrowRight = 0
            if(node.left and node.left.val == node.val): arrowLeft += left+1
            if(node.right and node.right.val == node.val): arrowRight += right+1
            res = max(res,arrowLeft+arrowRight)
            return max(arrowLeft,arrowRight)
        dfs(root)
        return res