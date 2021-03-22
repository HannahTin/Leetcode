/*
*
包含min函数的栈

题目描述：
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
**/
#include <stack>
#include <iostream>
using namespace std;
class MinStack {
private:
    stack<int> data_stack;
    stack<int> assist_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        data_stack.push(x);
        if(assist_stack.empty() || x <= assist_stack.top())
            assist_stack.push(x);
        else
            assist_stack.push(assist_stack.top());

    }

    void pop() {
        data_stack.pop();
        assist_stack.pop();

    }

    int top() {
        return data_stack.top();

    }

    int min() {
        return assist_stack.top();

    }
};

int main(){
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    int param_1 = minStack->min();  // --> 返回 -3.
    minStack->pop();
    minStack->top();    //  --> 返回 0.
    int param_2 = minStack->min();   //--> 返回 -2.
    cout<<param_1<<endl;
    cout<<param_2<<endl;

}

