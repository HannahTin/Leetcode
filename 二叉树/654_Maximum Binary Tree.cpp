/**
最大二叉树

题目描述：
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。
**/
using namespace std;
#include <vector>
#include <algorithm> 
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// 这题和105/106题很像，总结下这类题构造的步骤
// 第一步找到root分割点。本题是nums中的最大值。
// 第二步就是找到待分割序列的左序列的开始结束位置，右序列的开始结束位置
// 第三步就是单层递归逻辑
class Solution {
private:
    int maxIndex(vector<int>& nums,int start,int final){
        int maxVal = nums[start];
        int index = start;
        for(int i=start+1;i<final;i++){
            if(nums[i]>maxVal){
                maxVal = nums[i];
                index = i;
            } 
        }
        return index;
    }
    TreeNode* traversal(vector<int>& nums,int begin,int end){
        if(begin == end) return nullptr;
        int index = maxIndex(nums,begin,end);
        TreeNode* root = new TreeNode(nums[index]);
        root->left = traversal(nums,begin,index);
        root->right = traversal(nums,index+1,end);
        return root;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        return traversal(nums,0,nums.size());
        

    }
};
