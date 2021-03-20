'''
剪绳子 II

题目描述：
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
#  贪心实现，时间复杂度和空间复杂度均为O(1)
def cuttingRope(n: int) -> int:
        if(n <2): return 0
        if(n==2): return 1
        if(n==3): return 2
        timesof3 = n //3
        if(n - timesof3*3 ==1):
            timesof3 -=1
        timesof2 = (n-timesof3*3)//2
        return int(pow(3,timesof3)*pow(2,timesof2)%(1000000007))
print(cuttingRope(8)) # 18