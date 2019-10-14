class Solution {
public:
    int res = 0xffff;
    int minSteps(int n) {
        if (n <= 1) {
            return 0;
        }
        GetStepNum(1, 0, 0, n);
        return res;
    }
    bool GetStepNum(int cur, int step, int A, int target) {
        if (A % 2 == 0 && cur % 2 == 0 && target % 2 != 0) {
            return false;
        }
        if (cur + A == target) {
            step++;
            res = min(res, step);
            return true;
        }
        if (cur * 2 == target) {
            step += 2;
            res = min(res, step);
            return true;
        }
        if (2 * cur < target && GetStepNum(cur * 2, step + 2, cur, target)) {
            return true;
        }
        if (A + cur < target && GetStepNum(cur + A, step + 1, A, target)) {
            return true;
        }
        return false;
    }
};