/**
98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
**/
// 对于验证二叉搜索树 有两个陷阱：

// 陷阱一：不能单纯的比较左节点小于中间节点，右节点大于中间节点就完事了，而是左子树都小于中间节点，右子树都大于中间节点。

// 陷阱二：一个有序序列求最值的时候，不要定义一个全局遍历，然后遍历序列更新全局变量求最值。因为最值可能就是int 或者 longlong的最小值。
// 中序遍历实现，因为bst的中序遍历是从小到大有序的
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
//递归:判断中序遍历的数组是否是递增数组。
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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;

    }
};
// 递归：
class Solution2 {
private:
    long long maxVal = LONG_MIN;
    // TreeNode* pre = NULL; 
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        // 上面两句改写为（建议避免初始化最小值，如下方法取到最左面节点的数值来比较）：
        // if (pre != NULL && pre->val >= root->val) return false;
        // pre = root; // 记录前一个节点
        bool right = isValidBST(root->right);
        return left&&right;


    }
};
// 迭代模拟中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 讲访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();

                if (pre != NULL && cur->val <= pre->val)
                return false;
                pre = cur; //保存前一个访问的结点 

                cur = cur->right;               // 右
            }
        }
        return true;
    }
};
