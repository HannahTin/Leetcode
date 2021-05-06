/**
 * 在本问题中, 树指的是一个连通且无环的无向图。

输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。

返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

示例 1：

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
// 本题其实是无向图中环的检测，并查集模版：
// 如果两个顶点其中有一个不在这张图上，它当然不是多余的边；
// 可以在添加一条边的时候，检查从其中一个顶点是否可以通过 遍历 到达另一个顶点，这里所说的遍历可以是「深度优先遍历」，也可以是「广度优先遍历」；

// 如果遍历不能到达，说明这条表不是多余的边，需要添加到图中（注意：无向图需要添加两条边）；
// 如果遍历可以到达，说明形成了回路，当前考虑的这条边就是多余的边。
using namespace std;
#include <algorithm> 
#include <queue>
#include <unordered_set>
#include <vector>
class Solution {
private:
class UF {
private:
    // 连通分量个数
    int number;
    // 存储一棵树
    vector<int> parent;
    // 记录树的“重量”
    vector<int> size;
public:
    UF(int n) {
        this->number = n;
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        
        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        number--;
    }

    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int count() {
        return number;
    }
};
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(edges.size()+1);
        for(auto& e:edges){
            if(uf.connected(e[0],e[1])){
                return{e[0],e[1]};
            }
            else{
                uf.unite(e[0],e[1]);
            }
            
        }
        return {};

    }
};