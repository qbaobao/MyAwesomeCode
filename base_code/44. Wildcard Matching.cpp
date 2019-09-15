/*
44. Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:
    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like ? or *.

    Example 1:
        Input:
            s = "aa"
            p = "a"
        Output: false
        Explanation: "a" does not match the entire string "aa".
    Example 2:
        Input:
            s = "aa"
            p = "*"
        Output: true
        Explanation: '*' matches any sequence.
    Example 3:
        Input:
            s = "cb"
            p = "?a"
        Output: false
        Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
    Example 4:
        Input:
            s = "adceb"
            p = "*a*b"
        Output: true
        Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
    Example 5:
        Input:
            s = "acdcb"
            p = "a*c?b"
        Output: false

分析：采用动态规划完成
    dp[i][j]表示s[0,i) p[0,j)是否能完成正则匹配, 1--yes, 0--no
    初始化:  dp[sLen+1][pLen+1] = {false}, 
            dp[0][0] = 1; // S和P都为空
            dp[0][j] = dp[0][j-1]; // S为空, P的第一个及以后的字符全是* 例如: s = "", p = "*****"
    遍历:
        遍历长度i从1-sLen的s子串,长度j从1-pLen的P子串:
            a. if s[i-1] == p[i-1] ========>>>>>>>>>>     dp[i][j] = dp[i-1][j-1]; 
            b. if p[i-1] == '?'    ========>>>>>>>>>>     dp[i][j] = dp[i-1][j-1]; // '?'可以匹配任何字符
            c. if p[i-1] == '*'
                c.1                ========>>>>>>>>>>     dp[i][j] = dp[i][j-2];   // '*'不带表任何字符串,等价于去掉j-2-->j-1位置的字符
                c.2                ========>>>>>>>>>>     dp[i][j] = dp[i][j-1];   // '*'代表s[i-1]字符,等价于去掉j-1位置的字符
                c.3                ========>>>>>>>>>>     dp[i][j] = dp[i-1][j];   // '*'代表(*s[i-1]),等价于在j-1后增加i-1位置的字符
                                                                                   // 例如: s="abcd" p="ab*", 此时等价于p="ab(*c)";问题为比较[s="ab",p="ab*"]是否匹配
    返回:    dp[sLen][pLen]

*/
class Solution {
public:
    bool isMatch(string s, string p) {

        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        
        for(int j = 1; j <= p.size(); j++) {
            if ( p[j - 1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};