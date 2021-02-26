/*
数值的整数次方

题目描述：
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 总结：求 x^n最简单的方法是通过循环将n个x乘起来，时间复杂度为O(n)
// 这里考虑快速幂的方法,时间复杂度为O(logn)，其中用右移1表示/2，用位与判断奇偶数
// 本题还要尤其注意特殊值的处理。0的负指数幂，0的0次幂

#include <iostream>
using namespace std;
double myPow(double x, int n) {
    if(x==0) return 0;
    double res=1.0;
    long b=n; //防止n太大太小而溢出
    if(b<0){
        x=1.0/x;
        b=-b;
    }
    for(;b>0;x*=x,b>>=1){
        if((b&1)==1){
            res *= x;
        }
    }      
    return res;
}

int main() {
    double res;
    res = myPow(3,-1);
    cout << res;
    return 0;
}