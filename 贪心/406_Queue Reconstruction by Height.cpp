/*
406. 根据身高重建队列
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

 

示例 1：

输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
*/
#include<vector>
#include<list>
using namespace std;
// 按照身高排序之后，优先按身高高的people的k来插入，后序插入节点也不会影响前面已经插入的节点，最终按照k的规则完成了队列。

// 所以在按照身高从大到小排序后：

// 「局部最优：优先按身高高的people的k来插入。插入操作过后的people满足队列属性」

// 「全局最优：最后都做完插入操作，整个队列满足题目队列属性」

// 局部最优可推出全局最优，找不出反例，那就试试贪心。

// 回归本题，整个插入过程如下：
// 排序完的people：
// [[7,0], [7,1], [6,1], [5,0], [5,2]，[4,4]]
// 插入的过程：插入[7,0]：[[7,0]]
// 插入[7,1]：[[7,0],[7,1]]
// 插入[6,1]：[[7,0],[6,1],[7,1]]
// 插入[5,0]：[[5,0],[7,0],[6,1],[7,1]]
// 插入[5,2]：[[5,0],[7,0],[5,2],[6,1],[7,1]]
// 插入[4,4]：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
// 此时就按照题目的要求完成了重新排列。
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>&p1,vector<int>&p2){
            if(p1[0]==p2[0]) return p1[1]<p2[1];
            return p1[0]>p2[0];
        });
        vector<vector<int>> que;
        for(int i=0;i<people.size();i++){
            int position = people[i][1];
            que.insert(que.begin()+position,people[i]);
        }
        return que;

    }
};
// 时间复杂度O(nlogn + n^3)
// 空间复杂度O(n)
// 下面改用链表的底层实现：
class Solution2 {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++; 
            }
            que.insert(it, people[i]); 
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
// 时间复杂度O(nlogn + n^2)
// 空间复杂度O(n)
