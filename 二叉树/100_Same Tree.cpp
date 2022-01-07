/**
100. 相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
**/

//  Definition for a binary tree node.
using namespace std;
#include <vector>
#include <algorithm> 
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//  本题和101对称二叉树基本一致
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==nullptr) return true;
        else if(p==nullptr and q!=nullptr) return false;
        else if(p!=nullptr and q==nullptr) return false;
        else if(p->val != q->val) return false;
        bool leftside = isSameTree(p->left,q->left);
        bool rightside = isSameTree(p->right,q->right);
        return leftside&&rightside;
    }
    // 迭代写法
     bool isSameTree2(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode* rightnode = que.front();que.pop();
            TreeNode* leftnode = que.front();que.pop();
            if(rightnode==nullptr and leftnode==nullptr) continue;
            else if(rightnode==nullptr and leftnode!=nullptr) return false;
            else if (rightnode!=nullptr and leftnode==nullptr) return false;
            else if(rightnode->val!=leftnode->val) return false;
            que.push(rightnode->left);
            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);

        }
        return true;

    }
};
