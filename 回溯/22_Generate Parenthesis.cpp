// 22. 括号生成
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
private:
    vector<string> res;
public:
    void dfs(string str,int left,int right){ // 我觉得字符串的问题dfs也行 加个回溯操作也行，看传入的字符串是引用还是赋值了。赋值其实隐含了回溯操作。
        if(left ==0 and right ==0) {
            res.push_back(str);
            return;
        }
        if(left == right){
                //剩余左右括号数相等，下一个只能用左括号
                dfs(str+"(",left-1,right);
        }else if(left < right){
                //剩余左括号小于右括号，下一个可以用左括号也可以用右括号
                if(left > 0){
                    dfs(str+"(",left-1,right);
                }
                dfs(str+")",left,right-1);
        }



    }
    vector<string> generateParenthesis(int n) {
        string str ="";
        dfs(str,n,n);
        return res;
    }
};
//BFS
class Solution {
public:
class Node{
            
        public:
            string str;
            int left,right;
            Node(string str,int left,int right){
                this->str = str;
                this->left = left;
                this->right = right;
            }
    };
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0) return res;
        queue<Node*> que;
        que.push(new Node("",n,n));
        while(!que.empty()){
            Node* node = que.front();
            que.pop();
            if(node->left ==0 && node->right==0) res.push_back(node->str);
            if(node->left>0){
                que.push(new Node(node->str+"(",node->left-1,node->right));
            }
            if(node->right>0 && node->left<node->right){
                que.push(new Node(node->str+")",node->left,node->right-1));
            }
            

        }
        return res;
        

    }
};
