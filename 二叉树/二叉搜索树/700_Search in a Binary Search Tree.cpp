/**
700. 二叉搜索树中的搜索
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
**/
using namespace std;
#include <vector>
#include <stack>
// 迭代实现，其实就是中序遍历！
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 递归方法
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;
    if (root->val > val) return searchBST(root->left, val);// 找到了就返回
    else if (root->val < val) return searchBST(root->right, val);
    else return root;
}

/**
迭代方法
TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
**/