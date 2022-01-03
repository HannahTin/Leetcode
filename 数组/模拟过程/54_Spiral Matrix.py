"""
螺旋矩阵

题目描述:
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix/
"""
# 总结：螺旋矩阵的遍历，本题和#59题基本相同，除了使用计数作为终止条件

def spiralOrder(matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        top = 0
        c =len(matrix[0]) # 列数
        r = len(matrix) # 行数
        num = c * r
        right = c - 1
        bottom = r - 1
        left = 0
        result = []
        count = 0
        while(count <= num): 
                for i in range(left,right+1):
                        result.append(matrix[top][i])
                        count += 1
                top += 1
                if (count == num): return result
                for i in range(top,bottom+1):
                        result.append(matrix[i][right])
                        count += 1
                right -= 1
                if (count == num): return result
                for i in range(right,left-1,-1):
                        result.append(matrix[bottom][i])
                        count += 1
                bottom -= 1
                if (count == num): return result
                for i in range(bottom,top-1,-1):
                        result.append(matrix[i][left])
                        count += 1
                left += 1
                if (count == num): return result

# 期望输出：[1,2,3,4,8,12,11,10,9,5,6,7]
# print(spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))
# 期望输出：[2,5,4,-1,0,8]
# print(spiralOrder([[2,5],[8,4],[0,-1]]))
# 期望输出：[1,2,3,4,8,12,11,10,9,5,6,7]
print(spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))
