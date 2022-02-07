/*
538. 把二叉搜索树转换为累加树
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
*/
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
// 换一个角度来看，这就是一个有序数组[2, 5, 13]，求从后到前的累加数组，也就是[20, 18, 13]
class Solution {
private:
    int pre;
    void traversal(TreeNode* curr){
        if(curr==nullptr) return;
        traversal(curr->right);
        curr->val += pre;
        pre = curr->val;
        traversal(curr->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;

    }
};
// 迭代法:迭代法其实就是中序模板题了
class Solution {
private:
    int pre = 0;
    void traversal(TreeNode* node){
        stack<TreeNode*> st;
        TreeNode* curr = node;
        while(curr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr->right; //  右
            }
            else{
                curr = st.top();     // 中
                st.pop();
                curr->val += pre;
                pre = curr->val;
                curr = curr->left;    // 左
            }
        }
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;

    }
};