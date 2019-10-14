class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int dp[100][100][100] = {0};
        return removeBoxes(boxes, dp, 0, boxes.size() - 1, 0);
    }
private:
    int removeBoxes(vector<int>& boxes, int dp[100][100][100], int i, int j, int k) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }
        int m = i;
        for (; m + 1 <= j && boxes[m] == boxes[m + 1]; m++, k++) ;
        int tmp = (k + 1) * (k + 1) + removeBoxes(boxes, dp, m + 1, j, 0); 
        for (int n = m + 1; n <= j; n++) {
            if (boxes[n] == boxes[i]) {
                tmp = max(tmp, removeBoxes(boxes, dp, m + 1, n - 1, 0) + removeBoxes(boxes, dp, n, j, k + 1));
            }
        }

        dp[m][j][k] = tmp;
        return tmp;
    }
};