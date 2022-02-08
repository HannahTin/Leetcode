/*
1804. 实现 Trie （前缀树） II

前缀树（trie ，发音为 "try"）是一个树状的数据结构，用于高效地存储和检索一系列字符串的前缀。前缀树有许多应用，如自动补全和拼写检查。

实现前缀树 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 将字符串 word 插入前缀树中。
int countWordsEqualTo(String word) 返回前缀树中字符串 word 的实例个数。
int countWordsStartingWith(String prefix) 返回前缀树中以 prefix 为前缀的字符串个数。
void erase(String word) 从前缀树中移除字符串 wor
*/
#include<string>
using namespace std;
class Trie {
private:
    int count;
    int pre;
    Trie* next[26];
public:
    Trie() {
        count = 0;
        pre = 0;
        memset(next,0,sizeof(next)); 
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word){
            if(!node->next[c-'a']) node->next[c-'a'] = new Trie();
            node = node->next[c-'a'];
            node->pre++;
        }
        node->count++;
    }
    
    int countWordsEqualTo(string word) {
        Trie* node = this;
        for(char c: word){
            if(!node->next[c-'a']) return false;
            node = node->next[c-'a'];
        }
        return node->count;
    }
    
    int countWordsStartingWith(string prefix) {
        Trie* node = this;
        for(char c: prefix){
            if(!node->next[c-'a']) return 0;
            node = node->next[c-'a'];
        }
        return node->pre;
    }
    
    void erase(string word) {
        Trie* node = this;
        for(char c: word){
            if(!node->next[c-'a'])break;
            node = node->next[c-'a'];
            node->pre--;
        }
        if(node->count) node->count--;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */