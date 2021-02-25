/*
二进制中1的个数

题目描述：
请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。
*/

// 首先应该明确传入的n是有符号整数还是无符号整数。有符号的只能按照设置flag对其依次左移来计算。这时循环的次数等于整数二进制的位数。
// 第二种方法时间复杂度是整数二进制中1的个数：把一个整数减去1再和原数做与运算，会把该数最右边的1变成0，那么一个整数的二进制
// 有多少个1就可以进行多少次这样的操作
#include <iostream>
#include <vector>
using namespace std;
int hammingWeight(uint32_t n){
    int count =0;
    while(n){
        ++count;
        n=(n-1)&n;
    }
    return count;

    /*
    unsigned int flag = 1;
    int count =0;
    while(flag){
        if (n&flag)
            count++;
        flag = flag << 1;

    }    
    return count;
    */
}
int main() {
    int count = hammingWeight(9);
    cout<<count; 

}



 

