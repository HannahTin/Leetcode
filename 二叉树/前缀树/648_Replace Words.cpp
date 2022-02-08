/**
在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。
**/
using namespace std;
#include <map>
#include <string>
#include <vector>
class Solution {
private:
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
};
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* myTrie = new Trie();
        for(int i=0;i<dictionary.size();i++){
            myTrie->insert(dictionary[i]);
        }
        string ans;
        for (int i = 0; i < sentence.size(); ++i) {
            string temp;
            while (i < sentence.size() and sentence[i] != ' ') {
                temp.push_back(sentence[i++]);
            }
            
            for (int j = 1; j <= temp.size(); ++j) {
                if (myTrie->search(temp.substr(0, j))) {
                    temp = temp.substr(0, j);
                    break;
                }
            }
            if (ans.empty()) {
                ans += temp;
            } else {
                ans.push_back(' ');
                ans += temp;
            }
        }
        return ans;

    }
};