/**
无向图中连通分量的数目
给定编号从 0 到 n-1 的 n 个节点和一个无向边列表（每条边都是一对节点），请编写一个函数来计算无向图中连通分量的数目。
输入: n = 5 和 edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
using namespace std;
#include <algorithm> 
#include <queue>
#include <unordered_set>
#include <vector>
class Solution {
private:
    vector<bool> visited;
    void dfs(vector<unordered_set<int>> graph,int src){
        if(visited[src]) return;
        visited[src] = true;
        for(auto& neighbor:graph[src]){
            dfs(graph,neighbor);
        }

    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(const auto& e:edges){
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        } // 创建邻接表
        int count = 0;//记录连通分量个数
        visited = vector<bool>(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count ++;
                dfs(graph,i);
            }
        }
        return count;

    }
};