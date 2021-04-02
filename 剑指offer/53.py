def search(nums: list,target: int) -> int:
    #   查找数字出现的开始和结束位置，时间复杂度为o(n)
        if(len(nums) == 0 or target < nums[0] or target > nums[-1] ): return 0
        right = len(nums) -1
        left = 0
        while(left <= right):
            if(nums[right] == nums[left]):
                return right - left + 1
            while(nums[left] < target):
                left += 1
            while(nums[right] > target):
                right -= 1
        return 0
print(search([5,7,7,8,8,10],8))
# 可以分别二分查找数字的开始和结束位置，加起来时间复杂度仍是O(logn)
# 不写了其实就是二分寻找一个数的左右边界



            
        
