/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.
    Example 1:
        Input: "babad"
        Output: "bab"
        Note: "aba" is also a valid answer.
    Example 2:
        Input: "cbbd"
        Output: "bb"

分析：采用动态规划算法
    1. 设dp[i][j]=1表示从i-->j字符串为回文,dp[i][j]=0为非回文
    2. 动态转移方程
        dp[i][j] = (str[i]==str[j] && dp[i+1][j-1]=1(表示i-->j中间字符串也是回文))
        dp[i][j] = 0
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.lenght() <= 1) {
            return s;
        }
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int maxLen = 1;
        int start = 0;
        int tmp = 0;
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            if ((i <s.length() - 1 ) && (s[i] == s[i+1])) {
                dp[i][i+1] = 1;
                start = i;
                maxLen = 2;
            }
        }

        for((int i = 3; i < s.size(); i++) {
            for(int j = 0; j + i - 1 < s.size(); j++) {
                if (s[j] == [j + i - 1] && dp[j+1][(j + i - 1) - 1] == 1) {
                    dp[j][j+i-1] = 1;
                    maxLen = i;
                    start = j;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};