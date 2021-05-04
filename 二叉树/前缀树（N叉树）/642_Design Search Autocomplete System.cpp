/**
642. 设计搜索自动补全系统
为搜索引擎设计一个搜索自动补全系统。用户会输入一条语句（最少包含一个字母，以特殊字符 '#' 结尾）。除 '#' 以外用户输入的每个字符，返回历史中热度前三并以当前输入部分为前缀的句子。下面是详细规则：

一条句子的热度定义为历史上用户输入这个句子的总次数。
返回前三的句子需要按照热度从高到低排序（第一个是最热门的）。如果有多条热度相同的句子，请按照 ASCII 码的顺序输出（ASCII 码越小排名越前）。
如果满足条件的句子个数少于 3，将它们全部输出。
如果输入了特殊字符，意味着句子结束了，请返回一个空集合。
你的工作是实现以下功能：

构造函数：

AutocompleteSystem(String[] sentences, int[] times): 这是构造函数，输入的是历史数据。 Sentences 是之前输入过的所有句子，Times 是每条句子输入的次数，你的系统需要记录这些历史信息。

现在，用户输入一条新的句子，下面的函数会提供用户输入的下一个字符：

List<String> input(char c): 其中 c 是用户输入的下一个字符。字符只会是小写英文字母（'a' 到 'z' ），空格（' '）和特殊字符（'#'）。输出历史热度前三的具有相同前缀的句子。
**/
// 首先这是个经典的问题，首先考虑字典树的方法实现。
using namespace std;
#include <map>
#include <vector>
#include <string>
struct TrieNode {
    int val = 0; // 每个节点保存出现的频数
    map<char, TrieNode*> next;
};
class AutocompleteSystem {
private:
    TrieNode* root;
    TrieNode* cur;  // 当前节点
    string ans = "";  // 历史输入
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        ans = "";
        cur = root = new TrieNode();
        // 构建trie树
        for(int i=0;i<sentences.size();i++) {
            insert(sentences[i], times[i]);
        }
    }

    void insert(string& s, int time) {
        TrieNode* p = root;
        for(int i=0;i<s.length();i++){
            if((p->next).count(s[i]) <= 0){
                (p->next).insert(make_pair(s[i],new TrieNode()));
            }
            p = (p->next)[s[i]];
        }
        p->val += time;
    }
    
    vector<string> input(char c) {
        // 输入结束时复位
        if (c == '#') {
            cur->val ++;
            cur = root;
            ans = "";
            return {};
        }
        // 更新当前节点
        if(cur->next.find(c)==cur->next.end()) {
            cur->next[c] = new TrieNode();
        }
        cur = cur->next[c];
        ans += c;
        // 查找所有符合条件的候选集及出现次数
        vector<pair<string, int>> vec;
        find(cur, ans, vec);
        // 按次数及字典序排序
        sort(vec.begin(), vec.end(), [this](pair<string, int>& p1, pair<string, int>& p2){
            return p1.second == p2.second ? compare(p1.first, p2.first) : p1.second > p2.second; 
        });
        // 取top 3
        vector<string> res;
        for(auto& p: vec) {
            res.push_back(p.first);
            if(res.size()>=3) break;
        }
        return res;
    }
    // 字典序比较
    bool compare(string& s1, string& s2) {
        int i = 0, m = s1.size(), n = s2.size();
        while(i<m&&i<n) {
            if(s1[i] != s2[i]) {
                return s1[i] < s2[i];
            }
            i++;
        }
        return m <= n;
    }
    // dfs查找所有候选集及次数
    void find(TrieNode* node, string ans, vector<pair<string, int>>& vec) {
        if(node->val>0) {
            vec.push_back({ans, node->val});
        }
        for(auto& it: node->next) {
            find(it.second, ans+it.first, vec);
        }
    }

};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
/**
哈希法，速度更快
class AutocompleteSystem {
public:
    string cur;//当前输入的查询字符串
    int idx;//当前输入查询字符在查询字符串的下标
    vector<string> res;//目前所有可能的补全结果，按题目要求排序（热度递减、字典序递增）
    unordered_map<char, map<string, int>> cnt;//以各个字母开头的所有字符串的历史查询次数
    static bool cmp(pair<string, int>& a, pair<string, int>& b){//排序函数
        if(a.second != b.second)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        cur = "";
        idx = 0;
        res.clear();
        cnt.clear();
        for(int i = 0; i < sentences.size(); i++)
            cnt[sentences[i][0]][sentences[i]] = times[i];
    }
    vector<string> input(char c) {
        if(c == '#'){//本此查询完毕，更新cnt，清空缓存量
            cnt[cur[0]][cur]++;
            cur = "";
            idx = 0;
            res.clear();
            return res;
        }
        if(idx == 0){//输入查询字符串的第一个字母
            cur += c;
            idx++;
            //找到所有可能的补全结果
            vector<pair<string, int>> temp;
            for(auto it = cnt[c].begin(); it != cnt[c].end(); it++)
                temp.push_back(*it);
            sort(temp.begin(), temp.end(), cmp);//排序
            for(auto it = temp.begin(); it != temp.end(); it++)
                res.push_back(it->first);
        }
        else{
            auto it = res.begin();
            while(it != res.end()){//去掉res中不可能是补全结果的单词
                if((*it).size() <= idx || (*it)[idx] != c)
                    res.erase(it);
                else
                    it++;
            }
            cur += c;
            idx++;
        }
        //返回res中的前三个
        if(res.size() < 3) 
            return res;
        else
            return vector<string>(res.begin(), res.begin()+3);
    }
};
**/


