/**
单词方块
给定一个单词集合 （没有重复），找出其中所有的 单词方块 。

一个单词序列形成了一个有效的单词方块的意思是指从第 k 行和第 k 列 (0 ≤ k < max(行数, 列数)) 来看都是相同的字符串。

例如，单词序列 ["ball","area","lead","lady"] 形成了一个单词方块，因为每个单词从水平方向看和从竖直方向看都是相同的。

b a l l
a r e a
l e a d
l a d y

**/
// 直接回溯实现
/**
class Solution:

    def wordSquares(self, words: List[str]) -> List[List[str]]:

        self.words = words
        self.N = len(words[0])
        self.buildPrefixHashTable(self.words)

        results = []
        word_squares = []
        for word in words:
            word_squares = [word]
            self.backtracking(1, word_squares, results)
        return results

    def backtracking(self, step, word_squares, results):
        if step == self.N:
            results.append(word_squares[:])
            return

        prefix = ''.join([word[step] for word in word_squares])
        for candidate in self.getWordsWithPrefix(prefix):
            word_squares.append(candidate)
            self.backtracking(step+1, word_squares, results)
            word_squares.pop()

    def buildPrefixHashTable(self, words):
        self.prefixHashTable = {}
        for word in words:
            for prefix in (word[:i] for i in range(1, len(word))):
                self.prefixHashTable.setdefault(prefix, set()).add(word)

    def getWordsWithPrefix(self, prefix):
        if prefix in self.prefixHashTable:
            return self.prefixHashTable[prefix]
        else:
            return set([])
**/
using namespace std;
#include <map>
#include <string>
#include <vector>
// 参考：https://leetcode-cn.com/problems/word-squares/solution/dan-ci-fang-kuai-by-leetcode/
class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        vector<int> indexs; //我们不在 Trie 的叶节点标记单词，而是在每个结点标记单词，这样一旦到达前缀中的最后一个结点，就不需要执行进一步的遍历。这个技巧可以优化时间复杂度。
        TrieNode() : children(26, nullptr) { }
    };
    
    TrieNode* buildTrie(const vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *p = root;
            for (const auto &ch : words[i]) {
                int j = ch - 'a';
                if (p->children[j] ==  nullptr) {
                    p->children[j] = new TrieNode();
                }
                p = p->children[j];
                p->indexs.push_back(i);
            }
        }
        return root;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;        
        int size = words[0].size();
        TrieNode *root = buildTrie(words);
        vector<string> out(size);
        for (const auto &word : words) {
            out[0] = word;
            helper(words, root, 1, out, res);
        }
        return res;
    }

    void helper(vector<string>& words, TrieNode *root, int level, vector<string> &out, vector<vector<string>> &res) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str;
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }
        TrieNode *t = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!t->children[str[i] - 'a']) return;
            t = t->children[str[i] - 'a'];
        }
        for (int idx : t->indexs) {
            out[level] = words[idx];
            helper(words, root, level + 1, out, res);
        }
    }
};
