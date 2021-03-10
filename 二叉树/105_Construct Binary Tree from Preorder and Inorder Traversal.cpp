/**
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。

例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
**/
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
TreeNode* buildTreeCore(vector<int>& preorder, int PreorderBegin,int PreorderEnd,vector<int>& inorder,int InorderBegin,int InorderEnd){
    if(PreorderBegin == PreorderEnd) return NULL; // 前序为空
    // 第一步，得到root
    int rootValue = preorder[PreorderBegin];
    TreeNode* root = new TreeNode(rootValue);
    if(PreorderEnd - PreorderBegin ==1) return root; // 前序为1
    // 第二步，切割中序
    int delimiterIndex;
    for (delimiterIndex = InorderBegin;delimiterIndex<InorderEnd;delimiterIndex++){
        if(inorder[delimiterIndex] == rootValue) break;
    }
    //左中序区间
    int leftInorderBegin = InorderBegin;
    int leftInorderEnd = delimiterIndex;
    //右中序区间
    int rightInorderBegin = delimiterIndex+1;
    int rightInorderEnd = InorderEnd;
    //左前序区间
    int leftPreorderBegin = PreorderBegin+1;
    int leftPreorderEnd = PreorderBegin + 1 + delimiterIndex- InorderBegin;
    //右前序区间
    int rightPreorderBegin =PreorderBegin + 1 + delimiterIndex- InorderBegin; 
    int rightPreorderEnd = PreorderEnd;
    // 递归单层逻辑
    root->left = buildTreeCore(inorder,leftInorderBegin,leftInorderEnd,preorder,leftPreorderBegin,leftPreorderEnd);
    root->right = buildTreeCore(inorder,rightInorderBegin,rightInorderEnd,preorder,rightPreorderBegin,rightPreorderEnd);

    return root;




}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(inorder.size()==0 || preorder.size()==0) return NULL;
    return buildTreeCore(preorder,0,preorder.size(),inorder,0,inorder.size());


}