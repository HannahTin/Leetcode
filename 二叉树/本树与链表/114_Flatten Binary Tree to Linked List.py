'''
114. 二叉树展开为链表
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
'''
# Definition for a binary tree node.
# 思路：将二叉树的前序遍历指针保存在数组中，然后再进行展开为链表
# 时间复杂度：O(n)，其中 n 是二叉树的节点数。前序遍历的时间复杂度是 O(n)，前序遍历之后，需要对每个节点更新左右子节点的信息，
# 时间复杂度也是 O(n)O。

# 空间复杂度：O(n)，其中 n 是二叉树的节点数。空间复杂度取决于栈（递归调用栈或者迭代中显性使用的栈）和存储前序遍历结果的列表的大小，
# 栈内的元素个数不会超过 n，前序遍历列表中的元素个数是 n。

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        preorderList = list()
        def traversal(root):
            if not root: return
            preorderList.append(root)
            traversal(root.left)
            traversal(root.right)

        traversal(root)
        for i in range(1,len(preorderList)):
            prev,curr = preorderList[i-1],preorderList[i]
            prev.left = None
            prev.right = curr

#  此外还有一种时间复杂度为O(n)，空间复杂度为O(1)的解法
#  当前节点的左子树不为空，则左子树的最右边节点为当前节点右子树的前驱节点。
'''
class Solution:
    def flatten(self, root: TreeNode) -> None:
        curr = root
        while curr:
            if curr.left:
                predecessor = nxt = curr.left
                while predecessor.right:
                    predecessor = predecessor.right
                predecessor.right = curr.right
                curr.left = None
                curr.right = nxt
            curr = curr.right
'''
