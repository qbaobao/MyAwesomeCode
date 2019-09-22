class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A.size() <= 0) {
            return -1;
        }
        int res = A.size() + 1;
        vector<long long> sum(A.size() + 1, 0);
        deque<int> q;
        for (int i = 1; i <= A.size(); i++) {
            sum[i] = sum[i - 1] + A[i - 1];
        }
        for (int i = 0; i < A.size() + 1; i++) {
            while (!q.empty() && sum[i] - sum[q.front()] >= K) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && sum[i] <= sum[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return (res == A.size() + 1) ? -1 : res;

    }
};