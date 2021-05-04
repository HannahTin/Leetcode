/**
677. 键值映射
实现一个 MapSum 类，支持两个方法，insert 和 sum：

MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
**/
using namespace std;
#include <map>
#include <string>
struct TrieNode{
    int isEnd = -1;// -1表示不是终止节点，非-1表示终止节点的值，相比原来的bool表示是否为单词末尾，good
    int val = 0; 
    map<char,TrieNode*> next;
};
class MapSum {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    int search(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++){
            if((p->next).count(word[i]) <= 0){
                return -1;
            }
            p = (p->next)[word[i]];
        }
        return p->isEnd;
    }
    void insert(string key, int val) {
        int preval = search(key);
        int trueval = val;
        TrieNode* p = root;
        if(preval!=-1) val -= preval;
        for(int i=0;i<key.length();i++){
            if((p->next).count(key[i]) <= 0){
                (p->next).insert(make_pair(key[i],new TrieNode()));
            }
            p = (p->next)[key[i]]; 
            p->val += val;
        }
        p->isEnd = trueval;

    }
    
    int sum(string prefix) {
        TrieNode* p = root;
        for(int i=0;i<prefix.length();i++){
            if((p->next).count(prefix[i]) <= 0){
                return 0;
            }
            p = (p->next)[prefix[i]];   
        }
        return p->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */