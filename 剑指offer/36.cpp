#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
/**
二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
**/
class Solution {
private:
    Node *pre, *head;
    void dfs(Node* curr){
        if(curr->left) dfs(curr->left);
        if(pre!=NULL) pre->right=curr;
        else head = curr;
        curr->left = pre;
        pre=curr;
        if(curr->right) dfs(curr->right);

    }

public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        dfs(root);
        head->left = pre; //设置首尾指针
        pre->right = head;
        return head;

        
    }
};