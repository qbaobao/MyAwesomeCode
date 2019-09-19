/*
87. Scramble String
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
    Example 1:
        Input: s1 = "great", s2 = "rgeat"
        Output: true
    Example 2:
        Input: s1 = "abcde", s2 = "caebd"
        Output: false

    分析：
        什么是scramble？--通过[分割,镜像]操作可以从原始字符串转换成目标字符串的过程
        如何判断两个字符串是否符合scramble？
            将字符串分割成两个子串,如果子串符合scramble,未分割字符串也符合scramble。
              great         rgeat
             /    \        /    \
            gr    eat    rg    eat
            如何判断子串是否符合scramble呢？
            1. 如果子串相等,直接返回true
            2. 如果子串不相等，将子串再分解(如下图),如果分解后的s1左子串Scamble s2右子串,s1的右子串 Scamble s2左子串,则返回true
                  gr     rg                      如果分解后的s1左子串Scamble s2左子串,s1的右子串 Scamble s2右子串,则返回true
                 / \    /  \
                g   r  r   g         

        综上：可以采用DP或者分治递归法实现算法。核心思想如下：
            1. 如果字符串相等,返回true
            2. 分割字符串,满足上述两种Scramble中的其一,则返回true!
*/

class Solution {
public:
    /* this is dynamic programing method!
    bool isScramble(string s1, string s2) {
        if(s1.length() <= 0 || s2.length() <= 0 || s1.length() != s2.length()) {
            return false;
        }
        vector<vector<vector<bool>>> dp(s1.length(), vector<vector<bool>>(s2.length(), vector<bool>(s1.length() + 1, false)));

        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= s1.length(); len++) {
            for (int i = 0; i < s1.length() - len + 1; i++) {
                for (int j = 0; j < s2.length() - len + 1; j++) {
                    for (int k = 1; k < len; k++) {
                        if (dp[i][j][len]) {
                            break;
                        }
                        dp[i][j][len] = ((dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i+k][j][len-k] && dp[i][j+len-k][k]));
                    }
                }
            }
        }

        return dp[0][0][s1.length()];
    }*/

    // 采用分治递归的方法实现
    bool isScramble(string s1, string s2)
    {
        if (s1.length() <= 0 || s2.length() <= 0) return false;
        if (s1 == s2) return true;
        string tmp1 = s1;
        string tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if (tmp1 != tmp2) return false;

        for (int k = 1; k < s1.length(); k++) {
            if ((isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k), s2.substr(k))) ||
                (isScramble(s1.substr(0, k), s2.substr(len - k)) && isScramble(s1.substr(k), s2.substr(0, len - k)))) {
                    return true;
                }
        } 
        return false; 
    }
};