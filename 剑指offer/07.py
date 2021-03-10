'''
重建二叉树

题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
'''
class TreeNode:
     def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None  

def buildTree(preorder: List[int], inorder: List[int]) -> TreeNode:
    if not preorder or not inorder: return None
    root = TreeNode(preorder[0])
    # 由于list.index时间复杂度为o(n): 284 ms	87 MB
    # 因此可以构建哈希表存inorder的element：index为o(1)耗时更短:64 ms	19.4 MB
    root.left = buildTree(preorder[1:inorder.index(preorder[0])+1], inorder[0:inorder.index(preorder[0])])
    root.right = buildTree(preorder[inorder.index(preorder[0])+1:],inorder[inorder.index(preorder[0])+1:])
    return root



r


# 前序遍历 preorder = [3,9,20,15,7]
# 中序遍历 inorder = [9,3,15,20,7]