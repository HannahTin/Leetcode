'''
剑指 Offer 33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
'''

def verifyPostorder(self, postorder: list) -> bool:
    if not postorder: return True
    root = postorder[-1]
    left = 0
    for i in range(len(postorder)):
        if(postorder[i]<root):
            left += 1
        else:
            break
    for j in range(left,len(postorder)-1):
        if(postorder[j] < root):
            return False
    return self.verifyPostorder(postorder[0:left]) and self.verifyPostorder(postorder[left:len(postorder)-1])

