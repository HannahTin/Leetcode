'''
斐波那契数列

题目描述：
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

'''
# 总结：递归实现时间复杂度类似二叉树的节点数o(2^n),空间复杂度类似二叉树的高度为o(n)；循环实现时间复杂度为o(n),空间复杂度为o(1)
def fib(n: int) -> int:
        if n == 0: return 0
        if n == 1: return 1
        fib1 = 0
        fib2 = 1
        for _ in range(2,n+1):
            fibn = fib1 + fib2
            fib1 = fib2
            fib2 = fibn
        return fibn%1000000007 
        # 由于 Python 中整形数字的大小限制 取决计算机的内存 （可理解为无限大），因此可不考虑大数越界问题。加和最后取余即可。

print(fib(2))
print(fib(5))