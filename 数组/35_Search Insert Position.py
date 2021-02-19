"""
搜索插入位置

题目描述:
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position/
"""
# 总结：暴力解题不一定时间消耗就非常高，关键看实现的方式，就像是二分查找时间消耗不一定就很低，是一样的。时间复杂度为o(n),空间复杂度为o(1)
# 有序数组首先反应是不是可以二分做，二分写的时候要注意左闭右闭还是左闭右开，时间复杂度为o(logn),空间复杂度为o(1)
# 同时题目还强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下表可能不是唯一的。
def searchInsert(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # 左闭右开
        left = 0
        right = len(nums)
        while(left < right):
            middle = left + (right - left)//2
            if target == nums[middle]:
                return middle
            elif target > nums[middle]:
                left = middle + 1
            elif target < nums[middle]:
                right = middle 
        # 分别处理如下四种情况
        # 目标值在数组所有元素之前 [0,0)
        # 目标值等于数组中某一个元素 return middle
        # 目标值插入数组中的位置 [left, right) ，return right 即可
        # 目标值在数组所有元素之后的情况 [left, right)，return right 即可
        return right

        """
        # 左闭右闭
        left = 0
        right = len(nums) - 1 
        while(left <= right): 
            middle = left + (right - left)//2
            if target == nums[middle]:
                return middle
            elif target > nums[middle]:
                left = middle + 1
            elif target < nums[middle]:
                right = middle - 1
        # 分别处理如下四种情况
        # 目标值在数组所有元素之前  [0, -1]
        # 目标值等于数组中某一个元素  return middle;
        # 目标值插入数组中的位置 [left, right]，return  right + 1
        # 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return(right+1)
        """

print(searchInsert([1,3,5,6], 5)) # 输出：2
