/*
738. 单调递增的数字


当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
示例 1:

输入: n = 10
输出: 9
示例 2:

输入: n = 1234
输出: 1234
示例 3:

输入: n = 332
输出: 299
*/
#include<string>
using namespace std;
// 暴力求解
// 时间复杂度：O(n * m) m为n的数字长度
// 空间复杂度：O(1)
class Solution {
private:
    bool checkNum(int num) {
        int max = 10;
        while (num) {
            int t = num % 10;
            if (max >= t) max = t;
            else return false;
            num = num / 10;
        }
        return true;
    }
public:
    int monotoneIncreasingDigits(int N) {
        for (int i = N; i > 0; i--) {
            if (checkNum(i)) return i;
        }
        return 0;
    }
};
// 贪心
// 时间复杂度：O(n) n 为数字长度
// 空间复杂度：O(n) 需要一个字符串，转化为字符串操作更方便
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};