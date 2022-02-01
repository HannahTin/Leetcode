/**
617. 合并二叉树

给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。
**/
using namespace std;
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
private:
    TreeNode* traversal(TreeNode* node1,TreeNode* node2){
        if(node1==nullptr and node2==nullptr) return nullptr;
        if(node1==nullptr and node2!=nullptr) return node2;
        if(node1!=nullptr and node2==nullptr) return node1;
        node1->val += node2->val;
        node1->left = traversal(node1->left,node2->left);
        node1->right = traversal(node1->right,node2->right);
        return node1;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr) return root2;
        if(root2==nullptr) return root1;
        return traversal(root1,root2);

    }
};
//迭代法
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr) return root2;
        if(root2==nullptr) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while(!que.empty()){
            TreeNode* node1 = que.front();que.pop();
            TreeNode* node2 = que.front();que.pop();
            // 如果两棵树左节点都不为空，加入队列
            if(node1->left and node2->left){
                que.push(node1->left);
                que.push(node2->left);
            }
            // 如果两棵树右节点都不为空，加入队列
            if(node1->right and node2->right){
                que.push(node1->right);
                que.push(node2->right);
            }
            // 当t1的左节点 为空 t2左节点不为空，就赋值过去
            if(node1->left == nullptr and node2->left){
                node1->left = node2->left;
            }
            // 当t1的右节点 为空 t2右节点不为空，就赋值过去
            if(node1->right==nullptr and node2->right){
                node1->right = node2->right;
            }
            // 此时两个节点一定不为空，val相加
            node1->val += node2->val;

        }
        return root1;

    }
};