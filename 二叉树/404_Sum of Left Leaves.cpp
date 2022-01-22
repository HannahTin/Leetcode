/**
左叶子之和
计算给定二叉树的所有左叶子之和。
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
// 递归写法，注意左叶子节点的判断。
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
//层序遍历
class Solution {
private:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        if(root==nullptr) return sum;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if (node->left) {
                if (isLeafNode(node->left)) {
                    sum += node->left->val;
                }
                else {
                    que.push(node->left);
                }
            }
            if (node->right) {
                que.push(node->right);

            }

        }
        return sum;

    }
};