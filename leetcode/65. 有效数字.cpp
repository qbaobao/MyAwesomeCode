class Solution {
public:
    bool isNumber(string s) {
        if (s == "") {
            return false;
        }
        int index = s.size() - 1;
        for (; index && s[index] == ' '; index--) {
        }
        s = s.substr(0, index + 1);
        for (index = 0; index < s.size() && s[index] == ' '; index++) {
        }
        s = s.substr(index, s.size() - index + 1);
        if (s.size() == 0) {
            return false;
        }
        index = 0;
        bool result = isInt(index, s);
        if (s[index] == '.') {
            result |= isUnsignedInt(++index, s);
        }
        if (s[index] == 'e' || s[index] == 'E') {
            result &= isInt(++index, s);
        }
        return result && (index == s.size());
    }
    bool isInt(int& index, const string& s) {
        if (s[index] == '-' || s[index] == '+') {
            index++;
        }
        return isUnsignedInt(index, s);
    }
    bool isUnsignedInt(int& index, const string& s) {
        bool flag = false;
        while (index < s.size() && s[index] <= '9' && s[index] >= '0') {
            index++;
            flag = true;
        }
        return flag;
    }
};