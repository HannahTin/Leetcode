/**
530. 二叉搜索树的最小绝对差

给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。

输入：root = [1,0,48,null,null,12,49]
输出：1
**/
// 在递归遍历的过程中如何记录前后两个指针！！
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

// 递归，采用中序遍历得到的数组
class Solution1 {
private:
    vector<int> vec;
    void traversal(TreeNode* node){
        if(node==nullptr) return;
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) { 
            result = min(result, vec[i] - vec[i-1]);
        }
        return result;
    }
};
// 在递归中如何记录前一个节点的指针
class Solution2 {
private:
    int res = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* node){
        if(node==nullptr) return;
        traversal(node->left);
        if(pre!=nullptr){
            res = min(res, node->val - pre->val);
        }
        pre = node;
        traversal(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
// 迭代法
class Solution3 {
private:
    int res = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* pre=nullptr;
        while(curr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr); // 将访问的节点放进栈
                curr = curr->left;
            }
            else{
                curr = st.top();
                st.pop();
                if (pre != NULL) {              // 中
                    res = min(res, curr->val - pre->val);
                }
                pre = curr;
                curr = curr->right;   
            }

        }
        return res;


    }
};

