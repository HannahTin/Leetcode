/**
二叉树的所有路径

题目描述：
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
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
 // 回溯法（递归和回溯就是一家的，回溯和递归是一一对应的，有一个递归就要有一个回溯
void buildPath(TreeNode* node,string path,vector<string>& paths){ // 注意这里定义的是string path，每次都是复制赋值，不用使用引用，否则就无法做到回溯的效果。
        path+=to_string(node->val);
        if(node->left==nullptr and node->right==nullptr) paths.push_back(path);
        else{
            path+="->";
            buildPath(node->left,path,paths); // 每次都是复制赋值，否则无法达到回溯的效果。
            buildPath(node->right,path,paths);
        }

}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    string path;
    if(root == nullptr) return paths;
    buildPath(root,path,paths);
    return paths;

}
// 同样采用前序遍历，有两个栈，一个保存遍历节点，一个保存遍历路径
vector<string> binaryTreePaths(TreeNode* root) {
    stack<TreeNode*> st;
    stack<string> pst;
    vector<string> result;
    if(root==nullptr) return result;
    st.push(root);
    pst.push(to_string(root->val));
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        string path = pst.top();
        pst.pop();
        if(node->left == nullptr and node->right==nullptr) result.push_back(path);
        if(node->right){
            st.push(node->right);
            pst.push(path+"->"+to_string(node->right->val));
        }
        if(node->left){
            st.push(node->left);
            pst.push(path+"->"+to_string(node->left->val));
        }
    }
    return result;


}