'''
402. 移掉 K 位数字
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

 
示例 1 ：

输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
示例 2 ：

输入：num = "10200", k = 1
输出："200"
解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
'''
# 思路，从左到右，找第一个比后面大的字符，删除，清零，k次扫描。
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for d in num:
            while stack and k and stack[-1]>d:
                stack.pop()
                k -= 1
            stack.append(d)
        if k>0:
            stack = stack[:-k]
        return ''.join(stack).lstrip('0') or "0"