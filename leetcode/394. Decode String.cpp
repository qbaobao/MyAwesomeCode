class Solution {
public:
    string decodeString(string s) {
        if (s.size() == 0) {
            return s;
        }
        string result = "";
        int start = 0;
        int left = 0;
        helper(start, s, result, left);
        return result;
    }
    bool isSrt(char ch) {
        return (ch < '0' || ch >'9') && (ch != '[' && ch != ']');
    }
    void helper(int& start, const string& s, string& result, int& left) {
        if (start >= s.size()) {
            return;
        }
        if (s[start] >= '0' && s[start] <= '9') {
            int num = 0;
            while (start < s.size() && s[start] >= '0' && s[start] <= '9') {
                num = num * 10 + s[start] - '0';
                start++;
            }
            string tmp = "";
            left++;
            for (start = start + 1; start < s.size() && isSrt(s[start]); start++) {
                tmp += s[start];
            }
            while (s[start] != ']' && left) {
                string res = "";
                helper(start, s, res, left);
                tmp += res;
            }
            while (num) {
                result += tmp;
                num--;
            }
            start++;
            left = left ? left - 1 : 0;
            helper(start, s, result, left);
        }
        else if (s[start] >= 'a' && s[start] <= 'z') {
            for (; start < s.size() && isSrt(s[start]); start++) {
                result += s[start];
            }
            helper(start, s, result, left);
        }
        else {
            left--;
        }
        return;
    }
};