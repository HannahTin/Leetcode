/**
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
**/
//  思路：这里强调一下概念就是前面求的二叉树的深度问题是指根节点到叶子节点所经过路径上的节点个数。
// 求解最大深度就是根节点到叶子节点的最远路径上的节点个数；最小深度就是根节点到叶子节点最短路径上的节点个数。
// 我们可以用递归或者层序遍历很方便的写出来。
// 而本题中的高度是指叶子节点到某个节点的所经路径节点数。也就是说深度是从根节点开始算的，高度是从叶子节点开始算的。
using namespace std;
#include <algorithm> 
#include <queue>
#include <vector>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//  递归
 int getHeight(TreeNode* node){
     if (node==nullptr) return 0;
     int leftHeight = getHeight(node->left);
     if(leftHeight == -1) return -1;
     int rightHeight = getHeight(node->right);
     if(rightHeight == -1) return -1;
     return abs(leftHeight-rightHeight)>1?-1:1+max(leftHeight,rightHeight);
     

 }
bool isBalanced(TreeNode* root) {
    return getHeight(root) !=- 1?true:false;

}
// 这里迭代就不能直接用层序遍历求解了，因为层序是从上到下一层层计算。我们可以先前序遍历每一个节点的左右子树是不是balanced，
// 求解每个节点的左右子树的高度时候呢，就可以按照以该节点为根节点的树的最大深度来做，这时候就可以快乐的层序遍历了。
int getMaxiMumDepth(TreeNode* node ){
    if(node==nullptr) return 0;
    queue<TreeNode*> que;
    que.push(node);
    int layer = 0;
    while(!que.empty()){
        int size = que.size();
        for(int i=0;i<size;i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        layer += 1;
    }
    return layer;

}
bool isBalanced(TreeNode* root) {
    if(root==nullptr) return true;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        if(abs(getMaxiMumDepth(node->left)-getMaxiMumDepth(node->right))>1) return false;
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    return true;


}