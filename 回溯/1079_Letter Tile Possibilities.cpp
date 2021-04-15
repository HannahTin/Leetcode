/**
活字印刷

题目描述：
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。

 

示例 1：

输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-tile-possibilities
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string tiles;
    int count = 0;
    vector<bool> visited;
    void dfs(int start){
        if(start == tiles.size()) return;
        for(int i=start;i<tiles.size();i++){
            if(visited[i] ==true or (i>0 and tiles[i] == tiles[i-1] and visited[i-1] ==false)) continue;
            visited[i] = true;  
            count++;
            dfs(0);
            visited[i] = false;
        }

        
    }
public:
    int numTilePossibilities(string tiles) {
        if(tiles.size()==0) return 1;
        this->tiles = tiles;
        visited = vector<bool>(tiles.size(),false);
        sort(this->tiles.begin(),this->tiles.end());
        dfs(0);
        return count;


    }
};