class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if (S.size() == 0 || words.size() == 0) {
            return 0;
        }
        int res = 0;
        for (auto w : words) {
            res += helper(S, w);
        }
        return res;
    }
    int helper(const string& s, const string& w) {
        
        int begin1 = 0;
        int begin2 = 0;
        int end1 = 0;
        int end2 = 0;
        int d1 = 0;
        int d2 = 0;
        while (end1 < s.size() && end2 < w.size()) {
            if (s[end1] != w[end2]) {
                return 0;
            }
            while (end1 < s.size() && s[begin1] == s[end1]) {
                end1++;
            }
            while (end2 < w.size() && w[begin2] == w[end2]) {
                end2++;
            }
            d1 = end1 - begin1;
            d2 = end2 - begin2;
            if (d1 < d2 || (d1 < 3 && d1 > d2)) {
                return 0;
            }
            begin1 = end1;
            begin2 = end2;
        }
        d1 = s.size() - begin1;
        d2 = w.size() - begin2;
        if (d1 < d2 || (d1 < 3 && d1 > d2)) {
                return 0;
        }
        return 1;
    }
};