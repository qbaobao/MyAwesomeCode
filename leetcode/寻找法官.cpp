class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.size() == 0 || trust[0].size() == 0) {
            return N == 1 ? 1 : -1;
        }
        vector<int> in(N + 1, 0);
        vector<int> out(N + 1, 0);

        for (auto t : trust) {
            in[t[1]]++;
            out[t[0]]++;
        }
        vector<int> res;
        for (int i = 0; i <= N; i++) {
            if (in[i] == N - 1 && out[i] == 0) {
                res.push_back(i);
            }
        }
        return res.size() == 1 ? res[0] : -1;
    }
};