class Solution {
public:
    string removeDuplicateLetters(string s) {
        int exitCnt[26] = {0};
        bool exit[26] = {false};
        string res = "";
        int idx = 0;
        for (auto c : s) {
            idx = c - 'a' + 0;
            exitCnt[idx]++;
        }

        for (auto c : s) {
            idx = c - 'a' + 0;
            exitCnt[idx]--;
            if (exit[idx]) {
                continue;
            }
            while (!res.empty() && res.back() > c && exitCnt[res.back() - 'a']) {
                exit[res.back() - 'a'] = false;
                res.pop_back();
            }
            exit[idx] = true;
            res += c;
        }
        return res;
    }
};