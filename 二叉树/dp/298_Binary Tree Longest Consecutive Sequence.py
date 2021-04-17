'''
298. 二叉树最长连续序列(只可以父子顺序)
给你一棵指定的二叉树，请你计算它最长连续序列路径的长度。

该路径，可以是从某个初始结点到树中任意结点，通过「父 - 子」关系连接而产生的任意路径。

这个最长连续的路径，必须从父结点到子结点，反过来是不可以的。
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        res = 0
        def dfs(node):
            nonlocal res
            if not node: return 0
            left =dfs(node.left)+1
            right=dfs(node.right)+1
            if(node.left and node.left.val-node.val != 1): left = 1
            if(node.right and node.right.val-node.val != 1): right = 1
            res = max(res,max(left,right))
            return max(left,right)

        
        dfs(root)
        return res