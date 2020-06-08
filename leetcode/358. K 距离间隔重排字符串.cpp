class Solution {
public:
    string rearrangeString(string s, int k) {
        int alphaCnt[26] = { 0 };
        for (auto c : s) {
            alphaCnt[c - 'a']++;
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < 26; i++) {
            if (alphaCnt[i] == 0) {
                continue;
            }
            pair<int, int> tmp(alphaCnt[i], i);
            q.push(tmp);
        }
        int start = 0;
        int end = -1;
        string res;
        while (!q.empty()) {
            pair<int, int> tmp = q.top();
            q.pop();
            alphaCnt[tmp.second]--;
            res += tmp.second + 'a';
            end++;
            if (end - start + 1 >= k) {
                if (alphaCnt[res[start] - 'a'] > 0) {
                    q.push(pair<int, int>(alphaCnt[res[start] - 'a'], res[start] - 'a'));
                }
                start++;
            }

        }
        return res.size() == s.size() ? res : "";
    }
};