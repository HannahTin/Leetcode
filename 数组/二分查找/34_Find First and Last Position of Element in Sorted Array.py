"""
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
"""
def searchRange(nums: list(), target: int) -> list():
        if(len(nums) == 0 or target < nums[0] or target > nums[-1] ): return [-1,-1]
        right = len(nums) -1
        left = 0
        while(left <= right):
            if(nums[right] == nums[left]):
                return [left,right]
            while(nums[left] < target):
                left += 1
            while(nums[right] > target):
                right -= 1
        return [-1,-1]
print(searchRange([2,3,3,3,4,5,8,9,100],3))