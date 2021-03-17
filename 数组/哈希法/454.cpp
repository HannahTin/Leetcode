/**
四数相加 ii

题目描述：
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> my_map;
        for(int a:A)
            for(int b:B)
                my_map[a+b]++;
        int count =0;
        for(int c:C)
            for(int d:D)
                if(my_map.find(0-c-d)!=my_map.end()){
                    count += my_map[0 - (c + d)];
                }

        return count;

}

int main(){
    vector<int> A = {1,2};
    vector<int> B ={-2,-1};
    vector<int> C = {-1,2};
    vector<int> D = {0,2};
    cout<<fourSumCount(A,B,C,D);

}