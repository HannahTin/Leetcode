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
//迭代写法，更新保存每一行的第一个节点值。
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
// 递归写法，找到深度最大的叶子节点，那么如果找最左边的呢？可以使用前序遍历，这样才先优先左边搜索，然后记录深度最大的叶子节点。
class Solution {
private:
    int maxLen = INT_MIN;
    int leftvalue;
    void traversal(TreeNode* node,int leftLen){
        if(node->left == nullptr and node->right==nullptr){
            if(leftLen>maxLen){
                maxLen = leftLen;
                leftvalue = node->val;
            }
            return; //中
        }
        if(node->left){ //左
            leftLen ++;
            traversal(node->left, leftLen);
            leftLen --;
        }
         if(node->right){ //右
            leftLen ++;
            traversal(node->right, leftLen);
            leftLen --;
        }
        return;


    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root,0);
        return leftvalue;
    }
};