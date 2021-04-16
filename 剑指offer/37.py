# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root: return "[]"
        que = [root]
        res=[]
        while que:
            node = que.pop(0)  
            if node:
                res.append(str(node.val))
                que.append(node.left)
                que.append(node.right)
            else:
                res.append("null")
        return "["+",".join(res)+"]" # 会多输出null，但是不要紧只要反序列化成正确的🌲即可

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data=="[]":return
        vals,i = data[1:-1].split(","),1
        root = TreeNode(int(vals[0]))
        que = [root]
        while que:
            node = que.pop(0)
            if(vals[i]!="null"):
                node.left = TreeNode(int(vals[i]))
                que.append(node.left)
            i+=1
            if(vals[i]!="null"):
                node.right = TreeNode(int(vals[i]))
                que.append(node.right)
            i+=1
        return root


        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))