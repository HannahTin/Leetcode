'''
火柴拼正方形

题目描述：
还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matchsticks-to-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
# 回溯时间复杂度为O(4^n).空间复杂度为o（n）

def makesquare(self, matchsticks: list) -> bool:
        if(not matchsticks): return False
        if(sum(matchsticks)%4!=0): return False
        possible_side = sum(matchsticks) //4
        matchsticks.sort(reverse=True) #相当于剪枝
        sums = [0 for _ in range(len(matchsticks))]
        def dfs(index):
            if(index == len(matchsticks)):
                return sums[0] == sums[1] == sums[2] ==sums[3] == possible_side
            for i in range(4):
                if sums[i] + matchsticks[index]<=possible_side:
                    sums[i]+= matchsticks[index]
                    if(dfs(index+1)): return True
                    sums[i] -= matchsticks[index]
            return False
        return dfs(0)
