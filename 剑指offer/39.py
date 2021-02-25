'''
数组中出现次数超过一半的数字

题目描述：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
'''
# 总结：我首先想到的用哈希表统计出现次数,时间复杂度为O(n),空间复杂度为O(n)。
# 其次还可以数组排序，中位数为所求，但时间复杂度最好为O(nlogn)
# 这里我另外实现一下partition方法,即找到长度为n的数组中第n/2大的数组，时间复杂度为O(n)。
# 还有本题的最佳解法见39-1.py：摩尔投票法，时间复杂度为O(n),空间复杂度为O(1)。
def swap(nums:list,i:int,j:int)->None:
    tmp = nums[i]
    nums[i] = nums[j]
    nums[j] = tmp

def partition(nums:list,left:int,right:int)->int:
        middle = (left+right)//2
        pivot = nums[middle]
        nums[middle] = nums[right] 
        nums[right] = pivot
        boundary = left
        for index in range(left,right):
            if(nums[index]< pivot):
                swap(nums,index,boundary)
                boundary +=1
        swap(nums,right,boundary)
        return boundary

def majorityElement(nums: list) -> int:
    n  = len(nums)
    middle = n >> 1
    start = 0
    end = n-1
    index = partition(nums,start,end)
    while(index!=middle):
        if index > middle:
            end = index-1
            index = partition(nums,start,end)
        else:
            start = index+1
            index = partition(nums,start,end)
    res = nums[middle]
    return res

    """
    # 哈希
    hashmap = {}
    for num in nums:
        hashmap[num] = hashmap.get(num,0)+1

    for key,vaule in hashmap.items():
        if vaule>len(nums)/2:
            return key
    return 0
    """

    
print(majorityElement([1, 2, 3, 2, 2, 2, 5, 4, 2]))