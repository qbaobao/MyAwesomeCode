class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if ((pattern.size() == 0 && str.size() > 0) ||
            (pattern.size() > 0 && str.size() == 0)) {
            return false;
        }

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        size_t pos1 = 0;
        size_t pos2 = 0;
        string strstr;
        for (int i = 0; i < pattern.size(); i++) {
            pos2 = str.find(' ', pos1);
            pos2 = (pos2 == string::npos ? str.size() : pos2);
            strstr = str.substr(pos1, pos2 - pos1);
            pos1 = (pos2 == string::npos ? str.size() : pos2 + 1);
            if ((m1.count(pattern[i]) && m1[pattern[i]] != strstr) ||
                (m2.count(strstr) && m2[strstr] != pattern[i])) {
                return false;
            }
            if ((pos2 == str.size() && i < pattern.size() - 1) ||
                (pos2 != str.size() && i == pattern.size() - 1)){
                return false;
            }
            m1[pattern[i]] = strstr;
            m2[strstr] = pattern[i];
        }

        return true;
    }
};