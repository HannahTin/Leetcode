'''
扑克牌中的顺子

题目描述：
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
def isStraight(nums: list) -> bool:
        nums.sort()
        count = 0
        for i in range(len(nums)-1):
            if(nums[i] ==0):
                count += 1
            else:
                if nums[i+1] - nums[i] >1:
                    count = count -(nums[i+1] - nums[i]-1)
                elif nums[i+1] - nums[i] <1:
                    return False
        if count<0: return False
        else: return True
print(isStraight([0,0,1,2,5])) #True