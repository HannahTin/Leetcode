/**
左叶子之和
计算给定二叉树的所有左叶子之和。
**/
using namespace std;
#include <algorithm> 
#include <stack>
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
int sum =0;
void mySum(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL and root->left->left==NULL and root->left->right==NULL) 
            sum+= root->left->val;
        mySum(root->left);
        mySum(root->right);

    }
int sumOfLeftLeaves(TreeNode* root) {
    mySum(root);
    return sum;

}