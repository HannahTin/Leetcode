/**
找树左下角的值

给定一个二叉树，在树的最后一行找到最左边的值。
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
int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res=0;
        while(!que.empty()){
            int size = que.size();
            for(int i =0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) res = node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
        }
        return res;

        
    }