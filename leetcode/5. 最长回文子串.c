char * longestPalindrome(char * s){
    int len = strlen(s);
    int dp[len + 1];
    memset(dp, 1, sizeof(dp));
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) {
            dp[i] = 2;
        }
    }
    int res = 1;
    int start = 0;
    for (int i = 2; i < len; i++) {
        dp[i] = (dp[i - 1] >= 2) ? (s[i] == s[i - 1 - dp[i - 1]] ? dp[i - 1] + 2) : dp[i];
        start = res > dp[i] ? start : i - dp[i];
        res = res > dp[i] ? res : dp[i];
    }
}