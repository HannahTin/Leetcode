"""
移除元素

题目描述:
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
"""
# 和移动零这题很像
def removeElement(nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        # 头尾指针
        left = 0
        right = len(nums)-1
        while(left<=right):
            if(nums[left] == val):
                nums[left]= nums[right]
                right -= 1
            else:
                left+=1
        return left
        # 快慢指针
        '''
        slow = 0
        for fast in range(len(nums)):
            if nums[fast]!= val:
                nums[slow] = nums[fast]
                slow += 1
        return slow 
        '''
print(removeElement([1,2,3,3,4],3))

    
        