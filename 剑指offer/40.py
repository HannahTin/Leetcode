'''
最小的k个数

题目描述：
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
'''
# 和39题很像，依然可以利用partition函数找到k-1的位置，而这k个数字不一定是排序的。
# 另外注意处理特殊情况的用例0和len(arr)。这依然对愿数组进行了修改，时间复杂度为o(n)。

def swap(nums:list,i:int,j:int)->None:
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp

def partition(arr:list,left:int,right:int):
    middle = (left+right)//2
    pivot = arr[middle]
    arr[middle]= arr[right]
    arr[right] = pivot
    boundary = left
    for index in range(left,right):
        if arr[index]< pivot:
            swap(arr,index,boundary)
            boundary+=1
    swap(arr,right,boundary)
    return boundary

def getLeastNumbers(arr: list, k: int) -> list:
    if k == 0: return []
    right = 0
    left = len(arr)-1
    boundary = partition(arr,right,left)
    while(boundary!=k-1):
        if boundary>k-1:
            left = boundary-1
            boundary = partition(arr,right,left)
        else:
            right = boundary +1
            boundary = partition(arr,right,left)
    return arr[:k]

print(getLeastNumbers([0,1,2,1],1))
print(getLeastNumbers([3,2,1],2))
print(getLeastNumbers([4,5,1,6,2,7,3,8],4))
print(getLeastNumbers([0,0,2,3,2,1,1,2,0,4],10))


