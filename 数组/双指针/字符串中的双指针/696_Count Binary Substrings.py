'''
696. 计数二进制子串
给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。

重复出现（不同位置）的子串也要统计它们出现的次数。

 
示例 1：

输入：s = "00110011"
输出：6
解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
'''
class Solution:
# 我们可以将字符串 s 按照 0 和 1 的连续段分组，存在 counts 数组中，例如 s=00111011，可以得到这样的 
# counts 数组：counts={2,3,1,2}。

# 这里 counts 数组中两个相邻的数一定代表的是两种不同的字符。假设 counts 数组中两个相邻的数字为 
# u 或者 v，它们对应着 u 个 0 和 v 个 1，或者 u 个 1 和 v 个 0。它们能组成的满足条件的子串数目为 

# min{u,v}，即一对相邻的数字对答案的贡献。
# 我们只要遍历所有相邻的数对，求它们的贡献总和，即可得到答案。

    def countBinarySubstrings(self, s: str) -> int:
        # ans = []
        cur = 0
        last = 0
        res =0
        while(cur<len(s)):
            count = 0
            c = s[cur]
            while(cur<len(s) and s[cur]==c):
                count +=1
                cur += 1
            res += min(last,count)
            last = count        
        # print(ans)
        # res = 0
        # for i in range(1,len(ans)):
        #     res += min(ans[i],ans[i-1])
        return res