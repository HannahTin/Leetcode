/**
211. 添加与搜索单词 - 数据结构设计
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
**/
using namespace std;
#include <map>
#include <string>
// 前缀树+通配符dfs搜索
struct Trie {
    bool isWord;
    Trie* children[26];
    Trie() {
        isWord = false;
        for (auto& child : children) {
            child = nullptr;
        }
    }
};

class WordDictionary {
private:
    Trie* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        auto p = root;
        for (const auto& ch : word) {
            int index = ch - 'a';
            if (p->children[index] == nullptr) {
                p->children[index] = new Trie();
            }
            p = p->children[index];
        }

        p->isWord = true;
    }
    
    bool search(string word) {
        auto p = root;
        return match(word, p, 0);
    }

    bool match(string word, Trie* p, int start) {
        if (p == nullptr) {
            return false;
        }
        if (start == word.size()) {
            return p->isWord;
        }

        auto& ch = word[start];
        if (ch != '.') {
            int index = ch - 'a';
            if (p->children[index] == nullptr) {
                return false;
            }
            p = p->children[index];
            return match(word, p, start + 1);
        } else {
            for (auto ch = 'a'; ch <= 'z'; ch++) {
                int index = ch - 'a';
                if (match(word, p->children[index], start + 1)) {
                    return true;
                }
            }
        }

        return false;
    }


};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
