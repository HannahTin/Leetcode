# 时间复杂度 O(n ^ 2
# 空间复杂度 O(n)
# 概率dp入门题
def dicesProbability(n: int) -> list:
    dp =[1/6] *6
    for i in range(2,n+1):
        tmp = [0]*(5*i+1)
        for j in range(len(dp)):
            for k in range(6):
                tmp[j+k] += dp[j]/6
        dp = tmp
    return dp
print(dicesProbability(2))

