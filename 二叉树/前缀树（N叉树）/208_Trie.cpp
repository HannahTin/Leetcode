/**
实现 Trie (前缀树)

Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
using namespace std;
#include <map>
#include <string>
// 算法的复杂度分析：
struct TrieNode{
    bool flag;
    map<char,TrieNode*> next;
};
class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++){
            if((p->next).count(word[i]) <= 0){
                (p->next).insert(make_pair(word[i],new TrieNode()));
            }
            p = (p->next)[word[i]];
        }
        p->flag = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++){
            if((p->next).count(word[i]) <= 0){
                return false;
            }
            p = (p->next)[word[i]];
        }
        return p->flag;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i=0;i<prefix.length();i++){
            if((p->next).count(prefix[i]) <= 0){
                return false;
            }
            p = (p->next)[prefix[i]];
        }
        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
