'''
机器人的运动范围

题目描述：
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
# 思路：dfs+可行性剪枝（在搜索中遇到数位和超出目标值或元素已经被访问，则应立即返回。）
def digitSum(n):
    ans =0
    while(n):
        ans+=n%10
        n //= 10
    return ans
def movingCount( m: int, n: int, k: int) ->int:
    def dfs(i,j):
        if i>=m or j >=n or (digitSum(i)+digitSum(j))>k or  (i, j) in visited_set:
            return 0
        visited_set.add((i,j))
        return 1 + dfs(i+1,j) +dfs(i,j+1)

    visited_set = set()
    return dfs(0,0)
print(movingCount(2,3,1)) # 3
print(movingCount(3,2,6)) # 6

from queue import Queue
# 思路：bfs
def movingCount_bfs( m: int, n: int, k: int) ->int:
    q = Queue()
    q.put((0,0))
    s =set()
    while not q.empty():
        x,y = q.get()
        if((x,y) not in s and 0<=x<m and 0<=y<n and (digitSum(x)+digitSum(y))<=k ):
            s.add((x,y))
            for cx,cy in [(x+1,y),(x,y+1)]:
                q.put((cx,cy))
    return len(s)


print(movingCount_bfs(2,3,1)) # 3
print(movingCount_bfs(3,2,6)) # 6
