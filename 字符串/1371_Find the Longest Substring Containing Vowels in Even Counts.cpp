/**
每个元音包含偶数次的最长子字符串

题目描述：
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/
// 思路：本题的思路就是前缀和+状态压缩。没思路，所以看的官方题解。官方题解已经很巧妙了，整理于此。
// 前缀和pre[i][k]表示在字符串前i个字符中第k个元音字母出现的次数。因此问题就是统计对于某个子串，每个元音字母出现的次数都是偶数的情况。
// 然而枚举所有的子串的时间复杂度仍为O(n^2)。为避免枚举所有的子串，考虑枚举字符串的每个位置i，计算以它结尾的满足条件的最长字符串长度。
// 这个条件就是每个每一个元音字母出现的次数都是偶数次，也就是说两个前缀和pre[i][k]和pre[j][k]的奇偶性一定是相同的。
// 状态压缩就是将5个元音字母出现次数的奇偶性视为一种状态，一共有32种状态，不妨使用一个整数代表状态：第一位为1表示a出现奇数次，第1位为1表示e出现奇数次。。。
// 以此类推，仅有状态0符合题意。如果子串[0,i]和[0,j]的状态相同，那么子串[i,j]的状态一定是0，因此可以记录每个状态第一次出现的位置，此后再出现该状态时相减即可。
using namespace std;
#include <iostream>
#include <string>
#include <vector>
int findTheLongestSubstring(string s) {
    int ans =0,status =0,n =s.size();
    vector<int> pos(1<<5,-1);
    pos[0] = 0;
    for(int i=0;i<n;i++){
        if (s[i] == 'a') {
                status ^= 1<<0;
        } else if (s[i] == 'e') {
                status ^= 1<<1;
        } else if (s[i] == 'i') {
                status ^= 1<<2;
        } else if (s[i] == 'o') {
                status ^= 1<<3;
        } else if (s[i] == 'u') {
                status ^= 1<<4;
        }
        if(pos[status] != -1){
            ans = max(ans,i+1-pos[status]);
        }
        else{
            pos[status] = i+1;
        }  

    }
    return ans;


    }

int main(){
        cout<<findTheLongestSubstring("leetcodeisgreat")<<endl; // leetc 5
         cout<<findTheLongestSubstring("eleetminicoworoep")<<endl; // leetminic 13

}