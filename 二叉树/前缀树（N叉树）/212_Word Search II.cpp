/**
212. 单词搜索 II
给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
**/
using namespace std;
#include <map>
#include <string>
#include <vector>
struct TrieNode {
  vector<TrieNode*> children;
  string* word;
  TrieNode() : word(nullptr), children(26) {};
  ~TrieNode() {
    for (const auto& child : children)
      delete child;
  }
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    const int m = board.size(), n = board[0].size();

    TrieNode root;
    for (auto& word : words) {
      TrieNode* p = &root;
      for (const auto& c : word) {
        if (!p->children[c - 97])
          p->children[c - 97] = new TrieNode();
        p = p->children[c - 97];
      }
      p->word = &word;
    }

    vector<string> ans;
    function<void(int, int, int, TrieNode*)> walk = [&](int x, int y, int d, TrieNode* p) {
      if (x < 0 || y < 0 || x == n || y == m || !board[y][x])
        return;

      const char c = board[y][x];
      p = p->children[c - 97];
      if (!p) return;
      
      if (p->word) {
        ans.emplace_back(*p->word);
        p->word = nullptr;
      }

      board[y][x] = 0;

      walk(x - 1, y, d + 1, p);
      walk(x + 1, y, d + 1, p);
      walk(x, y - 1, d + 1, p);
      walk(x, y + 1, d + 1, p);

      board[y][x] = c;
    };

    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        walk(x, y, 0, &root);

    return ans;
  }
};