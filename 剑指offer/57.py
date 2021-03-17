# 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可
# 剑指 Offer 57. 和为s的两个数字

# 思路：本题其实和两数之和基本一致，只是给出的数组是递增排序的。那除了用哈希法做的话，还有就是如下的首尾指针法。
def twoSum(nums: List[int], target: int) -> List[int]:
        ahead = 0
        behind = len(nums)-1
        while(ahead<behind):
            sum = nums[ahead]+nums[behind]
            if(sum == target):
                return [nums[ahead],nums[behind]]
            elif sum >target:
                behind -=1
            else:
                ahead +=1
        return []

print(twoSum([2,7,11,15],9))
