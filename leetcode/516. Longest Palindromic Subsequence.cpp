class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 0) {
            return 0;
        }

        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 1));
        dp[0][0] = 1;
        for (int i = 1; i < s.size(); i++) {
            dp[i][i] = 1;
            if (s[i] == s[i - 1]) {
                dp[i - 1][i] = 2;
            }
        }
        int len = 0;
        for (int i = 3; i <= s.size(); i++) {
            for (int j = 0; j <= s.size() - i; j++) {
                if (s[j] == s[j + i - 1]) {
                    len = dp[j + 1][j + i - 2] + 2;
                }
                dp[j][j + i - 1] = max(len, dp[j + 1][j + i - 1]);
                dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][j + i - 2]);
                len = 0;
            }
        }

        return dp[0][s.size() - 1];
    }
};