/*
10. Regular Expression Matching
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
    Note:
    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
    Input:
        s = "aa"
        p = "a"
    Output: false
        Explanation: "a" does not match the entire string "aa".
Example 2:
    Input:
        s = "aa"
        p = "a*"
    Output: true
        Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:
    Input:
        s = "ab"
        p = ".*"
    Output: true
        Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:
    Input:
        s = "aab"
        p = "c*a*b"
    Output: true
        Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:
    Input:
        s = "mississippi"
        p = "mis*is*p*."
    Output: false

    分析：采用动态规划完成
    dp[i][j]表示s[0,i) p[0,j)是否能完成正则匹配, 1--yes, 0--no
    初始化:  dp[sLen+1][pLen+1] = {false}, 
            dp[0][0] = 1; // S和P都为空
            dp[0][j] = 1; // S为空, P的第二个及以后的字符全是* 例如: s = "", p = "a*****"
    遍历:
        遍历长度i从1-sLen的s子串,长度j从1-pLen的P子串:
            a. if s[i-1] == p[i-1] ========>>>>>>>>>>     dp[i][j] = dp[i-1][j-1]; 
            b. if p[i-1] == '.'    ========>>>>>>>>>>     dp[i][j] = dp[i-1][j-1]; // '.'可以匹配任何字符
            c. if p[i-1] == '*'
                c.1                ========>>>>>>>>>>     dp[i][j] = dp[i][j-2];   // '*'重复前一个字符0次,等价于去掉j-2-->j-1位置的字符
                c.2                ========>>>>>>>>>>     dp[i][j] = dp[i][j-1];   // '*'重复前一个字符1次,等价于去掉j-1位置的字符
                c.3                ========>>>>>>>>>>     dp[i][j] = dp[i-1][j];   // '*'重复前一个字符2+次,等价于在j-1后增加j-2位置的字符
                                                                                   // 例如: s="aaa" p="a*", 此时等价于p="a*a";问题为比较[s="aa",p="a*"]是否匹配
    返回:    dp[sLen][pLen]
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));

        dp[0][0] = true;
        /* 
            当S为空,P的第二个及以后的字符必须是*
        */
        for (int j = 1; j <= pLen; j++) {
            dp[0][j] = (j > 1) && (p[j-1] == '*') && (dp[0][j-2]);
        }

        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= pLen; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j - 1] == '*') {
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[sLen][pLen];
    }
};