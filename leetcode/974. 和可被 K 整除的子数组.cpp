class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> map;
        int sum = 0;
        for (auto a : A) {
            sum += a;
            int res = (sum % K + K) % K;
            map[res]++;
        }
        int res = 0;
        for (auto [x, cx]: map) {
            res += (cx) * (cx - 1) / 2;
        }
        return res;
    }
};