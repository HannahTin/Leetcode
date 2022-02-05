/**
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

输入：root = [3,4,5,1,2], subRoot = [4,1,2]
输出：true
**/
using namespace std;
#include <algorithm> 
#include <queue>
#include <vector>
#include <string>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//  要判断一个树 t 是不是树 s 的子树，那么可以判断 t 是否和树 s 的任意子树相等。那么就转化成 100. Same Tree。
// 即，这个题的做法就是在 s 的每个子节点上，判断该子节点是否和 t 相等。

// 判断两个树是否相等的三个条件是与的关系，即：

// 当前两个树的根节点值相等；
// 并且，s 的左子树和 t 的左子树相等；
// 并且，s 的右子树和 t 的右子树相等。

// 而判断 t 是否为 s 的子树的三个条件是或的关系，即：

// 当前两棵树相等；
// 或者，t 是 s 的左子树；
// 或者，t 是 s 的右子树。

class Solution {
public:
    bool isSametree(TreeNode* p, TreeNode* q) {
        if(p==nullptr and q==nullptr) return true;
        else if(p==nullptr and q!=nullptr) return false;
        else if(p!=nullptr and q==nullptr) return false;
        else if(p->val != q->val) return false;
        bool leftside = isSametree(p->left,q->left);
        bool rightside = isSametree(p->right,q->right);
        return leftside&&rightside;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        else if (root == NULL && subRoot != NULL) return false;
        return isSametree(root, subRoot) || isSubtree(root->left, subRoot) || isSametree(root->right, subRoot);
            



    }
};