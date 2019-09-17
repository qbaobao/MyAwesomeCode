class Solution {
public:
    int uniquePaths(int m, int n) {
        double M = m + n - 2;
        double N = n - 1;
        double result = 1;
        for (int i = M; i > N; i--) {
            result *= (i / (i - N));
        }
        
        return round(result);
    }
};