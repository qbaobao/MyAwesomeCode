class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A.size() == 1 && B.size() == 1) {
            return A == B ? 0 : 1;
        }
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
                A.erase(A.begin() + i);
                B.erase(B.begin() + i);
                i--;
            }
        }
        set<string> exist;
        queue<string> q;
        int step = 0;
        q.push(A);
        exist.insert(A);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string s = q.front();
                q.pop();
                int k = 0;
                for (; k < s.size(); k++) {
                    if (s[k] != B[k]) {
                        break;
                    }
                }
                if (k == B.size()) {
                    return step;
                }
                for (int m = k; m < s.size(); m++) {
                    if (s[m] == B[k]) {
                        swap(s[m], s[k]);
                        if (!exist.count(s)) {
                            q.push(s);
                            exist.insert(s);
                        }
                        swap(s[m], s[k]);
                    }
                }
            }
            step++;
        }
        return 0;
    }
};