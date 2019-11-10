class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> exist;
        while (!exist.count(n)) {
            exist[n] = true;
            int result = 0;
            while (n) {
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            n = result;
        }
        return n == 1;
    }
};