class Solution {
public:
    int GetNum(string str, int start)
    {
        int tmp = start;
        int flag = 1;
        if (str[start] == '-') {
            flag = -1;
            tmp++;
        }
        else if (str[start] == '+') {
            flag = +1;
            tmp++;
        }
        long long num = 0;
        for (; tmp < str.size(); tmp++) {
            if (!(str[tmp] >= '0' && str[tmp] <= '9')) {
                break;
            }
            else if (num * flag >= INT_MAX || num * flag <= INT_MIN) {
                break;
            }
            num = num * 10 + (str[tmp] - '0');
        }
        if (num * flag >= INT_MAX || num * flag <= INT_MIN) {
            return (flag == -1) ? INT_MIN : INT_MAX;
        }
        else {
            return num * flag;
        }
    }

    int myAtoi(string str) {
        int res = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                continue;
            }
            else if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
                res = GetNum(str, i);
                break;
            }
            else {
                break;
            }
        }
        return res;
    }
};