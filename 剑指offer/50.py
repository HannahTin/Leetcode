'''
第一个只出现一次的字符

题目描述：
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
'''
#  python中哈希表是dic字典，c++是unordered_map。
def firstUniqChar(s: str) -> str:
    dic ={}
    for c in s:
        dic[c] = not c in dic # 判断字典中有无键c
    print(dic)
    for c in s:
        if(dic[c]): return c
    return ' '

print(firstUniqChar("cabbfs"))

