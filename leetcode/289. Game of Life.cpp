class Solution {
public:
    void updateCurLine(vector<int>& pre, vector<int>& cur, vector<int>& next) {
        vector<int> result = cur;
        pre.insert(pre.begin(), 0);
        pre.push_back(0);
        next.insert(next.begin(), 0);
        next.push_back(0);
        cur.insert(cur.begin(), 0);
        cur.push_back(0);
        for (int i = 1; i < cur.size() - 1; i++) {
            int liveCnt = pre[i] + pre[i - 1] + pre[i + 1] +
                cur[i - 1] + cur[i + 1] +
                next[i] + next[i - 1] + next[i + 1];
            if ((liveCnt < 2 && cur[i]) ||
                (liveCnt > 3 && cur[i])) {
                result[i - 1] = 0;
            }
            if ((liveCnt == 2 && cur[i]) ||
                (liveCnt == 3 && cur[i]) ||
                (liveCnt == 3 && !cur[i])) {
                result[i - 1] = 1;
            }
        }
        cur = result;
        next.erase(next.begin());
        next.erase(next.end() - 1);
        return;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        vector<int> pre(board[0].size(), 0);
        vector<int> tmp(board[0].size(), 0);
        for (int i = 0; i < board.size() - 1; i++) {
            tmp = board[i];
            updateCurLine(pre, board[i], board[i + 1]);
            pre = tmp;
        }
        tmp = vector<int>(board[0].size(), 0);
        updateCurLine(pre, board[board.size() - 1], tmp);
        return;
    }
};