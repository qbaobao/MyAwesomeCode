class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MAX && divisor == 1) {
            return INT_MAX;
        }
        if (dividend == INT_MAX && divisor == -1) {
            return INT_MAX * -1;
        }
        long dividendTmp = static_cast<long>(dividend);
        long divisorTmp = static_cast<long>(divisor);
        long res = 0;
        bool flag = ((dividendTmp > 0 && divisorTmp > 0) || (dividendTmp < 0 && divisorTmp < 0)) ? true : false;
        dividendTmp = dividendTmp > 0 ? dividendTmp : (-1 * dividendTmp);
        divisorTmp = divisorTmp > 0 ? divisorTmp : (-1 * divisorTmp);
        while (dividendTmp >= divisorTmp) {
            long t = divisorTmp;
            long p = 1;
            while (dividendTmp >= (t << 1)) {
                p <<= 1;
                t <<= 1;
            }
            dividendTmp -= t;
            res += p;
        }
        res = (res == INT_MAX) ? INT_MAX : (flag ? res : (-1 * res));
        return res;
    }
};