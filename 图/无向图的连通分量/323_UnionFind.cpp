using namespace std;
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf(n);
        for (const auto& e : edges) {
            auto pu = uf.find(e[0]);
            auto pv = uf.find(e[1]);
            if (pu != pv) {
                uf.unite(pu, pv);
            }
        }

        return uf.count();

    }
};