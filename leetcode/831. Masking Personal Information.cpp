class Solution {
public:
    void GetNum(const string& s, string& res) {
        string numStr = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                numStr = numStr + s[i];
            }
        }
        if (numStr.size() == 10) {
            res = "***-***-";
            res = res + numStr.substr(numStr.size() - 4, 4);
            return;
        }
        res = "+";
        for (int i = numStr.size(); i > 10; i--) {
            res = res + '*';
        }
        res = res + "-***-***-";
        res = res + numStr.substr(numStr.size() - 4, 4);
        return;
    }

    void GetStr(const string& s, string& res) {
        size_t pos = s.find("@");
        res = tolower(s[0]);
        res = res + "*****";
        for (size_t i = pos - 1; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z')) {
                char ch = tolower(s[i]);
                res = res + ch;
            }
            else {
                res = res + s[i];
            }
        }
        return;
    }
    string maskPII(string S) {
        string res = "";
        if (S.size() == 0) {
            return res;
        }
        bool isNum = (S.find('@') == string::npos) ? true : false;
        if (isNum) {
            GetNum(S, res);
        }
        else {
            GetStr(S, res);
        }
        return res;
    }
};