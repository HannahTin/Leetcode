/**
279. 完全平方数
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

 

示例 1：

输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
**/
using namespace std;
#include <vector>
#include <queue>
// 将此问题抽象成图论问题，从输入的整数 n开始，使用广度优先遍历，到 0 为止 扩散的次数就是题目问的 n可以拆分为完全平方数的和的最少个数。
class Solution {
public:
    int numSquares(int n) {
        queue<int> que;
        vector<bool> visited(n+1);
        visited[n] = true;
        que.push(n);
        int step =1;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                int front = que.front();
                que.pop();
                for (int j = 1; j * j <= front; j++) {
                    if (j * j == front) {
                        return step;
                    }
                    int next = front - j * j;
                    if (!visited[next]) {
                        que.push(next);
                        visited[next] = true;
                    }
                }
            }
            step++;
        }
        return 0;

    }
};