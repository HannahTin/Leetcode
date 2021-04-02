/**
n个骰子的点数

把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
#include <vector>
#include <algorithm>

using namespace std;
// 递归实现 一共n个骰子，点数之和sum取值【n,6n】，一共有6^n种取法，第一个骰子选1，剩下的n-1个骰子点数之和应该是sum-1
int getCount(int n,int currSum){
        if(n ==0 and currSum ==0) return 1;
        if(n <0 or currSum<0) return 0;
        int sum =0;
        for (int j =1;j<=6;j++){
            sum += getCount(n-1,currSum-j);
        }
        return sum;

    }
vector<double> dicesProbability(int n) {
    vector<double> res(5*n+1);
    int currSum =n;
    for(int i =0;i<res.size();i++){
        res[i] = getCount(n,currSum)/pow(6,n);
        currSum++;
    }
    return res;

}