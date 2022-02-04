/**
501. 二叉搜索树中的众数
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 任意顺序 返回。


注意‼️
在求众数集合的时候有一个技巧，因为题目中众数是可以有多个的，所以一般的方法需要遍历两遍才能求出众数的集合。

但可以遍历一遍就可以求众数集合，使用了适时清空结果集的方法，这个方法还是很巧妙的。
**/
#include <unordered_map>
#include <vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 下面是普通二叉树的求众数:最直观的方法一定是把这个树都遍历了，用map统计频率，把频率排个序，最后取前面高频的元素的集合。
class Solution1 {
private:
void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // 前序遍历
    if (cur == NULL) return ;
    map[cur->val]++; // 统计元素频率
    searchBST(cur->left, map);
    searchBST(cur->right, map);
    return ;
}
// C++中如果使用std::map或者std::multimap可以对key排序，但不能对value排序。
// 所以要把map转化数组即vector，再进行排序，当然vector里面放的也是pair<int, int>类型的数据，第一个int为元素，第二个int为出现频率
bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map; // key:元素，value:出现频率
        vector<int> result;
        if (root == NULL) return result;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp); // 给频率排个序
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            // 取最高的放到result数组中
            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};


// 下面是二叉搜索树求众数了
// 遍历有序数组的元素出现频率，从头遍历，那么一定是相邻两个元素作比较，然后就把出现频率最高的元素输出就可以了。
// 关键是在有序数组上的话，好搞，在树上怎么搞呢？这就考察对树的操作了
// 弄一个指针指向前一个节点，这样每次cur（当前节点）才能和pre（前一个节点）作比较。
class Solution {
private:
    TreeNode* pre = nullptr;
    int maxCount = 0;
    int count;
    vector<int> res;
    void traversal(TreeNode* node){
        if(node==nullptr) return;
        traversal(node->left);
        if(pre==nullptr){
            count = 1;
        }
        else if(pre->val == node->val){
            count+=1;
        }else{
            count =1;
        }
        pre = node;
        if (count == maxCount) { // 如果和最大值相同，放进result中
            res.push_back(node->val);
        }

        if (count > maxCount) { // 如果计数大于最大值频率
            maxCount = count;   // 更新最大频率
            res.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            res.push_back(node->val);
        }

        traversal(node->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;


    }
};
// 迭代法：只要把中序遍历转成迭代，中间节点的处理逻辑完全一样。
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int maxCount = 0; // 最大频率
        int count = 0; // 统计频率
        vector<int> result;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top();
                st.pop();                       // 中
                if (pre == NULL) { // 第一个节点
                    count = 1;
                } else if (pre->val == cur->val) { // 与前一个节点数值相同
                    count++;
                } else { // 与前一个节点数值不同
                    count = 1;
                }
                if (count == maxCount) { // 如果和最大值相同，放进result中
                    result.push_back(cur->val);
                }

                if (count > maxCount) { // 如果计数大于最大值频率
                    maxCount = count;   // 更新最大频率
                    result.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};