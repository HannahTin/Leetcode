/*
678. 有效的括号字符串
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
示例 1:

输入: "()"
输出: True
示例 2:

输入: "(*)"
输出: True
*/
using namespace std;
#include <stack>
#include <string>
// 如果字符串中没有星号，则只需要一个栈存储左括号，在从左到右遍历字符串的过程中检查括号是否匹配。
// 在有星号的情况下，需要两个栈分别存储左括号和星号。从左到右遍历字符串，进行如下操作。
// 如果遇到左括号，则将当前下标存入左括号栈。
// 如果遇到星号，则将当前下标存入星号栈。
// 如果遇到右括号，则需要有一个左括号或星号和右括号匹配，由于星号也可以看成右括号或者空字符串，因此当前的右括号应优先和左括号匹配，没有左括号时和星号匹配：
// 如果左括号栈不为空，则从左括号栈弹出栈顶元素；
// 如果左括号栈为空且星号栈不为空，则从星号栈弹出栈顶元素；
// 如果左括号栈和星号栈都为空，则没有字符可以和当前的右括号匹配，返回 false。
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftStack;
        stack<int> asteriskStack;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                leftStack.push(i);
            } else if (c == '*') {
                asteriskStack.push(i);
            } else {
                if (!leftStack.empty()) {
                    leftStack.pop();
                } else if (!asteriskStack.empty()) {
                    asteriskStack.pop();
                } else {
                    return false;
                }
            }
        }

        while (!leftStack.empty() && !asteriskStack.empty()) {
            int leftIndex = leftStack.top();
            leftStack.pop();
            int asteriskIndex = asteriskStack.top();
            asteriskStack.pop();
            if (leftIndex > asteriskIndex) {
                return false;
            }
        }
        
        return leftStack.empty();
    }
};


class Solution {
public:
// 贪心
// 使用贪心的思想，可以将空间复杂度降到 O(1)。

// 从左到右遍历字符串，遍历过程中，未匹配的左括号数量可能会出现如下变化：

// 如果遇到左括号，则未匹配的左括号数量加 1；
// 如果遇到右括号，则需要有一个左括号和右括号匹配，因此未匹配的左括号数量减 1；
// 如果遇到星号，由于星号可以看成左括号、右括号或空字符串，因此未匹配的左括号数量可能加 1、减1 或不变。
// 任何情况下，未匹配的左括号数量必须非负，因此当最大值变成负数时，说明没有左括号可以和右括号匹配，返回 false。

// 当最小值为 0 时，不应将最小值继续减少，以确保最小值非负。

// 遍历结束时，所有的左括号都应和右括号匹配，因此只有当最小值为 0 时，字符串 s 才是有效的括号字符串。
    bool checkValidString(string s) {
        int minCount = 0, maxCount = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                minCount++;
                maxCount++;
            } else if (c == ')') {
                minCount = max(minCount - 1, 0);
                maxCount--;
                if (maxCount < 0) {
                    return false;
                }
            } else {
                minCount = max(minCount - 1, 0);
                maxCount++;
            }
        }
        return minCount == 0;
    }
};