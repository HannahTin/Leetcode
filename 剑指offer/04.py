'''
二维数组中的查找

题目描述：
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
'''

"""
总结：最简单的就是暴力求解，时间复杂度为o(nm),空间复杂度为o(1)。但是暴力法未利用矩阵 “从上到下递增、从左到右递增” 的特点，显然不是最优解法。
第二种做法可以从矩阵 matrix 左下角元素（索引设为 (i, j) ）开始遍历，并与目标值对比：
    当 matrix[i][j] > target 时，执行 i-- ，即消去第 i 行元素；
    当 matrix[i][j] < target 时，执行 j++ ，即消去第 j 列元素；
    当 matrix[i][j] = target 时，返回 truetrue ，代表找到目标值。
若行索引或列索引越界，则代表矩阵中无目标值，返回 falsefalse 。
这时时间复杂度为o(n+m),空间复杂度为o(1)
"""

def findNumberIn2DArray(matrix, target):
    '''
    for r in range(len(matrix)):
        for c in range(len(matrix[0])):
                if matrix[r][c] == target:
                    return True
    return False
    '''
    # 每轮 i 或 j 移动后，相当于生成了“消去一行（列）的新矩阵”
    if matrix==None: return False
    row = len(matrix)
    column = len(matrix[0])
    i = row - 1
    j = 0
    while(i >=0 and j < column):
        if matrix[i][j] > target:
            i -= 1
        elif matrix[i][j] < target:
            j += 1
        elif matrix[i][j] == target:
            return True
    return False


print(findNumberIn2DArray([
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
], 20))# False
print(findNumberIn2DArray([[]],0)) # False

