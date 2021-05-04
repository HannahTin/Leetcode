/**
336. 回文对
给定一组 互不相同 的单词， 找出所有 不同 的索引对 (i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。
**/
// 参考：https://leetcode-cn.com/problems/palindrome-pairs/solution/hui-wen-dui-by-leetcode-solution/
using namespace std;
#include <map>
#include <string>
#include <vector>
// 使用字典树存储所有的字符串。在进行查询时，我们将待查询串的子串逆序地在字典树上进行遍历，即可判断其是否存在。
// 时间复杂度：O(nm^2)，其中 n是字符串的数量，m是字符串的平均长度。
// 对于每一个字符串，我们需要 O(m^2)地判断其所有前缀与后缀是否是回文串，并 O(m^2) 地寻找其所有前缀与后缀是否在给定的字符串序列中出现。
// 空间复杂度：O(n×m)，其中 n是字符串的数量，m是字符串的平均长度。为字典树的空间开销。

class Solution {
public:
    struct node {
        int ch[26];
        int flag;
        node() {
            flag = -1;
            memset(ch, 0, sizeof(ch));
        }
    };

    vector<node> tree;

    void insert(string& s, int id) {
        int len = s.length(), add = 0;
        for (int i = 0; i < len; i++) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                tree.emplace_back();
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].flag = id;
    }

    int findWord(string& s, int left, int right) {
        int add = 0;
        for (int i = right; i >= left; i--) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                return -1;
            }
            add = tree[add].ch[x];
        }
        return tree[add].flag;
    }

    bool isPalindrome(string& s, int left, int right) {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[left + i] != s[right - i]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        tree.emplace_back(node());
        int n = words.size();
        for (int i = 0; i < n; i++) {
            insert(words[i], i);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            for (int j = 0; j <= m; j++) {
                if (isPalindrome(words[i], j, m - 1)) {
                    int left_id = findWord(words[i], 0, j - 1);
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({i, left_id});
                    }
                }
                if (j && isPalindrome(words[i], 0, j - 1)) {
                    int right_id = findWord(words[i], j, m - 1);
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({right_id, i});
                    }
                }
            }
        }
        return ret;
    }
};
/**哈希实现
  *使用哈希表存储所有字符串的翻转串。在进行查询时，我们判断带查询串的子串是否在哈希表中出现，就等价于判断了其翻转是否存在
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:

        def findWord(s: str, left: int, right: int) -> int:
            return indices.get(s[left:right+1], -1)
        
        def isPalindrome(s: str, left: int, right: int) -> bool:
            return (sub := s[left:right+1]) == sub[::-1]
        
        n = len(words)
        indices = {word[::-1]: i for i, word in enumerate(words)}
        
        ret = list()
        for i, word in enumerate(words):
            m = len(word)
            for j in range(m + 1):
                if isPalindrome(word, j, m - 1):
                    leftId = findWord(word, 0, j - 1)
                    if leftId != -1 and leftId != i:
                        ret.append([i, leftId])
                if j and isPalindrome(word, 0, j - 1):
                    rightId = findWord(word, j, m - 1)
                    if rightId != -1 and rightId != i:
                        ret.append([rightId, i])

        return ret
**/