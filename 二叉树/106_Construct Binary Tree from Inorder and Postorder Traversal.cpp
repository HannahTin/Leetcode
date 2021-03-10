/**根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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
TreeNode*  buildTreeCore(vector<int>& inorder, int InorderBegin,int InorderEnd,vector<int>& postorder,int PostorderBegin,int PostorderEnd){
    if(PostorderBegin == PostorderEnd) return NULL; // 后序为空
    // 第一步，得到root
    int rootValue = postorder[PostorderEnd -1];
    TreeNode* root = new TreeNode(rootValue);
    if(PostorderEnd - PostorderBegin ==1) return root; // 后序为1
    // 第二步，切割中序
    int delimiterIndex;
    for (delimiterIndex = InorderBegin;delimiterIndex<InorderEnd;delimiterIndex++){
        if(inorder[delimiterIndex] == rootValue) break;
    }
    // 左中序区间
    int leftInorderBegin = InorderBegin;
    int leftInorderEnd = delimiterIndex;
    // 右中序区间
    int rightInorderBegin = delimiterIndex+1;
    int rightInorderEnd = InorderEnd;
    //左后序区间
    int leftPostorderBegin = PostorderBegin;
    int leftPostorderEnd = PostorderBegin+  delimiterIndex - InorderBegin;
    // 右后序区间
    int rightPostorderBegin = PostorderBegin+  delimiterIndex - InorderBegin;
    int rightPostorderEnd = PostorderEnd-1;

    // 递归单层逻辑
    root->left = buildTreeCore(inorder,leftInorderBegin,leftInorderEnd,postorder,leftPostorderBegin,leftPostorderEnd);
    root->right = buildTreeCore(inorder,rightInorderBegin,rightInorderEnd,postorder,rightPostorderBegin,rightPostorderEnd);

    return root;




}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0 or postorder.size()==0) return NULL;
    return buildTreeCore(inorder,0,inorder.size(),postorder,0,postorder.size());


}
