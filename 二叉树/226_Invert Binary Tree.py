# 翻转二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

void reverse(TreeNode* node){
    if(node==nullptr) return;
    swap(node->left,node->right);
    reverse(node->left);
    reverse(node->right);

}

TreeNode* invertTree(TreeNode* root) {
    reverse(root);
    return root;

}