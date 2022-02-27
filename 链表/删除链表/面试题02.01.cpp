/*
面试题 02.01. 移除未排序链表的重复节点

编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
#include <unordered_set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 要求删除链表中的「重复节点」，并保留「最开始出现的节点」。考虑遍历链表，借助一个「哈希表 Set 」记录遇到的节点值，在遍历过程中判断：

// 若当前节点在 Set 中，代表是「重复节点」，则删除之；
// 若当前节点不在 Set 中，代表此节点第一次遇到，则将此「节点值」加入到 Set 中；

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* pre = head;
        ListNode* curr = head->next;
        unordered_set<int> visited={head->val};
        while(curr){
            if(visited.find(curr->val)!=visited.end()){
                pre->next = curr->next;
                curr = curr->next;
            }else{
                visited.insert(curr->val);
                pre = pre->next;
                curr = curr->next;
            }
            
        }
        return head;
    }
};
