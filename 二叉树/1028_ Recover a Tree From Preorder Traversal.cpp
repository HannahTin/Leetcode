/**
从先序遍历还原二叉树

题目描述：
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。
**/
using namespace std;
#include <vector>
#include <algorithm> 
#include <stack>
#include <string>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* recoverFromPreorder(string S) {
        if(S.size() == 0) return nullptr;
        return createTree(S, 0);
}

TreeNode* createTree(string& S, int depth){
        int len = 0;
        string str = "";
        while(S[len]=='-') len++;
        if(len!=depth) return NULL;
        while(S[len]!='-' && len<S.size()) str += S[len++];
        S = S.substr(len);
        TreeNode* root = new TreeNode(stoi(str));
        root->left = createTree(S,depth+1);
        root->right = createTree(S,depth+1);
        return root;
}

    