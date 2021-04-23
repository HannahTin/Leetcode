// BST插入操作的迭代写法
// 其实和插入的递归写法是一样的。注意二叉树递归的特性。
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* curr = root;
        TreeNode* parent;
        while(curr!=nullptr){
            parent = curr;
            if(curr->val < val) curr = curr->right;
            else if(curr->val > val) curr = curr->left;
        }
        TreeNode* node = new TreeNode(val);
        if (val > parent->val) parent->right = node;
        else parent->left = node;
        return root;



    }
};
