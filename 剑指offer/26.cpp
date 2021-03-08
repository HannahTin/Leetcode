/*
树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 */
// 思路：第一步，在树A中找到和树B的跟节点的值一样的节点R；第二步，判断树A中以R为跟节点的子树是不是包含和树B一样的结构。
// 一定要注意处理指针的问题。
using namespace std;
#include <algorithm> 
#include <queue>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 bool DoesAhaveB(TreeNode* node1,TreeNode* node2){
     if(node1 == nullptr) return false;
     if(node2 == nullptr) return true; // 上面这两个if不能交换，我们要先判断B。
     if(node1->val!=node2->val) return false;
     return(DoesAhaveB(node1->left,node2->left) and DoesAhaveB(node1->right,node2->right));

 }
 bool isSubStructure(TreeNode* A, TreeNode* B) {
     bool result = false;
     if(A!=nullptr and B!=nullptr){
         if(A->val == B->val){
             result = DoesAhaveB(A,B);
         }
         if(!result) result = isSubStructure(A->left,B);
         if(!result) result = isSubStructure(A->right,B);
     }
     return result;

    }