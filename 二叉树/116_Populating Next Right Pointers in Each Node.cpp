/**
填充每个节点的下一个右侧节点指针
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
**/
using namespace std;
#include <queue>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* node;
            Node* pre;
            for(int i=0;i<size;i++){
                if(i==0){
                    pre = que.front();
                    que.pop();
                    node = pre;
                }
                else{
                    node = que.front();
                    que.pop();
                    pre->next = node; // 本层前一个节点next指向本节点
                    pre = pre->next;

                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            pre->next = NULL;
        }
        return root;

        
    }
};
// 递归解法
/**
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root==None: return
        if(root.left):
            root.left.next = root.right
            root.right.next = None if root.next ==None else root.next.left
        self.connect(root.left)
        self.connect(root.right)
        return root
 **/
