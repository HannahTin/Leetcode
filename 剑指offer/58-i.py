'''
剑指 Offer 58 - I. 翻转单词顺序
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
'''
class Solution:
    def reverseWords(self, s: str) -> str:
        '''
        # 使用现成的内置函数
        s = s.strip().split()
        s.reverse()
        return ' '.join(s)
        '''
        s=s.strip()
        i = j = len(s)-1
        res= []
        while(i>=0):
            while(i>= 0 and s[i]!= ' '): 
                i-=1
            res.append(s[i+1:j+1])
            while s[i] == ' ':
                i -= 1
            j=i
        return ' '.join(res)