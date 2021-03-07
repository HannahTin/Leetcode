// 给定一个二叉树，检查它是否是镜像对称的。

using namespace std;
#include <vector>
#include <algorithm> 
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//   递归写法
bool mySymmetric(TreeNode* node1,TreeNode* node2){
    if(node1 == nullptr and node2 == nullptr) return true;
    else if(node1 != nullptr and node2 == nullptr) return false;
    else if(node1 == nullptr and node2 != nullptr) return false;
    else if (node1->val != node2->val) return false;
    else if (mySymmetric(node1->left,node2->right) and mySymmetric(node1->right, node2->left)) return true;
    else return false;

}
bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return mySymmetric(root->left,root->right);

}

//  迭代写法
bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode* node1 = st.top();
            st.pop();
            TreeNode* node2 = st.top();
            st.pop();
            if(node1 == nullptr and node2 == nullptr) continue;
            if ((!node1 || !node2 || (node1->val != node2->val))) { 
                return false;
            }
            st.push(node1->right);
            st.push(node2->left);
            st.push(node1->right);
            st.push(node2->left);
        }
        return true;
    }
