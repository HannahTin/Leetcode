'''
股票的最大利润

题目描述：
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
'''
# 首先本题我没有想到要用动规，数组实现
import sys
def maxProfit(prices: list) -> int:
        if not prices: return 0
        min_num = sys.maxsize
        res = []
        for i in range(len(prices)):
            min_num = min(min_num,prices[i])
            res.append(prices[i] - min_num)
        return max(res)
print(maxProfit([7,1,5,3,6,4])) # 5
print(maxProfit([7,6,5,4])) #0