/*
不用加减乘除做加法

题目描述：
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
*/
#include <iostream>
#include <vector>
using namespace std;

int add(int a, int b) {
    int sum;
    int carry;
    do{
        sum = a^b;//保存不进位值，下次循环用，
        carry = (unsigned int)(a&b)<<1;//C++中负数不支持左移位，因为结果是不定的
        a = sum;
        b =carry;//保存进位值，下次循环用

    }while(b!=0);//因为不允许用+号，所以求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止        

    return a;



    }

int main() {
    int sum = add(111,899);
    cout<<sum; 

}