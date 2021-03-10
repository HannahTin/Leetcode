'''
二叉树中和为某一值的路径
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
'''
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def FindPath(self,node: TreeNode,path:list,result:list,target:int):
        path.append(node.val)
        target -= node.val
        if(node.left==None and node.right==None and target ==0):
            result.append(list(path))
        if(node.left):
            self.FindPath(node.left,path,result,target)
            path.pop()
        if(node.right):
            self.FindPath(node.right,path,result,target)
            path.pop()


    def pathSum(self,root: TreeNode, target: int) -> List[List[int]]:
        path,result =[],[]
        if root==None: return result
        self.FindPath(root,path,result,target)
        return result
