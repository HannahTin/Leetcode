// 翻转二叉树
// 即把每个节点的左右孩子翻转一下就可以达到整体翻转的效果/
// 由于树的测试用例初始化对于刷题阶段实在耽误时间，所以本源代码不能直接运行，只能leetcode官网提交通过。
using namespace std;
#include <vector>
#include <algorithm> 
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
