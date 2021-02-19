"""
螺旋矩阵II

题目描述:
给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii/
"""
# 总结：本题并不涉及到什么算法，就是数组中的又一经典题型：模拟过程。
# 就是注意边界的处理，真正解决题目的代码都是简洁的，或者有原则性的，可以在这道题目中体会到这一点。

def generateMatrix(n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        target = n*n
        num = 1
        mat = [[0 for _ in range(n)] for _ in range(n)]  
        top = 0
        right = n-1
        bottom = n-1
        left = 0
        while(num <= target):
            for i  in range(left,right+1): # 从左到右
                mat[top][i] = num
                num += 1
            top += 1
            for i in range(top,bottom+1): # 从上到下
                mat[i][right] = num
                num += 1
            right -= 1 
            for i in range(right,left-1,-1): # 从右到左
                mat[bottom][i] = num
                num += 1
            bottom -= 1
            for i in range(bottom,top-1,-1): # 从下到上
                mat[i][left] = num
                num += 1
            left += 1
        
        return mat

print(generateMatrix(3))
