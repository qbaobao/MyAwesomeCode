class Solution {
public:
    vector<string> result;
    string temple[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        string str(digits.size(), ' ');
        GetStr(0, digits, str);
        return result;
    }

    void GetStr(int cur, const string& digits, string& str)
    {
        if (cur >= digits.size()) {
            result.push_back(str);
            return;
        }
        int tmp = digits[cur] - '0';
        for (int i = 0; i < temple[tmp].size(); i++) {
            str[cur] = temple[tmp][i];
            GetStr(cur + 1, digits, str);
        }
        return;
    }
};