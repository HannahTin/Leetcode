/*
*
下一个更大元素 III

题目描述：
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。

注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
*
*/
// 使用单调栈，从后向前找到第一对满足num[i-1] < num[i]的数，再从i处向右找到恰好大于num[i-1]的那个数num[j]，交换二者的位置，再从小到大排列i+1到最末位的数组。

int nextGreaterElement(int n) {
        long long res=0;
        stack<char> char_stack;
        string str=to_string(n);
        for(int i=str.length()-1;i>=0;i--)
        {
            if(char_stack.empty()||str[i]>=char_stack.top())
                char_stack.push(str[i]);
            else
            {
                int j=0;
                while(!char_stack.empty()&&str[i]<char_stack.top())
                {
                    char_stack.pop();
                    j++;
                }
                swap(str[i],str[i+j]);
                sort(str.begin()+i+1,str.end());
                res=stoll(str);
                if(res>INT_MAX)
                    return -1;
                else
                    return res;
            }
        }
        return -1;

}