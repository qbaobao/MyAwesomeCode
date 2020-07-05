int minimumMoves(int* arr, int arrSize){
    if (arrSize == 1) {
        return 1;
    }
    int dp[101][101];
    memset(dp, 101, sizeof(dp));
    for (int i = 0; i < arrSize; i++) {
        dp[i][i] = 1;
        if (i < arrSize - 1) {
            dp[i][i + 1] = (arr[i] == arr[i + 1]) ? 1 : 2;
        }
    }
    for (int len = 3; len <= arrSize; len++) {
        for (int i = 0; i <= arrSize - len; i++) {
            if (arr[i] == arr[i + len - 1] && dp[i][i + len - 1] > dp[i + 1][i + len - 2]) {
                dp[i][i + len - 1] = dp[i + 1][i + len - 2];
            }
            for (int k = i; k <= i + len - 1; k++) {
                if (dp[i][i + len - 1] > dp[i][k] + dp[k + 1][i + len - 1]) {
                    dp[i][i + len - 1] = dp[i][k] + dp[k + 1][i + len - 1];
                }
            }
        }
    }
    return dp[0][arrSize - 1];
}