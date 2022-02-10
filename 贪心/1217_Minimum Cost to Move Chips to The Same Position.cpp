/*
1217. 玩筹码
有 n 个筹码。第 i 个芯片的位置是 position[i] 。

我们需要把所有筹码移到同一个位置。在一步中，我们可以将第 i 个芯片的位置从 position[i] 改变为:

position[i] + 2 或 position[i] - 2 ，此时 cost = 0
position[i] + 1 或 position[i] - 1 ，此时 cost = 1
返回将所有筹码移动到同一位置上所需要的 最小代价 。

输入：position = [1,2,3]
输出：1
解释：第一步:将位置3的芯片移动到位置1，成本为0。
第二步:将位置2的芯片移动到位置1，成本= 1。
总成本是1。


输入：position = [2,2,2,3,3]
输出：2
解释：我们可以把位置3的两个芯片移到位置2。每一步的成本为1。总成本= 2。
*/
using namespace std;
#include<vector>
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // 由于将第 i 个筹码向左或者右移动 2 个单位，代价为 0，
        // 所以从任意偶数位置移动到另一个偶数位置，代价都为0，同理从任意奇数位置移动到另一个奇数位置的代价也是 0 。所以可以将所有位置为偶数的筹码移动到 0 这个位置，将所有位置为奇数的筹码移动到 1 这个位置，且代价为 0 。由于将第 i 个筹码向左或者右移动 1 个单位，代价为 1，所以只需要统计在位置在 0 的筹码个数 count0 和位置在 0 的筹码个数 count1 ，最小移动代价为 min(count0,count1)。
        int count1 = 0;
        for(int i : position){
            count1 += i & 1; //奇数个数
        }   
        int count0 = position.size() - count1; //偶数个数
        return count0 > count1 ? count1 : count0;

    }
};