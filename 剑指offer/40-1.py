'''
最小的k个数

题目描述：
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
'''
# 如果不能修改原数组，可以采用堆实时保存k个数。我们用一个大根堆实时维护数组的前 k 小值。首先将前 k个数插入大根堆中，
# 随后从第 k+1 个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，再插入当前遍历到的数。最后将大根堆里的数存入数组返回即可。
# 在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。
# 而 Python 语言中的堆为小根堆，因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前 k 小值。
import heapq as hq
def getLeastNumbers(arr: list, k: int) -> list:
        if k ==0 :return []
        hp = [-a for a in arr[:k]]
        heapq.heapify(hp)
        for i in range(k,len(arr)):
            if arr[i] < -hp[0]:
                heapq.heappop(hp)
                heapq.heappush(hp,-arr[i])
        ans = [-x for x in hp]
        return ans
print(getLeastNumbers([0,1,2,1],1))
print(getLeastNumbers([3,2,1],2))
print(getLeastNumbers([4,5,1,6,2,7,3,8],4))
print(getLeastNumbers([0,0,2,3,2,1,1,2,0,4],10))

