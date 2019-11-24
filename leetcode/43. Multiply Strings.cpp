class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int size1 = num1.size();
        int size2 = num2.size();
        int k = size1 + size2;
        vector<int> resInt(k, 0);
        int inc = 0;
        string result = "";
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                resInt[k - 1 - i - j] += (num1[size1 - 1 - i] - '0') * (num2[size2 - 1 - j] - '0');
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            resInt[i] += inc;
            inc = resInt[i] / 10;
            resInt[i] = resInt[i] % 10;
        }
        int i = 0;
        while (resInt[i] == 0) {
            i++;
        }
        for (; i < k; i++) {
            result += (resInt[i] + '0');
        }
        return result;
    }
};