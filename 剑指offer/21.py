'''
调整数组顺序使奇数位于偶数前面

题目描述：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
'''
# 最先想到的就是快排秒做。此外还有快慢指针法和首尾指针法。
def swap(nums:list,i:int,j:int)->None:
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp
'''
# 完全的快排
def partition(nums:list,left:int,right:int):
    middle = (left+right)>>1
    pivot = nums[middle]
    nums[middle]= nums[right]
    nums[right] = pivot
    boundary = left
    for index in range(left,right):
        if nums[index]%2==1:
            swap(nums,index,boundary)
            boundary+=1
    swap(nums,right,boundary)

    
def exchange(nums: list) -> list:
    partition(nums,0,len(nums)-1)
    return nums
'''


# 首尾指针就是：
# 定义头指针 left ，尾指针 right .
# left 一直往右移，直到它指向的值为偶数
# right 一直往左移， 直到它指向的值为奇数
# 交换 nums[left] 和 nums[right] .
# 重复上述操作，直到 left == right 
'''
def exchange(nums: list) -> list:
    left =0
    right =len(nums)-1
    while(left<right):
        if(nums[left]&1==1):
            left +=1
            continue
        if ((nums[right] & 1) != 1):
            right -=1
            continue
        swap(nums,left,right)
        left+=1
        right-=1
    return nums

print(exchange([1,2,3,4,5]))
'''
# 快慢双指针
# 定义快慢双指针 fast和 low ，fast 在前， low 在后 .
# fast 的作用是向前搜索奇数位置，low 的作用是指向下一个奇数应当存放的位置
# fast 向前移动，当它搜索到奇数时，将它和 nums[low] 交换，此时 low 向前移动一个位置 .
# 重复上述操作，直到 fast 指向数组末尾 .
def exchange(nums: list) -> list:
    low,fast=0,0
    while(fast<len(nums)):
        if (nums[fast] & 1):
            swap(nums,low, fast)
            low+=1
        fast+=1
    return nums

print(exchange([1,2,3,4,5]))
    




