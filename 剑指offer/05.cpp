/**
替换空格

题目描述：
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
**/
/**
Python实现的话可以简单的s.replace(' ',"%20")就可以ac，耗时24ms，内存消耗13.1M。
在 Python 和 Java 等语言中，字符串都被设计成「不可变」的类型，即无法直接修改字符串的某一位字符，需要新建一个字符串实现。
C++实现可以达到0ms和6.2M,因此本题存档的是C++写法。
另外，Python中字符串是不可变数据类型，C++中是可变的，因此可以原地修改字符串
**/
#include <iostream>
#include <string>
using namespace std;
string replaceSpace(string s) {
    int count = 0, len=s.size(); // 空格个数
    for (char c:s){
        if(c==' ') count ++;
    }
    s.resize(len+2*count);
    for(int j=s.size()-1,i=len-1;i<j;i--,j--){
        if(s[i]!=' ') {
            s[j]=s[i];
        }
        else{
            s[j-2]='%';
            s[j-1]='2';
            s[j]='0';
            j-=2;
        }
    }
    return s;
}
int main() {
    cout<<replaceSpace("We are happy.");
    return 0;
}
